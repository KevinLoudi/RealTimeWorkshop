
// ExpMultiThreadView.h : interface of the CExpMultiThreadView class
//


#pragma once
#include "mThread.h"

UINT MessageThread(LPVOID pParam);


class CExpMultiThreadView : public CView
{
protected: // create from serialization only
	CExpMultiThreadView();
	DECLARE_DYNCREATE(CExpMultiThreadView)

// Attributes
public:
	CExpMultiThreadDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CExpMultiThreadView();
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
};

#ifndef _DEBUG  // debug version in ExpMultiThreadView.cpp
inline CExpMultiThreadDoc* CExpMultiThreadView::GetDocument() const
   { return reinterpret_cast<CExpMultiThreadDoc*>(m_pDocument); }
#endif

