// mThread.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ExpMultiThread.h"
#include "mThread.h"


// CmThread

IMPLEMENT_DYNCREATE(CmThread, CWinThread)

CmThread::CmThread()
{
}

CmThread::~CmThread()
{
}

BOOL CmThread::InitInstance()
{
	// TODO: �ڴ�ִ���������̳߳�ʼ��
	//create a window fream
	CmWnd *pFrameWnd=new CmWnd();
	pFrameWnd->Create(NULL,"Thread Window");
	pFrameWnd->ShowWindow(SW_SHOW);
	pFrameWnd->UpdateWindow();
	return TRUE;
}

int CmThread::ExitInstance()
{
	// TODO: �ڴ�ִ���������߳�����
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CmThread, CWinThread)
END_MESSAGE_MAP()


// CmThread ��Ϣ�������
