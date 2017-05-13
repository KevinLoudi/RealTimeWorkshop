// EditCtrl.h : main header file for the EDITCTRL application
//

#if !defined(AFX_EDITCTRL_H__BC08FB88_F710_4800_83AC_735119154AB8__INCLUDED_)
#define AFX_EDITCTRL_H__BC08FB88_F710_4800_83AC_735119154AB8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEditCtrlApp:
// See EditCtrl.cpp for the implementation of this class
//

class CEditCtrlApp : public CWinApp
{
public:
	CEditCtrlApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditCtrlApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEditCtrlApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITCTRL_H__BC08FB88_F710_4800_83AC_735119154AB8__INCLUDED_)
