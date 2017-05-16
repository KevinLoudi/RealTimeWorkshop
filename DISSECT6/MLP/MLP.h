// MLP.h : main header file for the MLP application
//

#if !defined(AFX_MLP_H__36B4D6CD_B924_4F2B_9E68_86D199E9C405__INCLUDED_)
#define AFX_MLP_H__36B4D6CD_B924_4F2B_9E68_86D199E9C405__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMLPApp:
// See MLP.cpp for the implementation of this class
//

class CMLPApp : public CWinApp
{
public:
	CMLPApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMLPApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMLPApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MLP_H__36B4D6CD_B924_4F2B_9E68_86D199E9C405__INCLUDED_)
