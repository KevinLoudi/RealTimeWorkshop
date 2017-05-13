// EditCtrlDlg.h : header file
//

#if !defined(AFX_EDITCTRLDLG_H__31306A0D_0C08_42BE_BD5D_266F043CE2E4__INCLUDED_)
#define AFX_EDITCTRLDLG_H__31306A0D_0C08_42BE_BD5D_266F043CE2E4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEditCtrlDlg dialog

class CEditCtrlDlg : public CDialog
{
// Construction
public:
	CEditCtrlDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CEditCtrlDlg)
	enum { IDD = IDD_EDITCTRL_DIALOG };
	CListBox	m_nameList;
	int		m_intValue;
	int		m_iSex;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditCtrlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEditCtrlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnSelchangeList();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITCTRLDLG_H__31306A0D_0C08_42BE_BD5D_266F043CE2E4__INCLUDED_)
