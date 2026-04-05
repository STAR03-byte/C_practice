// MFC_CircleDrawView.cpp
#include "pch.h"
#include "framework.h"
#ifndef SHARED_HANDLERS
#include "MFC_CircleDraw.h"
#endif

#include "MFC_CircleDrawDoc.h"
#include "MFC_CircleDrawView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCCircleDrawView

IMPLEMENT_DYNCREATE(CMFCCircleDrawView, CView)

BEGIN_MESSAGE_MAP(CMFCCircleDrawView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCCircleDrawView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	// 绘制圆的菜单命令
	ON_COMMAND(ID_DRAW_CIRCLE, &CMFCCircleDrawView::OnDrawCircle)
	// 鼠标和键盘事件
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CMFCCircleDrawView 构造/析构
CMFCCircleDrawView::CMFCCircleDrawView() noexcept
	: m_nCenterX(0)
	, m_nCenterY(0)
	, m_nRadius(0)
	, m_bShouldDraw(false)
	, m_bDrawing(false)
{
}

CMFCCircleDrawView::~CMFCCircleDrawView()
{
}

BOOL CMFCCircleDrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

// 中点画圆算法实现
void CMFCCircleDrawView::MidpointCircle(CDC* pDC, int xc, int yc, int r) {
	if (r <= 0) return;

	int x = 0, y = r;
	// 判别式初始值（优化后，适配整数运算）
	int d = 1 - r;

	Draw8Points(pDC, xc, yc, x, y); // 绘制初始点

	while (x < y) {
		if (d < 0) {
			d += 2 * x + 3;
		}
		else {
			d += 2 * (x - y) + 5;
			y--;
		}
		x++;
		Draw8Points(pDC, xc, yc, x, y);
	}
}

// 绘制对称点的辅助函数
void CMFCCircleDrawView::Draw8Points(CDC* pDC, int xc, int yc, int x, int y) {
	pDC->SetPixel(xc + x, yc + y, RGB(255, 0, 0));
	pDC->SetPixel(xc - x, yc + y, RGB(255, 0, 0));
	pDC->SetPixel(xc + x, yc - y, RGB(255, 0, 0));
	pDC->SetPixel(xc - x, yc - y, RGB(255, 0, 0));
	pDC->SetPixel(xc + y, yc + x, RGB(255, 0, 0));
	pDC->SetPixel(xc - y, yc + x, RGB(255, 0, 0));
	pDC->SetPixel(xc + y, yc - x, RGB(255, 0, 0));
	pDC->SetPixel(xc - y, yc - x, RGB(255, 0, 0));
}

// CMFCCircleDrawView 绘图
void CMFCCircleDrawView::OnDraw(CDC* pDC)
{
	CMFCCircleDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// 绘制已确认的圆
	if (m_bShouldDraw && m_nRadius > 0) {
		MidpointCircle(pDC, m_nCenterX, m_nCenterY, m_nRadius);
	}

	// 绘制正在创建的圆（动态预览）
	if (m_bDrawing) {
		// 计算半径（两点间距离）
		int radius = (int)sqrt(pow(m_ptEnd.x - m_ptStart.x, 2) + pow(m_ptEnd.y - m_ptStart.y, 2));

		// 使用异或模式绘制临时圆（可擦除）
		pDC->SetROP2(R2_XORPEN);
		CPen pen(PS_SOLID, 1, RGB(0, 0, 255));
		CPen* pOldPen = pDC->SelectObject(&pen);

		// 使用GDI的Ellipse函数绘制预览圆
		pDC->Ellipse(m_ptStart.x - radius, m_ptStart.y - radius,
			m_ptStart.x + radius, m_ptStart.y + radius);

		pDC->SelectObject(pOldPen);
	}
}

// 处理绘制圆的菜单命令
void CMFCCircleDrawView::OnDrawCircle()
{
	// 进入绘制圆模式
	m_bDrawing = true;
	m_bShouldDraw = false;
	SetCapture(); // 捕获鼠标事件
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_CROSS)); // 设置十字光标
}

// 鼠标左键按下事件
void CMFCCircleDrawView::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (m_bDrawing) {
		m_ptStart = point;
		m_ptEnd = point;
	}

	CView::OnLButtonDown(nFlags, point);
}

// 鼠标移动事件
void CMFCCircleDrawView::OnMouseMove(UINT nFlags, CPoint point)
{
	if (m_bDrawing && (nFlags & MK_LBUTTON)) {
		// 重绘以擦除旧的预览圆
		Invalidate(FALSE);

		// 更新结束点
		m_ptEnd = point;

		// 重绘以显示新的预览圆
		Invalidate(FALSE);
	}

	CView::OnMouseMove(nFlags, point);
}

// 鼠标左键释放事件
void CMFCCircleDrawView::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (m_bDrawing) {
		m_ptEnd = point;

		// 计算半径
		m_nCenterX = m_ptStart.x;
		m_nCenterY = m_ptStart.y;
		m_nRadius = (int)sqrt(pow(m_ptEnd.x - m_ptStart.x, 2) + pow(m_ptEnd.y - m_ptStart.y, 2));

		// 确认绘制圆
		m_bShouldDraw = true;
		m_bDrawing = false;
		ReleaseCapture(); // 释放鼠标捕获
		SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW)); // 恢复默认光标

		// 重绘视图
		Invalidate();
	}

	CView::OnLButtonUp(nFlags, point);
}

// 键盘按下事件
void CMFCCircleDrawView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// ESC键取消绘制
	if (nChar == VK_ESCAPE && m_bDrawing) {
		m_bDrawing = false;
		ReleaseCapture();
		SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
		Invalidate();
	}

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

// CMFCCircleDrawView 打印
void CMFCCircleDrawView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCCircleDrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	return DoPreparePrinting(pInfo);
}

void CMFCCircleDrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

void CMFCCircleDrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

void CMFCCircleDrawView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCCircleDrawView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}

// CMFCCircleDrawView 诊断
#ifdef _DEBUG
void CMFCCircleDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCCircleDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCCircleDrawDoc* CMFCCircleDrawView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCCircleDrawDoc)));
	return (CMFCCircleDrawDoc*)m_pDocument;
}
#endif //_DEBUG