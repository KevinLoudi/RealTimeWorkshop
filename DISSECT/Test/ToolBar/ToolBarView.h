
// ToolBarView.h : interface of the CToolBarView class
//


#pragma once


class CToolBarView : public CView
{
protected: // create from serialization only
	CToolBarView();
	DECLARE_DYNCREATE(CToolBarView)

// Attributes
public:
	CToolBarDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CToolBarView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ToolBarView.cpp
inline CToolBarDoc* CToolBarView::GetDocument() const
   { return reinterpret_cast<CToolBarDoc*>(m_pDocument); }
#endif

