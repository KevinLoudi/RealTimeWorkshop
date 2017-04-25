
// Exp6.h : main header file for the Exp6 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CExp6App:
// See Exp6.cpp for the implementation of this class
//

class CExp6App : public CWinApp
{
public:
	CExp6App();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CExp6App theApp;
