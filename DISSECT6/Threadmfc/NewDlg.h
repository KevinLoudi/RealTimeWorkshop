#if !defined(AFX_NEWDLG_H__C7D8F386_DF69_4374_9FAF_BBD06BC5D983__INCLUDED_)
#define AFX_NEWDLG_H__C7D8F386_DF69_4374_9FAF_BBD06BC5D983__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NewDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNewDlg dialog

class CNewDlg : public CDialog
{
// Construction
	//DECLARE_DYNAMIC(CNewDlg)
public:
	CNewDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNewDlg)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNewDlg)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWDLG_H__C7D8F386_DF69_4374_9FAF_BBD06BC5D983__INCLUDED_)
