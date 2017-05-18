// Threadte.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "windows.h"

DWORD WINAPI ThreadProc(LPVOID lpParameter);



int main(int argc, char* argv[])
{
	HANDLE hThread;
	hThread=CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);
	CloseHandle(hThread);

	while(1)
	{
		printf("Main thread is running....\n");
		Sleep(1000);
	}
	return 0;
}


DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
	while(1)
	{
		printf("Thread 1 is running....\n");
		Sleep(500);
	}

	return 0;
}