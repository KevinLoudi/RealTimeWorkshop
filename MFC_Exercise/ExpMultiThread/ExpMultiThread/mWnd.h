#pragma once


// CmWnd ���

class CmWnd : public CFrameWnd
{
	DECLARE_DYNCREATE(CmWnd)
protected:
	//CmWnd();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CmWnd();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	CmWnd();
};


