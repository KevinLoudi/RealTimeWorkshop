
// ExpSDI.h : main header file for the ExpSDI application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CExpSDIApp:
// See ExpSDI.cpp for the implementation of this class
//

class CExpSDIApp : public CWinApp
{
public:
	CExpSDIApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CExpSDIApp theApp;
