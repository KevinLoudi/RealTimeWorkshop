#pragma once


// CmDialog �Ի���

class CmDialog : public CDialog
{
	DECLARE_DYNAMIC(CmDialog)

public:
	CmDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CmDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	void afx_msg OnOK(); //press-OK button event

	DECLARE_MESSAGE_MAP()
};
