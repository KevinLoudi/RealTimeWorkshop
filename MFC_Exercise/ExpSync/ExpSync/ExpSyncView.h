
// ExpSyncView.h : interface of the CExpSyncView class
//


#pragma once

UINT MessageThread1(LPVOID pParam);
UINT MessageThread2(LPVOID pParam);
UINT MessageThread3(LPVOID pParam);


class CExpSyncView : public CView
{
protected: // create from serialization only
	CExpSyncView();
	DECLARE_DYNCREATE(CExpSyncView)

// Attributes
public:
	CExpSyncDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CExpSyncView();
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

#ifndef _DEBUG  // debug version in ExpSyncView.cpp
inline CExpSyncDoc* CExpSyncView::GetDocument() const
   { return reinterpret_cast<CExpSyncDoc*>(m_pDocument); }
#endif

