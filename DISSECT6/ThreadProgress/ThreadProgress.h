// ThreadProgress.h : main header file for the THREADPROGRESS application
//

#if !defined(AFX_THREADPROGRESS_H__908BA692_1F81_4AA6_AEBF_B211817B1D2D__INCLUDED_)
#define AFX_THREADPROGRESS_H__908BA692_1F81_4AA6_AEBF_B211817B1D2D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CThreadProgressApp:
// See ThreadProgress.cpp for the implementation of this class
//

class CThreadProgressApp : public CWinApp
{
public:
	CThreadProgressApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThreadProgressApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CThreadProgressApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THREADPROGRESS_H__908BA692_1F81_4AA6_AEBF_B211817B1D2D__INCLUDED_)
