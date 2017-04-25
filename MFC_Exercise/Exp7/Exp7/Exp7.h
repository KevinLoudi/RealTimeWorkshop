
// Exp7.h : main header file for the Exp7 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CExp7App:
// See Exp7.cpp for the implementation of this class
//

class CExp7App : public CWinApp
{
public:
	CExp7App();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CExp7App theApp;
