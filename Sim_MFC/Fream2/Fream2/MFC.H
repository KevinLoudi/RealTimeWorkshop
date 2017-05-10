#define BOOL int
#define TRUE 1
#define FALSE 0
#define LPCSTR LPSTR
typedef char* LPSTR;
#define UINT unsigned int
#define PASCAL _stdcall
#define TRACE1 printf

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class CObject;

struct CRuntimeClass
{
	// Attributes
	LPCSTR m_lpszClassName;
	int m_nObjectSize;
	UINT m_wSchema; // schema number of the loaded class
	CObject* (PASCAL* m_pfnCreateObject)(); // NULL => abstract class
	CRuntimeClass* m_pBaseClass;

	//Dynamic creation
	CObject* CreateObject();
	static CRuntimeClass* PASCAL Load();

	// CRuntimeClass objects linked together in simple list
	static CRuntimeClass* pFirstClass; // start of class list
	CRuntimeClass* m_pNextClass;       // linked list of registered classes
};

struct AFX_CLASSINIT
{ AFX_CLASSINIT(CRuntimeClass* pNewClass); };

#define RUNTIME_CLASS(class_name) \
	(&class_name::class##class_name)

#define DECLARE_DYNAMIC(class_name) \
public: \
	static CRuntimeClass class##class_name; \
	virtual CRuntimeClass* GetRuntimeClass() const;

#define _IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, wSchema, pfnNew) \
	static char _lpsz##class_name[] = #class_name; \
	CRuntimeClass class_name::class##class_name = { \
	_lpsz##class_name, sizeof(class_name), wSchema, pfnNew, \
	RUNTIME_CLASS(base_class_name), NULL }; \
	static AFX_CLASSINIT _init_##class_name(&class_name::class##class_name); \
	CRuntimeClass* class_name::GetRuntimeClass() const \
{ return &class_name::class##class_name; } \

#define IMPLEMENT_DYNAMIC(class_name, base_class_name) \
	_IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, 0xFFFF, NULL)

//Implement dynamic creation
#define DECLARE_DYNCREATE(class_name) \
	DECLARE_DYNAMIC(class_name) \
	static CObject* PASCAL CreateObject();

#define  IMPLEMENT_DYNCREATE(class_name, base_class_name) \
	CObject* PASCAL class_name::CreateObject() \
				{return new class_name; } \
			_IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, 0xFFFF, NULL)


class CObject
{
public:
  CObject::CObject()  {
                      }
  CObject::~CObject() {
                      }

  virtual CRuntimeClass* GetRuntimeClass() const;
  virtual BOOL IsKindof(const CRuntimeClass* pClass) const;
  virtual void Response() const;

public:
	static CRuntimeClass classCObject;
};

class CCmdTarget : public CObject
{
public:
  DECLARE_DYNAMIC(CCmdTarget)
  CCmdTarget::CCmdTarget()  {
                            }
  CCmdTarget::~CCmdTarget() {
                            }
};

class CWinThread : public CCmdTarget
{
public:
  DECLARE_DYNAMIC(CWinThread)
  CWinThread::CWinThread()  {
                            }
  CWinThread::~CWinThread() {
                            }

  virtual BOOL InitInstance() {
                                cout << "CWinThread::InitInstance \n";
                                return TRUE;
                              }
  virtual int Run() {
                      cout << "CWinThread::Run \n";
                      return 1;
                    }
};

class CWnd;

class CWinApp : public CWinThread
{
public:
  DECLARE_DYNAMIC(CWinApp)
  CWinApp* m_pCurrentWinApp;
  CWnd* m_pMainWnd;

public:
  CWinApp::CWinApp()  {
                        m_pCurrentWinApp = this;
                      }
  CWinApp::~CWinApp() {
                      }

  virtual BOOL InitApplication() {
                                   cout << "CWinApp::InitApplication \n";
                                   return TRUE;
                                 }
  virtual BOOL InitInstance()    {
                                   cout << "CWinApp::InitInstance \n";
                                   return TRUE;
                                 }
  virtual int Run() {
                      cout << "CWinApp::Run \n";
                      return CWinThread::Run();
                    }
};


class CDocument : public CCmdTarget
{
public:
	DECLARE_DYNAMIC(CDocument)
  CDocument::CDocument()   {
                           }
  CDocument::~CDocument()  {
                           }
  void Response() const;
};


class CWnd : public CCmdTarget
{
public:
	//DECLARE_DYNAMIC(CWnd)
	DECLARE_DYNCREATE(CWnd)
  CWnd::CWnd()   {
                 }
  CWnd::~CWnd()  {
                 }

  virtual BOOL Create();
  BOOL CreateEx();
  virtual BOOL PreCreateWindow();
  virtual void Response() const;
};

class CFrameWnd : public CWnd
{
public:
	//DECLARE_DYNAMIC(CFrameWnd)
	DECLARE_DYNCREATE(CFrameWnd)
  CFrameWnd::CFrameWnd()   {
                           }
  CFrameWnd::~CFrameWnd()  {
                           }
  BOOL Create();
  virtual BOOL PreCreateWindow();
  virtual void Response() const;
};

class CView : public CWnd
{
public:
	DECLARE_DYNAMIC(CView)
  CView::CView()   {
                   }
  CView::~CView()  {
                   }
};


// global function

CWinApp* AfxGetApp();

