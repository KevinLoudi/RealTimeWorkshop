/*
 Propose: Demo the Windows handling of window and message
 Author: Kevin
 Date: 14th April, 2017
 Environment: Visual C++ 2008
*/

#include<windows.h>
//decalare system call-back function
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
//---------------------------------------------------------------------------------------------
//main function
int WINAPI WinMain(HINSTANCE hInstance,
				   HINSTANCE PreInstance,
				   LPSTR lpCmdLine,
				   int nCmdShow)
{
	HWND hwnd; //window handler

	MSG  msg; //store messages

	//details of a window
	char lpszClassName[]="Demo of Main Window";
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

	//register the window
	RegisterClass(&wc);

	//create the window
	hwnd=CreateWindow(	lpszClassName,
						"Windows",
						WS_OVERLAPPEDWINDOW,
						120,50,800,600,
						NULL,
						NULL,
						hInstance,
						NULL);

	//show the window and update the screen
	ShowWindow(hwnd,nCmdShow);
	UpdateWindow(hwnd);

	//message loop
	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
//---------------------------------------------------------------------------------------------
//window process handling message, called by Windows system
LRESULT CALLBACK WndProc(HWND hwnd,
						 UINT message,
						 WPARAM wParam,
						 LPARAM lParam)
{
	//message handling
	switch(message)
	{
	case WM_LBUTTONDOWN:
		{
			MessageBeep(0);
		}
		break;
	case WM_RBUTTONDOWN:
		{
			MessageBeep(1);
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd,message,wParam,lParam);
	}
	return 0;
}
//-----------------------------------------------------------------------------------------

