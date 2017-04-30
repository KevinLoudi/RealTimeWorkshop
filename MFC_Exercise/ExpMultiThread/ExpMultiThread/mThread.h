#pragma once
#include "mWnd.h"

// CmThread

class CmThread : public CWinThread
{
	DECLARE_DYNCREATE(CmThread)

protected:
	CmThread();           // 动态创建所使用的受保护的构造函数
	virtual ~CmThread();

public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

protected:
	DECLARE_MESSAGE_MAP()
};


