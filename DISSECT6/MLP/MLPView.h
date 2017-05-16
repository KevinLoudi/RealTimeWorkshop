// MLPView.h : interface of the CMLPView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MLPVIEW_H__8E7E4898_C03D_4848_AD3C_FBAC1DEACBF1__INCLUDED_)
#define AFX_MLPVIEW_H__8E7E4898_C03D_4848_AD3C_FBAC1DEACBF1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMLPView : public CView
{
protected: // create from serialization only
	CMLPView();
	DECLARE_DYNCREATE(CMLPView)

// Attributes
public:
	CMLPDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMLPView)
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
	virtual ~CMLPView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMLPView)
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MLPView.cpp
inline CMLPDoc* CMLPView::GetDocument()
   { return (CMLPDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MLPVIEW_H__8E7E4898_C03D_4848_AD3C_FBAC1DEACBF1__INCLUDED_)
