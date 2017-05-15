// TreeCtrlDlg.h : header file
//

#if !defined(AFX_TREECTRLDLG_H__1044804E_E02F_472C_8924_97E5BC5B9EB9__INCLUDED_)
#define AFX_TREECTRLDLG_H__1044804E_E02F_472C_8924_97E5BC5B9EB9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTreeCtrlDlg dialog

class CTreeCtrlDlg : public CDialog
{
// Construction
public:
	CTreeCtrlDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTreeCtrlDlg)
	enum { IDD = IDD_TREECTRL_DIALOG };
	CTreeCtrl	m_treeArea;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTreeCtrlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTreeCtrlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TREECTRLDLG_H__1044804E_E02F_472C_8924_97E5BC5B9EB9__INCLUDED_)
