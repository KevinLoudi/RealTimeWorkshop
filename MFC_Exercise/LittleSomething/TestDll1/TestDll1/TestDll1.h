
// TestDll1.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CTestDll1App:
// See TestDll1.cpp for the implementation of this class
//

class CTestDll1App : public CWinAppEx
{
public:
	CTestDll1App();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CTestDll1App theApp;