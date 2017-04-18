/*
 Propose: Reinvent message map macro
 Author: Kevin
 Date: 18th April, 2017
 Environment: Visual C++ 2008
*/
#include<windows.h>

//global variables
HINSTANCE		hInst;	
HWND 			hWnd;		
MSG			msg;
char lpszClassName [ ]="Window";
char*ShowText;

ATOM			MyRegisterClass(HINSTANCE hInstance);//register window
BOOL			Create(HINSTANCE, int);  //initalize program
int				    Run( );                  //message loop

LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM); //window process
 						
void OnLButtonDown(			// WM_LBUTTONDOWN message handling
HWND hWnd, 
UINT message, 
		WPARAM wParam, 
LPARAM lParam);

void OnPaint(					// WM_PAINT message handling
HWND hWnd, 
UINT message, 
		WPARAM wParam, 
LPARAM lParam);

void OnDestroy(				// WM_DESTROY message handling
HWND hWnd, 
UINT message, 
		WPARAM wParam, 
LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	MyRegisterClass(hInstance);        	//define and register window class
	Create(hInstance, nCmdShow);  		//create window
	ShowWindow(hWnd, nCmdShow);   	//show window
	UpdateWindow(hWnd);            	//update screen 
	return Run();                     	//enter message loop
}

int Run( )
{
	while (GetMessage(&msg, NULL, 0, 0)) 
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

//**********window frame related
ATOM MyRegisterClass(HINSTANCE hInstance)
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

BOOL Create(HINSTANCE hInstance, int nCmdShow)
{
	hWnd=CreateWindow(	lpszClassName,
						"Windows",
						WS_OVERLAPPEDWINDOW,
						400,300,180,160,
						NULL,
						NULL,
						hInstance,
						NULL);
   return TRUE;
}

//**********message type related
//messaging handling
void On_LButtonDown(HWND, UINT, WPARAM, LPARAM);
void On_RButtonDown(HWND, UINT, WPARAM, LPARAM);
void On_Paint(HWND, UINT, WPARAM, LPARAM);
void On_Destroy(HWND, UINT, WPARAM, LPARAM);

//message map marco
#define DECLARE_MESSAGE_MAP()\
	struct MSGMAP_ENTRY _messageEntres[];\

#define BEGIN_MESSAGE_MAP()\
	struct MSGMAP_ENTRY _messageEntres[]=\
{\

#define ON_WM(messageID, msgFuc)\
	messageID, msgFuc,
#define END_MESSAGE_MAP()\
};\

//message map
struct MSGMAP_ENTRY
{
	UINT nMessage;
	void (*pfn)(HWND,UINT,WPARAM,LPARAM);
};

//create message map through marco
DECLARE_MESSAGE_MAP()
BEGIN_MESSAGE_MAP()
	ON_WM(WM_LBUTTONDOWN,On_LButtonDown)
	ON_WM(WM_PAINT,On_Paint)
	ON_WM(WM_DESTROY,On_Destroy)
END_MESSAGE_MAP()

//implement message handling
void On_LButtonDown(HWND hWnd, UINT message, 
				WPARAM wParam, LPARAM lParam)
{
	ShowText="Hello!";
	InvalidateRect(hWnd,NULL,1); //create a WM_PAINT message
}

void On_RButtonDown(HWND hWnd, UINT message, 
					WPARAM wParam, LPARAM lParam)
{
	ShowText="Wordl!";
	PAINTSTRUCT ps;
	HDC hdc;
	hdc=BeginPaint(hWnd, &ps)

}

void On_Paint(HWND hWnd, UINT message, 
				WPARAM wParam, LPARAM lParam)
{
   PAINTSTRUCT ps;//structure contains information that can be used to paint the client area of a window
   HDC hdc; //Handle to a device context (DC).
   //do paint in a cilent area
   hdc=BeginPaint(hWnd,&ps);
   TextOut(hdc,50,50,ShowText,6);
   EndPaint(hWnd,&ps);
}

//destroy window
void On_Destroy(HWND hWnd, UINT message, 
				WPARAM wParam, LPARAM lParam)
{
	PostQuitMessage(0);
}

//******window process
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, 
WPARAM wParam, LPARAM lParam)
{
	int n=sizeof(_messageEntres)/sizeof(_messageEntres[0]);
	for(int i=0; i<n; ++i)
	{
		if(message==_messageEntres[i].nMessage)
			(*_messageEntres[i].pfn)(hWnd,message, wParam, lParam);
	}

	return DefWindowProc(hWnd,message, wParam, lParam);
};