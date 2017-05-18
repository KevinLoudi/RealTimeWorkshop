// WorkerThreadDlg.h : header file
//

#if !defined(AFX_WORKERTHREADDLG_H__ADE74AA6_6244_4708_96C0_23F3205E3D54__INCLUDED_)
#define AFX_WORKERTHREADDLG_H__ADE74AA6_6244_4708_96C0_23F3205E3D54__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWorkerThreadDlg dialog

typedef struct _progressInfo
{
	int time;
	CProgressCtrl* pPc;
}progressInfo;

UINT ThreadProc(LPVOID pParam);

class CWorkerThreadDlg : public CDialog
{
// Construction
public:
	CWorkerThreadDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CWorkerThreadDlg)
	enum { IDD = IDD_WORKERTHREAD_DIALOG };
	CProgressCtrl	m_progress;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWorkerThreadDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWorkerThreadDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonStart();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORKERTHREADDLG_H__ADE74AA6_6244_4708_96C0_23F3205E3D54__INCLUDED_)
