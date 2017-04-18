/*
 Propose: Inheritance App and window class
 Author: Kevin
 Date: 18th April, 2017
 Environment: Visual C++ 2008
*/

#include<windows.h>

HINSTANCE hInst; //Handle to an instance.				 				
HINSTANCE hInstance;
MSG msg;
char lpszClassName[]="window_class";
char*ShowText;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);//´°¿Úº¯Êý
void OnLButtonDown_(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
void OnPaint_(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
void OnDestroy_(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

//window class
class CFrameWnd_
{		
public:	
	HWND hWnd;
public:
	int RegisterWindow();	
	void Create(LPCTSTR lpClassName,
		LPCTSTR lpWindowName
		);	
	void ShowWindow(int nCmdShow);
	void UpdateWindow();
};

//implement window class
int CFrameWnd_::RegisterWindow()
{
	WNDCLASS wc;
	wc.style=0;
	wc.lpfnWndProc=WndProc;
	wc.cbClsExtra=0;
	wc.cbWndExtra=0;
	wc.hInstance=hInstance;
	wc.hIcon=LoadIcon(NULL,IDI_APPLICATION);
	wc.hCursor=LoadCursor(NULL,IDC_ARROW);
	wc.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName=NULL;
	wc.lpszClassName=lpszClassName;
	return RegisterClass(&wc);
}

void CFrameWnd_::Create(LPCTSTR lpClassName, LPCTSTR lpWindowName)
{
	RegisterWindow( );
	hInst = hInstance; 
	hWnd = CreateWindow(lpszClassName,
		lpWindowName, 
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 
		0, 
		CW_USEDEFAULT, 
		0, 
		NULL, 
		NULL, 
		hInstance, 
		NULL);
}

void CFrameWnd_::ShowWindow(int nCmdShow)
{
	::ShowWindow(hWnd,nCmdShow);
}

void CFrameWnd_::UpdateWindow()
{
	::UpdateWindow(hWnd);
}

class CWinApp_
{	
public:
	CWinApp_ *m_pCurrentApp;
	CFrameWnd_*m_pMainWnd;
public:
	CWinApp_(){m_pCurrentApp=this;};
	virtual BOOL InitInstance (int nCmdShow);
	int Run();
	~CWinApp_();
};

BOOL CWinApp_::InitInstance(int nCmdShow)
{
	m_pMainWnd=new CFrameWnd_;
	m_pMainWnd->Create(NULL,"Windows Application");
	m_pMainWnd->ShowWindow(nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

int CWinApp_::Run()
{
	while (GetMessage(&msg, NULL, 0, 0)) 
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

CWinApp_::~CWinApp_()
{
	delete m_pMainWnd;
}

//inherit a new window class and an application class
class CmFrameWnd_: public CFrameWnd_
{

};

class CmApp_: public CWinApp_
{
public:
	BOOL InitInstance(int nCmdShow);
};

BOOL CmApp_::InitInstance(int nCmdShow)
{
	CmFrameWnd_* m_pMainWnd=new CmFrameWnd_;
	m_pMainWnd->Create(NULL,"New Windows Application");
	m_pMainWnd->ShowWindow(nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

//******************Main 
CmApp_ theApp;

//get point of the current application
CWinApp_ *afxGetApp()
{
	return theApp.m_pCurrentApp;
}

int APIENTRY WinMain(HINSTANCE 	hInstance,
					 HINSTANCE 		hPrevInstance,
					 LPSTR     		lpCmdLine,
					 int       			nCmdShow)
{
	int ResultCode=-1;
	CWinApp_ *pApp=afxGetApp();
	pApp->InitInstance(nCmdShow);
	return ResultCode=pApp->Run();
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, 
						 WPARAM wParam, LPARAM lParam)
{
	switch (message) 
	{
	case WM_LBUTTONDOWN:	OnLButtonDown_(hWnd, message, wParam, lParam);	
		break;
	case WM_PAINT:			OnPaint_(hWnd, message,wParam, lParam);
		break;
	case WM_DESTROY:		OnDestroy_(hWnd, message, wParam, lParam);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

void OnLButtonDown_(HWND hWnd, UINT message, 
				   WPARAM wParam, LPARAM lParam)
{
	ShowText="Hello!";
	InvalidateRect(hWnd,NULL,1);
}
void OnPaint_(HWND hWnd, UINT message, 
			 WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	hdc = BeginPaint(hWnd, &ps);
	TextOut(hdc,50,50,ShowText,6);
	EndPaint(hWnd, &ps);
}
void OnDestroy_(HWND hWnd, UINT message, 
			   WPARAM wParam, LPARAM lParam)
{
	PostQuitMessage(0);
}