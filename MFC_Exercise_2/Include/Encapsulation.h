/*
 Propose: Encapsulate Framework and windows
 Author: Kevin
 Date: 18th April, 2017
 Environment: Visual C++ 2008
*/
#include <Windows.h>

//global variables
HINSTANCE hInst;
HINSTANCE hInstance;
MSG msg;
char lpszClassName[]="window_class";
char* ShowText;

//Declare the function prototype
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); //window process
void OnLButtonDown(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
void OnPaint(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
void OnDestroy(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

//Window class
class CFrameWnd
{
public:
	HWND hWnd;

public:
	//operations of window-frame object
	int RegisterClass();
	void Create(LPCTSTR lpszClassName, LPCTSTR lpWindowName);
	void ShowWindow(int nCmdShow);
	void UpdateWindow();
};

//Application class
class CWinApp
{
public:
	CFrameWnd *m_pMainWnd;
};

