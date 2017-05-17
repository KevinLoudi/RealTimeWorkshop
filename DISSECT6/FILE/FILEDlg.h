// FILEDlg.h : header file
//

#if !defined(AFX_FILEDLG_H__175C7673_7DB3_41FB_9371_AA42134B98A2__INCLUDED_)
#define AFX_FILEDLG_H__175C7673_7DB3_41FB_9371_AA42134B98A2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFILEDlg dialog
#define TMPFILE "d:\\test.txt"
#define TMPDATA "d:\\test.dat"


class CFILEDlg : public CDialog
{
// Construction
public:
	CFILEDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFILEDlg)
	enum { IDD = IDD_FILE_DIALOG };
	CString	m_strText;
	CString	m_strMajor;
	CString	m_strName;
	CString	m_strNumber;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFILEDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFILEDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonRead();
	afx_msg void OnButtonSave();
	afx_msg void OnButtonI();
	afx_msg void OnButtonO();
	afx_msg void OnButtonMfco();
	afx_msg void OnButtonMfci();
	afx_msg void OnButtonEmpty();
	afx_msg void OnButtonSysi();
	afx_msg void OnButtonSyso();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEDLG_H__175C7673_7DB3_41FB_9371_AA42134B98A2__INCLUDED_)
