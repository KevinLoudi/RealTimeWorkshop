
// Exp3View.h : interface of the CExp3View class
//


#pragma once


class CExp3View : public CView
{
protected: // create from serialization only
	CExp3View();
	DECLARE_DYNCREATE(CExp3View)

// Attributes
public:
	CExp3Doc* GetDocument() const;
	CArray<CRect,CRect&>m_Rectag;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CExp3View();
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
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in Exp3View.cpp
inline CExp3Doc* CExp3View::GetDocument() const
   { return reinterpret_cast<CExp3Doc*>(m_pDocument); }
#endif

