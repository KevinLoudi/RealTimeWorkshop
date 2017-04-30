// mThread.cpp : 实现文件
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
	// TODO: 在此执行任意逐线程初始化
	//create a window fream
	CmWnd *pFrameWnd=new CmWnd();
	pFrameWnd->Create(NULL,"Thread Window");
	pFrameWnd->ShowWindow(SW_SHOW);
	pFrameWnd->UpdateWindow();
	return TRUE;
}

int CmThread::ExitInstance()
{
	// TODO: 在此执行任意逐线程清理
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CmThread, CWinThread)
END_MESSAGE_MAP()


// CmThread 消息处理程序
