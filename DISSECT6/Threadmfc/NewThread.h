#if !defined(AFX_NEWTHREAD_H__125EEFB3_B171_4625_B5F9_4B33D7FCF8B9__INCLUDED_)
#define AFX_NEWTHREAD_H__125EEFB3_B171_4625_B5F9_4B33D7FCF8B9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NewThread.h : header file
//

#include "NewDlg.h"

/////////////////////////////////////////////////////////////////////////////
// CNewThread thread

class CNewThread : public CWinThread
{
	DECLARE_DYNCREATE(CNewThread)
public:
	CNewThread();           // protected constructor used by dynamic creation

// Attributes
public:
	CNewDlg m_dlg;
	

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewThread)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CNewThread();

	// Generated message map functions
	//{{AFX_MSG(CNewThread)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWTHREAD_H__125EEFB3_B171_4625_B5F9_4B33D7FCF8B9__INCLUDED_)
