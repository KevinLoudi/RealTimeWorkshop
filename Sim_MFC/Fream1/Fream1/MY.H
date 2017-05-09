
#include <iostream>
#include "mfc.h"
using namespace std;

class CMyWinApp : public CWinApp
{
public:
  CMyWinApp::CMyWinApp()   {
                              cout << "CMyWinApp Constructor \n";
                           }
  CMyWinApp::~CMyWinApp()  {
                              cout << "CMyWinApp Destructor \n";
                           }
  virtual BOOL InitInstance();
};

class CMyFrameWnd : public CFrameWnd
{
public:
  CMyFrameWnd()   {
                     cout << "CMyFrameWnd Constructor \n";
                  }
  ~CMyFrameWnd()  {
                     cout << "CMyFrameWnd Destructor \n";
                  }
};

class CMyView: public CView
{
	public:
		CMyView()   {
			cout << "CMyView Constructor \n";
		}
		~CMyView()  {
			cout << "CMyView Destructor \n";
		}
};

class CMyDoc: public CDocument
{
public:
	CMyDoc()   {
		cout << "CMyDoc Constructor \n";
	}
	~CMyDoc()  {
		cout << "CMyDoc Destructor \n";
	}
};