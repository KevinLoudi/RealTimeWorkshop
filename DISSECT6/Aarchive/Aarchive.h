// Aarchive.h : main header file for the AARCHIVE application
//

#if !defined(AFX_AARCHIVE_H__3F7E01E4_BC77_4C71_9EF5_1C6516485F66__INCLUDED_)
#define AFX_AARCHIVE_H__3F7E01E4_BC77_4C71_9EF5_1C6516485F66__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAarchiveApp:
// See Aarchive.cpp for the implementation of this class
//

class CAarchiveApp : public CWinApp
{
public:
	CAarchiveApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAarchiveApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAarchiveApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AARCHIVE_H__3F7E01E4_BC77_4C71_9EF5_1C6516485F66__INCLUDED_)
