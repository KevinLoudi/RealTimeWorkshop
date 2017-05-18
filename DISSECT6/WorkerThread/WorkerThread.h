// WorkerThread.h : main header file for the WORKERTHREAD application
//

#if !defined(AFX_WORKERTHREAD_H__3F7B1718_D1E6_4F86_A1D5_78259742F442__INCLUDED_)
#define AFX_WORKERTHREAD_H__3F7B1718_D1E6_4F86_A1D5_78259742F442__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWorkerThreadApp:
// See WorkerThread.cpp for the implementation of this class
//

class CWorkerThreadApp : public CWinApp
{
public:
	CWorkerThreadApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWorkerThreadApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWorkerThreadApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORKERTHREAD_H__3F7B1718_D1E6_4F86_A1D5_78259742F442__INCLUDED_)
