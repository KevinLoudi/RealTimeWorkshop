#pragma once


// CIODialog 对话框

class CIODialog : public CDialog
{
	DECLARE_DYNAMIC(CIODialog)

public:
	CIODialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CIODialog();

public:
	CString m_Edit_in;
	CString m_Edit_out;

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonIn();
	afx_msg void OnBnClickedButtonOut();
};
