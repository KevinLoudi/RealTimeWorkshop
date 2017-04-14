/*
 Propose: Demo the WND class and create multiply windows
 Author: Kevin
 Date: 14th April, 2017
 Environment: Visual C++ 2008
*/

#include <windows.h>

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);

int InitialWnd(WNDCLASS&, char[], int, HINSTANCE);

//main function
int WINAPI WinMain(HINSTANCE hInstance,
				   HINSTANCE PreInstance,
				   LPSTR lpCmdLine,
				   int nCmdShow)
{
	HWND hwnd1, hwnd2, hwnd3;

	MSG msg;

	//define three window-class and create three correspond window
	WNDCLASS wc1;  InitialWnd(wc1,"WND1",0,hInstance); 

	hwnd1=CreateWindow(	"WND1",	
						"Windows1",
						WS_OVERLAPPEDWINDOW,
						120,50,700,500,
						NULL,
						NULL,
						hInstance,
						NULL);

	WNDCLASS wc2;  InitialWnd(wc2,"WND2",0,hInstance);
	hwnd2=CreateWindow(	"WND2",	
						"Windows2",
						WS_OVERLAPPEDWINDOW,
						150,80,750,550,
						NULL,
						NULL,
						hInstance,
						NULL);

	WNDCLASS wc3;  InitialWnd(wc3,"WND3",0,hInstance);
	hwnd3=CreateWindow(	"WND3",	
						"Windows3",
						WS_OVERLAPPEDWINDOW,
						200,130,500,300,
						NULL,
						NULL,
						hInstance,
						NULL);

	//show window and update screen
	ShowWindow(hwnd1,nCmdShow);		
	UpdateWindow(hwnd1);

	ShowWindow(hwnd2,nCmdShow);		
	UpdateWindow(hwnd2);

	ShowWindow(hwnd3,nCmdShow);		
	UpdateWindow(hwnd3);

	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

//message handling
LRESULT CALLBACK WndProc(HWND hwnd,
						 UINT message,
						 WPARAM wParam,
						 LPARAM lParam)
{
	switch(message)
	{
	case WM_LBUTTONDOWN:
		{
			MessageBeep(0);
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

//inital wnd class
int InitialWnd(WNDCLASS& wc, char ClassName[], int TypeCode,HINSTANCE hInstance)
{
	if(TypeCode==0)
	{
		wc.style=0;
		wc.lpfnWndProc=WndProc;
		wc.cbClsExtra=0;
		wc.cbWndExtra=0;
		wc.hInstance=hInstance;
		wc.hIcon=LoadIcon(NULL,IDI_APPLICATION);
		wc.hCursor=LoadCursor(NULL,IDC_ARROW);
		wc.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);//°×É«
		wc.lpszMenuName=NULL;
		wc.lpszClassName=ClassName;
	}
	else
	{ 
		//not define this type
		return 0;
	}
	
	RegisterClass(&wc);
	return 1;
}