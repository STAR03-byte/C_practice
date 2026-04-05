// t1View.cpp: Ct1View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "t1.h"
#endif

#include "t1Doc.h"
#include "t1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ct1View

IMPLEMENT_DYNCREATE(Ct1View, CView)

BEGIN_MESSAGE_MAP(Ct1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Ct1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()

	// 添加鼠标事件处理
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// Ct1View 构造/析构

Ct1View::Ct1View() noexcept
{
	// 初始化圆的参数
	m_nCenterX = 0;
	m_nCenterY = 0;
	m_nRadius = 0;
	m_bDrawing = false;
}

Ct1View::~Ct1View()
{
}

BOOL Ct1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ct1View 绘图

void Ct1View::OnDraw(CDC* pDC)
{
	Ct1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// 获取客户区大小
	CRect rect;
	GetClientRect(&rect);

	// 绘制坐标轴
	pDC->SetTextColor(RGB(0, 0, 255));
	pDC->MoveTo(0, rect.Height() / 2);
	pDC->LineTo(rect.Width(), rect.Height() / 2);
	pDC->MoveTo(rect.Width() / 2, 0);
	pDC->LineTo(rect.Width() / 2, rect.Height());

	// 显示坐标原点
	pDC->TextOut(rect.Width() / 2 + 5, rect.Height() / 2 + 5, _T("O"));

	// 绘制圆
	if (m_nRadius > 0)
	{
		// 转换坐标系，将原点移至客户区中心
		int centerX = rect.Width() / 2 + m_nCenterX;
		int centerY = rect.Height() / 2 - m_nCenterY;

		// 使用中点圆算法绘制圆
		MidPointCircle(pDC, centerX, centerY, m_nRadius);

		// 显示圆心和半径信息
		CString strInfo;
		strInfo.Format(_T("圆心: (%d, %d), 半径: %d"), m_nCenterX, m_nCenterY, m_nRadius);
		pDC->TextOut(10, 10, strInfo);
	}

	// 如果正在绘制，显示临时圆
	if (m_bDrawing)
	{
		CPen pen(PS_DASH, 1, RGB(255, 0, 0));
		CPen* pOldPen = pDC->SelectObject(&pen);
		pDC->Ellipse(m_ptStart.x, m_ptStart.y, m_ptEnd.x, m_ptEnd.y);
		pDC->SelectObject(pOldPen);
	}
}


// Ct1View 打印


void Ct1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Ct1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Ct1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Ct1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void Ct1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Ct1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}

// 鼠标按下事件处理
void Ct1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// 记录起始点
	m_ptStart = point;
	m_bDrawing = true;

	// 计算圆心相对于客户区中心的坐标
	CRect rect;
	GetClientRect(&rect);
	m_nCenterX = point.x - rect.Width() / 2;
	m_nCenterY = rect.Height() / 2 - point.y;

	CView::OnLButtonDown(nFlags, point);
}

// 鼠标释放事件处理
void Ct1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (m_bDrawing)
	{
		m_ptEnd = point;
		m_bDrawing = false;

		// 计算半径
		int dx = point.x - m_ptStart.x;
		int dy = point.y - m_ptStart.y;
		m_nRadius = (int)sqrt(dx * dx + dy * dy);

		// 刷新视图
		Invalidate();
	}

	CView::OnLButtonUp(nFlags, point);
}

// 鼠标移动事件处理
void Ct1View::OnMouseMove(UINT nFlags, CPoint point)
{
	if (m_bDrawing)
	{
		m_ptEnd = point;
		// 实时刷新视图，显示临时圆
		Invalidate();
	}

	CView::OnMouseMove(nFlags, point);
}

// 中点圆算法实现
void Ct1View::MidPointCircle(CDC* pDC, int xc, int yc, int r)
{
	int x = 0;
	int y = r;
	int d = 1 - r; // 初始决策参数
	int deltaE = 3; // E方向的增量
	int deltaSE = -2 * r + 5; // SE方向的增量

	// 绘制第一个点
	DrawCirclePoints(pDC, xc, yc, x, y);

	// 循环直到x >= y
	while (x < y)
	{
		if (d < 0)
		{
			// 选择E点
			d += deltaE;
			deltaE += 2;
			deltaSE += 2;
		}
		else
		{
			// 选择SE点
			d += deltaSE;
			deltaE += 2;
			deltaSE += 4;
			y--;
		}
		x++;
		DrawCirclePoints(pDC, xc, yc, x, y);
	}
}

// 绘制圆的八个对称点
void Ct1View::DrawCirclePoints(CDC* pDC, int xc, int yc, int x, int y)
{
	// 设置绘图颜色
	COLORREF clr = RGB(255, 0, 0);

	// 绘制八个对称点
	pDC->SetPixel(xc + x, yc + y, clr);
	pDC->SetPixel(xc - x, yc + y, clr);
	pDC->SetPixel(xc + x, yc - y, clr);
	pDC->SetPixel(xc - x, yc - y, clr);
	pDC->SetPixel(xc + y, yc + x, clr);
	pDC->SetPixel(xc - y, yc + x, clr);
	pDC->SetPixel(xc + y, yc - x, clr);
	pDC->SetPixel(xc - y, yc - x, clr);
}


// Ct1View 诊断

#ifdef _DEBUG
void Ct1View::AssertValid() const
{
	CView::AssertValid();
}

void Ct1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ct1Doc* Ct1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ct1Doc)));
	return (Ct1Doc*)m_pDocument;
}
#endif //_DEBUG


// Ct1View 消息处理程序
