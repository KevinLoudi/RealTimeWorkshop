#pragma once


// CIODialog �Ի���

class CIODialog : public CDialog
{
	DECLARE_DYNAMIC(CIODialog)

public:
	CIODialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CIODialog();

public:
	CString m_Edit_in;
	CString m_Edit_out;

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonIn();
	afx_msg void OnBnClickedButtonOut();
};
