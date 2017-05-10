
#include <iostream>
#include "mfc.h"
using namespace std;

class CMyWinApp : public CWinApp
{
public:
  CMyWinApp::CMyWinApp()   {
                           }
  CMyWinApp::~CMyWinApp()  {
                           }

  virtual BOOL InitInstance();
};

class CMyFrameWnd : public CFrameWnd
{
public:
	DECLARE_DYNCREATE(CMyFrameWnd)
  CMyFrameWnd();
  ~CMyFrameWnd()  { }
  void Response() const;
};

class CMyDoc : public CDocument
{
DECLARE_DYNCREATE(CMyDoc)
private:
	LPSTR DocName;

public:
	CMyDoc() {DocName="Justice";}
	CMyDoc(char* namestr){DocName=(LPSTR)namestr;}
};

void PrintAllClasses();