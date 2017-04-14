/*
 Propose: Modularized Window-message handling
 Author: Kevin
 Date: 14th April, 2017
 Environment: Visual C++ 2008
*/

//head files
#include <windows.h>

//gobal variables
HINSTANCE hInst;
HWND hWnd;
MSG msg;
char lpszClassName[]="Window";
char* showText;

//declare function
ATOM mRegisterClass(HINSTANCE hInstance); //windows regist
BOOL Create(HINSTANCE, int); //create app instance
int Run(); //messge handling
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM); //window process

//event
void OnLButtonDown(HWND hWnd,UINT messge,
	WPARAM wParam, LPARAM lParam);
void OnPaint(HWND hWnd,UINT messge,
	WPARAM wParam, LPARAM lParam);
void OnDestroy(HWND hWnd,UINT messge,
	WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	mRegisterClass(hInstance); //define and register window class
	Create(hInstance,nCmdShow); //create window
	ShowWindow(hWnd,nCmdShow);
	UpdateWindow(hWnd);
	return Run(); //start messaging loop
}

//register windows function
ATOM mRegisterClass(HINSTANCE hInstance)
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

//create window
BOOL Create(HINSTANCE hInstance, int cCmdShow)
{
	hWnd=CreateWindow(lpszClassName,
		"Window",
		WS_OVERLAPPEDWINDOW,
		400,300,180,160,
		NULL,NULL,
		hInstance,
		NULL);
	return TRUE;
}

//message loop
int Run()
{
	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

//windows process
LRESULT CALLBACK WndProc(HWND hWnd,UINT message,
	WPARAM wParam,LPARAM lParam) //window process
{
	switch(message)
	{
		case WM_LBUTTONDOWN:
		  {
		  	OnLButtonDown(hWnd, message, wParam, lParam);
		  }
		break; 
		case WM_PAINT:			
		  {
			OnPaint(hWnd, message,wParam, lParam);
		  }
		break;
		case WM_DESTROY:		
		  {
			OnDestroy(hWnd, message, wParam, lParam);
		  }
		break; 

		default:
		 return DefWindowProc(hWnd, message,wParam, lParam);
	}	
	return 0;
}

//message handling
void OnLButtonDown(HWND hWnd, UINT message, 
				WPARAM wParam, LPARAM lParam)
{
	showText="Today";
	InvalidateRect(hWnd,NULL,1);
}

void OnPaint(HWND hWnd, UINT message, 
				WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	hdc = BeginPaint(hWnd, &ps);
	TextOut(hdc,50,50,showText,6);
	EndPaint(hWnd, &ps);
}

void OnDestroy(HWND hWnd, UINT message, 
				WPARAM wParam, LPARAM lParam)
{
	PostQuitMessage(0);
}