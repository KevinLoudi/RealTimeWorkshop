#pragma once


// CmWnd 框架

class CmWnd : public CFrameWnd
{
	DECLARE_DYNCREATE(CmWnd)
protected:
	//CmWnd();           // 动态创建所使用的受保护的构造函数
	virtual ~CmWnd();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	CmWnd();
};


