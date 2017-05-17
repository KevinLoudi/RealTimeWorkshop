// AlgorithmDlg.h : header file
//

#if !defined(AFX_ALGORITHMDLG_H__DB75C045_02F5_4058_A036_667D8A5833D6__INCLUDED_)
#define AFX_ALGORITHMDLG_H__DB75C045_02F5_4058_A036_667D8A5833D6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAlgorithmDlg dialog

#include "Algorithm.h"

class CAlgorithmDlg : public CDialog
{
// Construction
public:
	CAlgorithmDlg(CWnd* pParent = NULL);	// standard constructor

	//BinaryTree<CString> strTree;

// Dialog Data
	//{{AFX_DATA(CAlgorithmDlg)
	enum { IDD = IDD_ALGORITHM_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAlgorithmDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAlgorithmDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnUpdate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ALGORITHMDLG_H__DB75C045_02F5_4058_A036_667D8A5833D6__INCLUDED_)
