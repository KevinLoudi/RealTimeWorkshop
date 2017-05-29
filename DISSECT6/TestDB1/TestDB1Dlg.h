// TestDB1Dlg.h : header file
//

#if !defined(AFX_TESTDB1DLG_H__25FC7931_11D4_40B2_8A03_43877078DB5F__INCLUDED_)
#define AFX_TESTDB1DLG_H__25FC7931_11D4_40B2_8A03_43877078DB5F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTestDB1Dlg dialog
#include "MAccess.h"

class CTestDB1Dlg : public CDialog
{
// Construction
public:
	CTestDB1Dlg(CWnd* pParent = NULL);	// standard constructor

	MAccess m_meAccess1;

// Dialog Data
	//{{AFX_DATA(CTestDB1Dlg)
	enum { IDD = IDD_TESTDB1_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestDB1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTestDB1Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTDB1DLG_H__25FC7931_11D4_40B2_8A03_43877078DB5F__INCLUDED_)
