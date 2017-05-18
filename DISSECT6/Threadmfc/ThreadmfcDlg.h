// ThreadmfcDlg.h : header file
//

#if !defined(AFX_THREADMFCDLG_H__F2CBEB23_C3F3_4146_A2C1_183D449F8A5F__INCLUDED_)
#define AFX_THREADMFCDLG_H__F2CBEB23_C3F3_4146_A2C1_183D449F8A5F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CThreadmfcDlg dialog

class CThreadmfcDlg : public CDialog
{
// Construction
public:
	CThreadmfcDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CThreadmfcDlg)
	enum { IDD = IDD_THREADMFC_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThreadmfcDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CThreadmfcDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonShow();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THREADMFCDLG_H__F2CBEB23_C3F3_4146_A2C1_183D449F8A5F__INCLUDED_)
