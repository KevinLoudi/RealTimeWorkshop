#pragma once
#include "mWnd.h"

// CmThread

class CmThread : public CWinThread
{
	DECLARE_DYNCREATE(CmThread)

protected:
	CmThread();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CmThread();

public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

protected:
	DECLARE_MESSAGE_MAP()
};


