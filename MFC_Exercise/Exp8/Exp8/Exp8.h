
// Exp8.h : main header file for the Exp8 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CExp8App:
// See Exp8.cpp for the implementation of this class
//

class CExp8App : public CWinApp
{
public:
	CExp8App();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CExp8App theApp;
