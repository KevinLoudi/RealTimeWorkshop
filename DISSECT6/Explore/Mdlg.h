#if !defined(AFX_MDLG_H__F96AEB9B_CF3B_4F16_A5CB_A6F2F710ED71__INCLUDED_)
#define AFX_MDLG_H__F96AEB9B_CF3B_4F16_A5CB_A6F2F710ED71__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Mdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMdlg dialog

class CMdlg : public CDialog
{
// Construction
public:
	CMdlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMdlg)
	enum { IDD = IDD_MDIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMdlg)
	virtual BOOL OnInitDialog();
	virtual void OnSysCommand(UINT nID, LPARAM lParam);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MDLG_H__F96AEB9B_CF3B_4F16_A5CB_A6F2F710ED71__INCLUDED_)
