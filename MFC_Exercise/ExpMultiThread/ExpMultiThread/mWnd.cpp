// mWnd.cpp : 实现文件
//

#include "stdafx.h"
#include "ExpMultiThread.h"
#include "mWnd.h"


// CmWnd

IMPLEMENT_DYNCREATE(CmWnd, CFrameWnd)

CmWnd::CmWnd()
{

}

CmWnd::~CmWnd()
{
}


BEGIN_MESSAGE_MAP(CmWnd, CFrameWnd)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CmWnd 消息处理程序

void CmWnd::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	char* pMessage="This is a window thread";
	CWnd* pMainWnd=AfxGetMainWnd();
	::MessageBox(NULL,pMessage,"Thread Message! Verification!",MB_OK);
	CFrameWnd::OnLButtonDown(nFlags, point);
}
