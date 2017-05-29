// TestDB1.h : main header file for the TESTDB1 application
//

#if !defined(AFX_TESTDB1_H__D4F02A3E_907A_4BEC_B0B9_976ECF948F7D__INCLUDED_)
#define AFX_TESTDB1_H__D4F02A3E_907A_4BEC_B0B9_976ECF948F7D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTestDB1App:
// See TestDB1.cpp for the implementation of this class
//

class CTestDB1App : public CWinApp
{
public:
	CTestDB1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestDB1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTestDB1App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTDB1_H__D4F02A3E_907A_4BEC_B0B9_976ECF948F7D__INCLUDED_)
