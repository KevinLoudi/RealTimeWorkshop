
#include "StdAfx.h"
#include "HELLO.H"
#include "Resource.h"

BOOL CMyWinApp::InitInstance()
{
	m_pMainWnd=new CMyFreamWnd();
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

CMyFreamWnd::CMyFreamWnd()
{
	Create(NULL, "First Show", WS_OVERLAPPEDWINDOW, rectDefault, NULL, "MainMeun");
}

void CMyFreamWnd::OnPaint()
{
	CPaintDC dc(this);
	CRect rect;

	GetClientRect(rect);
	dc.SetTextAlign(TA_BOTTOM|TA_CENTER);

	::LineDDA(rect.right/2,0, rect.right/2, rect.bottom/2,
		(LINEDDAPROC)LineDDACallback, (LPARAM)(LPVOID)&dc);
}

void CMyFreamWnd::OnAbout()
{
	CDialog about("AboutBox",this);
	about.DoModal();
}

VOID CALLBACK CMyFreamWnd::LineDDACallback(int x ,int y, LPARAM lpdc)
{
	static char szText[]="Nice to meet you.";

	((CDC*)lpdc)->TextOut(x,y,szText, sizeof(szText)-1);
	for (int i=1; i<50000; ++i)
	{
	}
}

BEGIN_MESSAGE_MAP(CMyFreamWnd,CFrameWnd)
	ON_COMMAND(IDM_ABOUT, OnAbout)
	ON_WM_PAINT()
END_MESSAGE_MAP()

