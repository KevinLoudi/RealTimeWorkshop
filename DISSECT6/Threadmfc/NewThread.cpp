// NewThread.cpp : implementation file
//

#include "stdafx.h"
#include "Threadmfc.h"
#include "NewThread.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNewThread

IMPLEMENT_DYNCREATE(CNewThread, CWinThread)

CNewThread::CNewThread()
{
}

CNewThread::~CNewThread()
{
}

BOOL CNewThread::InitInstance()
{
	// TODO:  perform and per-thread initialization here
	m_pMainWnd=&m_dlg;
	m_dlg.DoModal();

	return TRUE;
}

int CNewThread::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CNewThread, CWinThread)
	//{{AFX_MSG_MAP(CNewThread)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewThread message handlers
