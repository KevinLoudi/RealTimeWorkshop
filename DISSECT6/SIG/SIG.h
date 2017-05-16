// SIG.h : main header file for the SIG application
//

#if !defined(AFX_SIG_H__CF30B5AC_73C4_4A00_9BFB_A48C7D9F8BBF__INCLUDED_)
#define AFX_SIG_H__CF30B5AC_73C4_4A00_9BFB_A48C7D9F8BBF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSIGApp:
// See SIG.cpp for the implementation of this class
//

class CSIGApp : public CWinApp
{
public:
	CSIGApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSIGApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSIGApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIG_H__CF30B5AC_73C4_4A00_9BFB_A48C7D9F8BBF__INCLUDED_)
