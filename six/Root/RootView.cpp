
// RootView.cpp: CRootView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Root.h"
#endif

#include "RootDoc.h"
#include "RootView.h"
#include <stack> 
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRootView

IMPLEMENT_DYNCREATE(CRootView, CView)

BEGIN_MESSAGE_MAP(CRootView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRootView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CRootView 构造/析构

CRootView::CRootView() noexcept
{
	// TODO: 在此处添加构造代码

}

CRootView::~CRootView()
{
}

BOOL CRootView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CRootView 绘图

void CRootView::OnDraw(CDC* pDC)
{
	CRootDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	 // 创建一个黑色的画笔来绘制矩形边框
	CPen blackPen(PS_SOLID, 1, RGB(0, 0, 0));
	CPen* pOldPen = pDC->SelectObject(&blackPen);

	// 绘制一个矩形作为边界
	pDC->Rectangle(200, 150, 600, 450);

	// 恢复旧的画笔
	pDC->SelectObject(pOldPen);
}


// CRootView 打印


void CRootView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CRootView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CRootView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CRootView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: 添加打印后进行的清理过程
}

void CRootView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CRootView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CRootView 诊断

#ifdef _DEBUG
void CRootView::AssertValid() const
{
	CView::AssertValid();
}

void CRootView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRootDoc* CRootView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRootDoc)));
	return (CRootDoc*)m_pDocument;
}
#endif //_DEBUG


// CRootView 消息处理程序
void CRootView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// 获取设备上下文(DC)，用于绘图
	CClientDC dc(this);

	// 定义填充颜色和边界颜色
	COLORREF fillColor = RGB(255, 0, 0); // 红色

	// 获取点击位置的颜色（即旧颜色）
	COLORREF oldColor = dc.GetPixel(point);

	// 调用种子填充算法
	SeedFill4(&dc, point.x, point.y, fillColor, oldColor);

	CView::OnLButtonDown(nFlags, point);
}

void CRootView::SeedFill4(CDC* pDC, int x, int y, COLORREF fillColor, COLORREF oldColor)
{
	// 如果起始点颜色不是旧颜色，或者已经是填充色，则直接返回
	if (pDC->GetPixel(x, y) != oldColor || pDC->GetPixel(x, y) == fillColor)
	{
		return;
	}

	std::stack<CPoint> s;
	s.push(CPoint(x, y));

	while (!s.empty())
	{
		CPoint current = s.top();
		s.pop();

		if (pDC->GetPixel(current) == oldColor)
		{
			pDC->SetPixel(current, fillColor); // 使用 SetPixel 填充颜色

			// 将四个方向的邻居压入栈中
			s.push(CPoint(current.x, current.y - 1));
			s.push(CPoint(current.x, current.y + 1));
			s.push(CPoint(current.x - 1, current.y));
			s.push(CPoint(current.x + 1, current.y));
		}
	}
}
