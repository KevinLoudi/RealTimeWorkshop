
// VisibleAlogrithmView.h : interface of the CVisibleAlogrithmView class
//


#pragma once

#include "TypeDlg.h"

class CVisibleAlogrithmView : public CView
{
protected: // create from serialization only
	CVisibleAlogrithmView();
	DECLARE_DYNCREATE(CVisibleAlogrithmView)

// Attributes
public:
	CVisibleAlogrithmDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CVisibleAlogrithmView();
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
	afx_msg void OnType();
};

#ifndef _DEBUG  // debug version in VisibleAlogrithmView.cpp
inline CVisibleAlogrithmDoc* CVisibleAlogrithmView::GetDocument() const
   { return reinterpret_cast<CVisibleAlogrithmDoc*>(m_pDocument); }
#endif

