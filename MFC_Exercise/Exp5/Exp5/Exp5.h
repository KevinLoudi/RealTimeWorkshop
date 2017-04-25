
// Exp5.h : main header file for the Exp5 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CExp5App:
// See Exp5.cpp for the implementation of this class
//

class CExp5App : public CWinApp
{
public:
	CExp5App();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CExp5App theApp;
