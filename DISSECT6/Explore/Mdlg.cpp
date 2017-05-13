// Mdlg.cpp : implementation file
//

#include "stdafx.h"
#include "Explore.h"
#include "Mdlg.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMdlg dialog


CMdlg::CMdlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMdlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMdlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMdlg, CDialog)
	//{{AFX_MSG_MAP(CMdlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMdlg message handlers

BOOL CMdlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CMenu* pSysMenu=GetSystemMenu(FALSE);
	if (pSysMenu!=NULL)
	{
		ASSERT((IDM_VER & 0XFFF0)==IDM_VER);
		ASSERT(IDM_VER<0XF000);
		pSysMenu->AppendMenu(MF_SEPARATOR);
		pSysMenu->AppendMenu(MF_STRING, IDM_VER, "Version (&V)");
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

//#include "Explore.h"
//class CAboutDlg;

void CMdlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID& 0xFFF0)==IDM_ABOUTBOX)
	{
		//CAboutDlg dlgAbout;
		//dlgAbout.DoModal();
	}
	else if(IDM_VER==(nID & 0xFFF0))
	{

		AfxMessageBox("Current version is 1.0.0");
	}
	else
	{
		CDialog::OnSysCommand(nID,lParam);
	}
}

