#pragma once
#include "afxwin.h"


// CTypeDlg �Ի���

class CTypeDlg : public CDialog
{
	DECLARE_DYNAMIC(CTypeDlg)

public:
	CTypeDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTypeDlg();

// �Ի�������
	enum { IDD = IDD_TYPE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CEdit m_show;
	CEdit m_input;
	afx_msg void OnBnClickedUpdate();
	// //count of changed times
	int m_count;
	afx_msg void OnEnChangeInput();
	afx_msg void OnBnClickedOk();
	afx_msg BOOL OnInitDialog();

	afx_msg void OnBnClickedUpdate2();
	// number
	int m_num;
	// word of number
	CString m_note;
	// control of IDC_NUM
	CEdit m_Spinnum;
};
