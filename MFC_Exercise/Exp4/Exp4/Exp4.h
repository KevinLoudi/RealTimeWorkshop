
// Exp4.h : main header file for the Exp4 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CExp4App:
// See Exp4.cpp for the implementation of this class
//

class CExp4App : public CWinApp
{
public:
	CExp4App();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CExp4App theApp;
