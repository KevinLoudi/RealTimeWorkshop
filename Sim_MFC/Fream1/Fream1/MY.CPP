#include "my.h"

CMyWinApp theApp;

//------------------------------------------------------------------
// main
//------------------------------------------------------------------
void main()
{
	{
		CWinApp* pApp = AfxGetApp();
		pApp->InitApplication();
		pApp->InitInstance();
		pApp->Run();
	}

getchar();

}
//------------------------------------------------------------------



BOOL CMyWinApp::InitInstance()
{
	cout<<"CMyWinApp::InitInstance \n";
	m_pMainWnd=new CMyFrameWnd;
	return TRUE;
}
