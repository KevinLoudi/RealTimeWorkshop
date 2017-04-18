/*
 Propose: Encapsulate Framework and windows
 Author: Kevin
 Date: 18th April, 2017
 Environment: Visual C++ 2008
*/
#include <Windows.h>

//Declare the function prototype
void OnLButtonDown(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
void OnPaint(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
void OnDestroy(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

//global variables

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); //window process

//Window class
class CFrameWnd
{
public:
	HWND hWnd;

public:
	//operations of window-frame object
	int RegisterWindow();
	void Create(LPCTSTR lpszClassName, LPCTSTR lpWindowName);
	void ShowWindow(int nCmdShow);
	void UpdateWindow();
};

//Application class
class CWinApp
{
public:
	CFrameWnd *m_pMainWnd; //window-frame object

public:
	BOOL InitInstance(int nCmdShow); //initial window object
	int Run(); //implement message loop
};

HINSTANCE hInst;
HINSTANCE hInstance;
MSG msg;
char lpszClassName[]="window_class";
char* ShowText;

CWinApp theApp;

int APIENTRY WinMain(HINSTANCE hInstance,  HINSTANCE hPrevInstance, 
					  LPSTR lpCmdLine,  int nShowCmd )
{
	int ResultCode=1;
	theApp.InitInstance(nShowCmd);
	return ResultCode=theApp.Run();
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	//message loop
	switch(message)
	{
	case WM_LBUTTONDOWN: OnLButtonDown(hWnd, message, wParam, lParam);
		break;
	case WM_PAINT: OnPaint(hWnd, message, wParam, lParam);
		break;
	case WM_DESTROY: OnDestroy(hWnd, message, wParam, lParam);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

void OnLButtonDown(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	ShowText="Hello!";
	InvalidateRect(hWnd,NULL,1);
}

void OnPaint(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	hdc = BeginPaint(hWnd, &ps);
	TextOut(hdc,50,50,ShowText,6);
	EndPaint(hWnd, &ps);
}

void OnDestroy(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PostQuitMessage(0);
}

//implement window class
int CFrameWnd::RegisterWindow()
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

void CFrameWnd::Create(LPCTSTR lpszClassName, LPCTSTR lpWindowName)
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

void CFrameWnd::ShowWindow(int nCmdShow)
{
	::ShowWindow(hWnd,nCmdShow);
}

void CFrameWnd::UpdateWindow()
{
	::UpdateWindow(hWnd);
}

//implement application
BOOL CWinApp::InitInstance(int nCmdShow)
{
	m_pMainWnd=new CFrameWnd;
	m_pMainWnd->Create(NULL,"Encapsulated Class");
	m_pMainWnd->ShowWindow(nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

int CWinApp::Run()
{
	while (GetMessage(&msg, NULL, 0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

