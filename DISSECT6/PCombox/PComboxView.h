// PComboxView.h : interface of the CPComboxView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCOMBOXVIEW_H__D43430C5_7C22_4D34_BA1B_E0430E97B3FD__INCLUDED_)
#define AFX_PCOMBOXVIEW_H__D43430C5_7C22_4D34_BA1B_E0430E97B3FD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPComboxView : public CEditView
{
protected: // create from serialization only
	CPComboxView();
	DECLARE_DYNCREATE(CPComboxView)

// Attributes
public:
	CPComboxDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPComboxView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPComboxView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPComboxView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PComboxView.cpp
inline CPComboxDoc* CPComboxView::GetDocument()
   { return (CPComboxDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PCOMBOXVIEW_H__D43430C5_7C22_4D34_BA1B_E0430E97B3FD__INCLUDED_)
