
// RootView.h: CRootView 类的接口
//

#pragma once


class CRootView : public CView
{
protected: // 仅从序列化创建
	CRootView() noexcept;
	DECLARE_DYNCREATE(CRootView)

// 特性
public:
	CRootDoc* GetDocument() const;

// 操作
public:
	void SeedFill4(CDC* pDC, int x, int y, COLORREF fillColor, COLORREF oldColor);

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CRootView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point); // 声明鼠标左键按下消息处理函数
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // RootView.cpp 中的调试版本
inline CRootDoc* CRootView::GetDocument() const
   { return reinterpret_cast<CRootDoc*>(m_pDocument); }
#endif

