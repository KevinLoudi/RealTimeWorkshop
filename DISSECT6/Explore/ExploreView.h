// ExploreView.h : interface of the CExploreView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXPLOREVIEW_H__C36FFB3D_456F_4078_9136_25773C33C13E__INCLUDED_)
#define AFX_EXPLOREVIEW_H__C36FFB3D_456F_4078_9136_25773C33C13E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CExploreView : public CHtmlView
{
protected: // create from serialization only
	CExploreView();
	DECLARE_DYNCREATE(CExploreView)

// Attributes
public:
	CExploreDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExploreView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CExploreView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CExploreView)
	afx_msg void OnCsdn();
	afx_msg void OnVcshare();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ExploreView.cpp
inline CExploreDoc* CExploreView::GetDocument()
   { return (CExploreDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPLOREVIEW_H__C36FFB3D_456F_4078_9136_25773C33C13E__INCLUDED_)
