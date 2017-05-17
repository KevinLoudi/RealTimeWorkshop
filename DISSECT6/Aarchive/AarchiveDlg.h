// AarchiveDlg.h : header file
//

#if !defined(AFX_AARCHIVEDLG_H__C436907B_B1CB_406F_91AF_4BC0ECBBD757__INCLUDED_)
#define AFX_AARCHIVEDLG_H__C436907B_B1CB_406F_91AF_4BC0ECBBD757__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAarchiveDlg dialog
#define TMPTEXT "d:\\test.txt"

class CAarchiveDlg : public CDialog
{
// Construction
public:
	CAarchiveDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAarchiveDlg)
	enum { IDD = IDD_AARCHIVE_DIALOG };
	CString	m_strName;
	CString	m_strJnum;
	UINT	m_uintPay;
	CString	m_strPos;
	CString	m_strRemark;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAarchiveDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAarchiveDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonRead();
	afx_msg void OnButtonSave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AARCHIVEDLG_H__C436907B_B1CB_406F_91AF_4BC0ECBBD757__INCLUDED_)
