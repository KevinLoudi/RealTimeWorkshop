// Ser.h : main header file for the SER application
//

#if !defined(AFX_SER_H__8FA39F19_7D4D_417A_961A_0E34E5369D27__INCLUDED_)
#define AFX_SER_H__8FA39F19_7D4D_417A_961A_0E34E5369D27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSerApp:
// See Ser.cpp for the implementation of this class
//

class CSerApp : public CWinApp
{
public:
	CSerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSerApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SER_H__8FA39F19_7D4D_417A_961A_0E34E5369D27__INCLUDED_)
