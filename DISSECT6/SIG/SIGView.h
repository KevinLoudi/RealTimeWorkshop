// SIGView.h : interface of the CSIGView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SIGVIEW_H__B68E804E_07BA_4ABC_9B45_73E393D9FBF7__INCLUDED_)
#define AFX_SIGVIEW_H__B68E804E_07BA_4ABC_9B45_73E393D9FBF7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSIGView : public CView
{
protected: // create from serialization only
	CSIGView();
	DECLARE_DYNCREATE(CSIGView)

// Attributes
public:
	CSIGDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSIGView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSIGView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSIGView)
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SIGView.cpp
inline CSIGDoc* CSIGView::GetDocument()
   { return (CSIGDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIGVIEW_H__B68E804E_07BA_4ABC_9B45_73E393D9FBF7__INCLUDED_)
