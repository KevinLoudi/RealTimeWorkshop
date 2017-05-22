// ThreadValueDlg.h : header file
//

#if !defined(AFX_THREADVALUEDLG_H__53BF7D2F_029E_4812_8159_E3D53CE776B2__INCLUDED_)
#define AFX_THREADVALUEDLG_H__53BF7D2F_029E_4812_8159_E3D53CE776B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CThreadValueDlg dialog



class CThreadValueDlg : public CDialog
{
// Construction
public:
	CThreadValueDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CThreadValueDlg)
	enum { IDD = IDD_THREADVALUE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThreadValueDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CThreadValueDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonAss();
	afx_msg void OnButtonLook();
	afx_msg void OnButtonRelease();
	afx_msg void OnButtonRun();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THREADVALUEDLG_H__53BF7D2F_029E_4812_8159_E3D53CE776B2__INCLUDED_)
