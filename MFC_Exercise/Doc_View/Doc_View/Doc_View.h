
// Doc_View.h : Doc_View Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CDoc_ViewApp:
// �йش����ʵ�֣������ Doc_View.cpp
//

class CDoc_ViewApp : public CWinAppEx
{
public:
	CDoc_ViewApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDoc_ViewApp theApp;
