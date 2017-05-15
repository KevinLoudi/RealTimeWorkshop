// AdvCtrlDlg.h : header file
//

#if !defined(AFX_ADVCTRLDLG_H__47F978CB_DA19_431B_9726_8AFE555100E8__INCLUDED_)
#define AFX_ADVCTRLDLG_H__47F978CB_DA19_431B_9726_8AFE555100E8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAdvCtrlDlg dialog

class CAdvCtrlDlg : public CDialog
{
// Construction
public:
	CAdvCtrlDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAdvCtrlDlg)
	enum { IDD = IDD_ADVCTRL_DIALOG };
	CListCtrl	m_listCtrl;
	CComboBox	m_ctrlCity;
	CListBox	m_listCity;
	CString	m_tempCity;
	CString	m_strHint;
	CString	m_strCity;
	CString	m_strNumber;
	CString	m_strName;
	CString	m_strPos;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdvCtrlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAdvCtrlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonDelete();
	afx_msg void OnSelchangeListCity();
	afx_msg void OnButtonEnter();
	afx_msg void OnSelchangeComboCity();
	afx_msg void OnButtonAdd1();
	afx_msg void OnButtonDel1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADVCTRLDLG_H__47F978CB_DA19_431B_9726_8AFE555100E8__INCLUDED_)
