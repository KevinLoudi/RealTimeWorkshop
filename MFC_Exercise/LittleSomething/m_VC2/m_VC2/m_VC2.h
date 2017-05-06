
// m_VC2.h : main header file for the m_VC2 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// Cm_VC2App:
// See m_VC2.cpp for the implementation of this class
//

class Cm_VC2App : public CWinApp
{
public:
	Cm_VC2App();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cm_VC2App theApp;
