// Threadte.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "windows.h"

DWORD WINAPI ThreadProc(LPVOID lpParameter);

DWORD WINAPI ThreadProc1(LPVOID lpParameter);
DWORD WINAPI ThreadProc2(LPVOID lpParameter);

int tickets=20;
HANDLE hMutex;


int main(int argc, char* argv[])
{
	HANDLE hThread1,hThread2;
	//hThread=CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);
	hThread1=CreateThread(NULL, 0, ThreadProc1, NULL, 0, NULL);
	hThread2=CreateThread(NULL, 0, ThreadProc2, NULL, 0, NULL);

	CloseHandle(hThread1);
	CloseHandle(hThread2);

	hMutex=CreateMutex(NULL,FALSE,"Shop");

	while (tickets>0)
	{
		WaitForSingleObject(hMutex,INFINITE);
		if (tickets>0)
		{
			Sleep(10);
			printf("Tread main sales the %d ticket...\n", tickets--);
		} 
		else
		{
			break;
		}
		ReleaseMutex(hMutex);
		
	}
	CloseHandle(hMutex);
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

DWORD WINAPI ThreadProc1(LPVOID lpParameter)
{
	WaitForSingleObject(hMutex,INFINITE);
	while (tickets>0)
	{
		if (tickets>0)
		{
			Sleep(10);
			printf("Tread 1 sales the %d ticket...\n", tickets--);
		} 
		else
		{
			break;	
		}
		ReleaseMutex(hMutex);

	}

	return 0;
	
}

DWORD WINAPI ThreadProc2(LPVOID lpParameter)
{
	WaitForSingleObject(hMutex,INFINITE);
	while (tickets>0)
	{
		if (tickets>0)
		{
			Sleep(10);
			printf("Tread 2 sales the %d ticket...\n", tickets--);
		} 
		else
		{
			break;
			
		}
		ReleaseMutex(hMutex);
	}

	return 0;
	
}