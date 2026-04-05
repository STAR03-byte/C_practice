// t1View.h: Ct1View 类的接口
//

#pragma once


class Ct1View : public CView
{
protected: // 仅从序列化创建
	Ct1View() noexcept;
	DECLARE_DYNCREATE(Ct1View)

	// 特性
public:
	Ct1Doc* GetDocument() const;

	// 操作
public:

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
	virtual ~Ct1View();
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

	// 添加鼠标事件处理
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);

	DECLARE_MESSAGE_MAP()

private:
	// 圆的参数
	int m_nCenterX;    // 圆心X坐标
	int m_nCenterY;    // 圆心Y坐标
	int m_nRadius;     // 圆的半径

	// 绘制状态
	bool m_bDrawing;   // 是否正在绘制
	CPoint m_ptStart;  // 起始点
	CPoint m_ptEnd;    // 结束点

	// 中点圆算法
	void MidPointCircle(CDC* pDC, int xc, int yc, int r);

	// 绘制圆的八个对称点
	void DrawCirclePoints(CDC* pDC, int xc, int yc, int x, int y);
};

#ifndef _DEBUG  // t1View.cpp 中的调试版本
inline Ct1Doc* Ct1View::GetDocument() const
{
	return reinterpret_cast<Ct1Doc*>(m_pDocument);
}
#endif
