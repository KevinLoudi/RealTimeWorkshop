// mWnd.cpp : ʵ���ļ�
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


// CmWnd ��Ϣ�������

void CmWnd::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	char* pMessage="This is a window thread";
	CWnd* pMainWnd=AfxGetMainWnd();
	::MessageBox(NULL,pMessage,"Thread Message! Verification!",MB_OK);
	CFrameWnd::OnLButtonDown(nFlags, point);
}
