#if !defined(AFX_ACLOCK_H__13A1EC78_4009_4808_B50C_D92195E81063__INCLUDED_)
#define AFX_ACLOCK_H__13A1EC78_4009_4808_B50C_D92195E81063__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// AClock.h : main header file for ACLOCK.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CAClockApp : See AClock.cpp for implementation.

class CAClockApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ACLOCK_H__13A1EC78_4009_4808_B50C_D92195E81063__INCLUDED)
