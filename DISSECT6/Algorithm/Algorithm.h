// Algorithm.h : main header file for the ALGORITHM application
//

#if !defined(AFX_ALGORITHM_H__7E0B77C6_376B_4A24_A8AA_6E86DA03625D__INCLUDED_)
#define AFX_ALGORITHM_H__7E0B77C6_376B_4A24_A8AA_6E86DA03625D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAlgorithmApp:
// See Algorithm.cpp for the implementation of this class
//

class CAlgorithmApp : public CWinApp
{
public:
	CAlgorithmApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAlgorithmApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAlgorithmApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ALGORITHM_H__7E0B77C6_376B_4A24_A8AA_6E86DA03625D__INCLUDED_)
