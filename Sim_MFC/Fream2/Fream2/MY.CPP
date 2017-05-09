#include "my.h"

CMyWinApp theApp;

BOOL CMyWinApp::InitInstance()
{
    cout << "CMyWinApp::InitInstance \n";
    m_pMainWnd = new CMyFrameWnd;
    return TRUE;
}

CMyFrameWnd::CMyFrameWnd()
{
    cout << "CMyFrameWnd::CMyFrameWnd \n";
    Create();
}

IMPLEMENT_DYNAMIC(CMyDoc,CDocument)
IMPLEMENT_DYNCREATE(CMyDoc,CDocument)
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

		//PrintAllClasses();  //print out all runtime class information

		CMyDoc pMyDoc("Justice");
		cout<<pMyDoc.IsKindof(RUNTIME_CLASS(CMyDoc))<<"\n";
	
	}

	{
		//Test dynamic creation
		cout<<"Test dynamic creation \n";
		CRuntimeClass* pClassRef;
		CObject* pOb;
	}

	getchar();
}

void PrintAllClasses()
{
	CRuntimeClass* pClass;

	for (pClass=CRuntimeClass::pFirstClass; pClass!=NULL; pClass=pClass->m_pNextClass)
	{
		cout<<pClass->m_lpszClassName<<"\n";
		cout<<pClass->m_nObjectSize<<"\n";
		cout<<pClass->m_wSchema<<"\n";
	}
}

//------------------------------------------------------------------
