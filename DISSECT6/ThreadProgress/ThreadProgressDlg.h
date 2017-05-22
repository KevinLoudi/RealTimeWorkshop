// ThreadProgressDlg.h : header file
//

#if !defined(AFX_THREADPROGRESSDLG_H__F16431FC_C473_41E4_83E3_1D55565248A4__INCLUDED_)
#define AFX_THREADPROGRESSDLG_H__F16431FC_C473_41E4_83E3_1D55565248A4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CThreadProgressDlg dialog


class CThreadProgressDlg : public CDialog
{
// Construction
public:
	CThreadProgressDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CThreadProgressDlg)
	enum { IDD = IDD_THREADPROGRESS_DIALOG };
	CProgressCtrl	m_progress4;
	CProgressCtrl	m_progress3;
	CProgressCtrl	m_progress2;
	CProgressCtrl	m_progress1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThreadProgressDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CThreadProgressDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonStart();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THREADPROGRESSDLG_H__F16431FC_C473_41E4_83E3_1D55565248A4__INCLUDED_)
