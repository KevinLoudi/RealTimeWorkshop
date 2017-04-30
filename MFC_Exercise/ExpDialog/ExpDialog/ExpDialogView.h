
// ExpDialogView.h : interface of the CExpDialogView class
//


#pragma once
#include "mDialog.h"
#include "IODialog.h"


class CExpDialogView : public CView
{
protected: // create from serialization only
	CExpDialogView();
	DECLARE_DYNCREATE(CExpDialogView)

// Attributes
public:
	CExpDialogDoc* GetDocument() const;

// Operations
public:
	CString m_ShowIn;
	CString m_ShowOut;

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CExpDialogView();
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

#ifndef _DEBUG  // debug version in ExpDialogView.cpp
inline CExpDialogDoc* CExpDialogView::GetDocument() const
   { return reinterpret_cast<CExpDialogDoc*>(m_pDocument); }
#endif

