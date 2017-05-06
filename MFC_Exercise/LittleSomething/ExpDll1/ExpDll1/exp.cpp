#include <Windows.h>

BOOL APIENTRY DllMain( HANDLE hDllHandle, DWORD dwReason, LPVOID lpreserved )
{

}

int ShowHello(void)
{
	MessageBox(NULL,"Hello from exp dll!!","Info",MB_YESNO);
	return TRUE;
}