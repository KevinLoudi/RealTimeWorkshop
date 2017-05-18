// SerView.h : interface of the CSerView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SERVIEW_H__36D782F5_FE82_4779_A2C4_7102EA720AF5__INCLUDED_)
#define AFX_SERVIEW_H__36D782F5_FE82_4779_A2C4_7102EA720AF5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSerView : public CView
{
protected: // create from serialization only
	CSerView();
	DECLARE_DYNCREATE(CSerView)

// Attributes
public:
	CSerDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSerView)
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
	virtual ~CSerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSerView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SerView.cpp
inline CSerDoc* CSerView::GetDocument()
   { return (CSerDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVIEW_H__36D782F5_FE82_4779_A2C4_7102EA720AF5__INCLUDED_)
