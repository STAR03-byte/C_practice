// MFC_CircleDrawView.h（修改后）
#pragma once

// 前向声明替代头文件包含
class CMFCCircleDrawDoc;

class CMFCCircleDrawView : public CView
{
protected: // 仅从序列化创建
	CMFCCircleDrawView() noexcept;
	DECLARE_DYNCREATE(CMFCCircleDrawView)

	// 特性
public:
	CMFCCircleDrawDoc* GetDocument() const;

	// 操作
public:
	void MidpointCircle(CDC* pDC, int xc, int yc, int r);
	void Draw8Points(CDC* pDC, int xc, int yc, int x, int y);

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
	virtual ~CMFCCircleDrawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	// 圆的参数
	int m_nCenterX;
	int m_nCenterY;
	int m_nRadius;
	bool m_bShouldDraw; // 标记是否需要绘制圆
	bool m_bDrawing;    // 标记是否正在绘制圆
	CPoint m_ptStart;   // 起始点（圆心）
	CPoint m_ptEnd;     // 结束点（用于计算半径）

	// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnDrawCircle();      // 绘制圆的菜单命令
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);  // 鼠标左键按下
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);    // 鼠标左键释放
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);    // 鼠标移动
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);  // 键盘按下
	DECLARE_MESSAGE_MAP()
};