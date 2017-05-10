#include "my.h"  // it should be mfc.h, but for CMyWinApp definition, so...

extern CMyWinApp theApp;

static char szCObject[]="CObject";
struct CRuntimeClass CObject::classCObject={
	szCObject, sizeof(CObject), 0Xffff, NULL, NULL };
static AFX_CLASSINIT _init_CObject(&CObject::classCObject);

CRuntimeClass* CRuntimeClass::pFirstClass = NULL;

AFX_CLASSINIT::AFX_CLASSINIT(CRuntimeClass* pNewClass)
{
        pNewClass->m_pNextClass = CRuntimeClass::pFirstClass;
        CRuntimeClass::pFirstClass = pNewClass;
}

CObject* CRuntimeClass::CreateObject()
{
	if (m_pfnCreateObject==NULL)
	{
		TRACE1("Errror: Trying to create object which has not been ","DECLARE_DYNCRATE \nor DECLARE_SERIAL: %hs. \n",
			m_lpszClassName);
		return NULL;
	}

	CObject* pObject=NULL;
	pObject=(*m_pfnCreateObject)();

	return pObject;
}

CRuntimeClass* PASCAL CRuntimeClass::Load()
{
	char szClassName[64];
	CRuntimeClass* pClass; //runtime class link list

	//load for console
	cout<<"Please enter a class name you want to dynamic created: ";
	cin>>szClassName;

	//search matched class in the runtime class link list
	for (pClass=pFirstClass; pClass!=NULL; pClass=pClass->m_pNextClass)
	{
		if (strcmp(szClassName, pClass->m_lpszClassName)==0)
		{
			return pClass;
		}
	}

	TRACE1("Error: Class not found: %s \n", szClassName);
	return NULL;
}

CRuntimeClass* CObject::GetRuntimeClass() const
{
	return &CObject::classCObject;
}

BOOL CObject::IsKindof(const CRuntimeClass* pClass) const
{
	CRuntimeClass* pClassThis=GetRuntimeClass();

	while (pClassThis != NULL)
	{
		if (pClassThis==pClass)
		{
			return TRUE;
		}
		pClassThis=pClassThis->m_pBaseClass;
	}
	return FALSE;
}

void CObject::Response() const
{
	cout<<"Is an object of class CObject \n";
}

BOOL CWnd::Create()
{
  cout << "CWnd::Create \n";
  return TRUE;
}

BOOL CWnd::CreateEx()
{
  cout << "CWnd::CreateEx \n";
  PreCreateWindow();
  return TRUE;
}

BOOL CWnd::PreCreateWindow()
{
  cout << "CWnd::PreCreateWindow \n";
  return TRUE;
}

void CWnd::Response() const
{
	cout<<"Is an object of CWnd class";
}

BOOL CFrameWnd::Create()
{
  cout << "CFrameWnd::Create \n";
  CreateEx();
  return TRUE;
}

BOOL CFrameWnd::PreCreateWindow()
{
  cout << "CFrameWnd::PreCreateWindow \n";
  return TRUE;
}

void CFrameWnd::Response() const
{
	cout<<"Is an object of class CFrameWnd";
}

IMPLEMENT_DYNAMIC(CCmdTarget, CObject);
IMPLEMENT_DYNAMIC(CWinThread, CCmdTarget)
IMPLEMENT_DYNAMIC(CWinApp, CWinThread)

//IMPLEMENT_DYNAMIC(CWnd, CCmdTarget)
IMPLEMENT_DYNCREATE(CWnd,CCmdTarget)

//IMPLEMENT_DYNAMIC(CFrameWnd, CWnd)
IMPLEMENT_DYNCREATE(CFrameWnd,CWnd)

//IMPLEMENT_DYNAMIC(CDocument, CCmdTarget)
IMPLEMENT_DYNAMIC(CView, CWnd)

IMPLEMENT_DYNAMIC(CDocument, CCmdTarget)

void CDocument::Response() const
{
	cout<<"Is an object of class CDocument \n";
}

CWinApp* AfxGetApp()
{
  return theApp.m_pCurrentWinApp;
}
