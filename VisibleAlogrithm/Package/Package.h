// Package.h : Package DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CPackageApp
// �йش���ʵ�ֵ���Ϣ������� Package.cpp
//

class CPackageApp : public CWinApp
{
public:
	CPackageApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
