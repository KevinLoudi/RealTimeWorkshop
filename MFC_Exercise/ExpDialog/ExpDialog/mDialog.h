#pragma once


// CmDialog 对话框

class CmDialog : public CDialog
{
	DECLARE_DYNAMIC(CmDialog)

public:
	CmDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CmDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	void afx_msg OnOK(); //press-OK button event

	DECLARE_MESSAGE_MAP()
};
