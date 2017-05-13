// EditCtrlDlg.cpp : implementation file
//

#include "stdafx.h"
#include "EditCtrl.h"
#include "EditCtrlDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditCtrlDlg dialog

CEditCtrlDlg::CEditCtrlDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEditCtrlDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEditCtrlDlg)
	m_intValue = 0;
	m_iSex = -1;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEditCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEditCtrlDlg)
	DDX_Control(pDX, IDC_LISTBOX, m_nameList);
	DDX_Text(pDX, IDC_NUMBER, m_intValue);
	DDV_MinMaxInt(pDX, m_intValue, 0, 100);
	DDX_Radio(pDX, IDC_GENDER1, m_iSex);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CEditCtrlDlg, CDialog)
	//{{AFX_MSG_MAP(CEditCtrlDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_LBN_SELCHANGE(IDC_LISTBOX, OnSelchangeList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditCtrlDlg message handlers

BOOL CEditCtrlDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	//Initialize list box
	int nItem=m_nameList.AddString("Kevin");
	m_nameList.SetItemData(nItem,3);
	nItem=m_nameList.AddString("Shirely");
	m_nameList.SetItemData(nItem,5);
	nItem=m_nameList.AddString("Dean");
	m_nameList.SetItemData(nItem,7);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CEditCtrlDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CEditCtrlDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CEditCtrlDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CEditCtrlDlg::OnOK() 
{
	// TODO: Add extra validation here
	CString strMess;
	UpdateData(TRUE); //update data related to control
	/*strMess.Format("The number you input is %d", m_intValue);
	AfxMessageBox(strMess);*/

	//check gener delection
	if (m_iSex==0)
	{
		strMess="Mr. XXX";
	}
	else if (m_iSex==1)
	{
		strMess="Ms. XXX";
	}
	else
	{
		strMess="Lady or Gental man";
	}

	//get hobby selection
	strMess+="I guess your hobbies include \n";
	CButton *pBtn=NULL;
	pBtn=(CButton*)GetDlgItem(IDC_HOBBY1);
	if (pBtn->GetCheck()!=NULL)
	{
		strMess+="Learning ";
	}

	pBtn=(CButton*)GetDlgItem(IDC_HOBBY2);
	if (pBtn->GetCheck()!=NULL)
	{
		strMess+="and Chatting ";
	}

	pBtn=(CButton*)GetDlgItem(IDC_HOBBY3);
	if (pBtn->GetCheck()!=NULL)
	{
		strMess+="and Gaming ";
	}

	AfxMessageBox(strMess);

	CDialog::OnOK();
}

void CEditCtrlDlg::OnSelchangeList() 
{
	// TODO: Add your control notification handler code here
	int nSel=m_nameList.GetCurSel();
	if (nSel!=-1)
	{
		CString strName;
		m_nameList.GetText(nSel,strName);
		UINT uID=m_nameList.GetItemData(nSel);

		CString strMess;
		strMess.Format("What you have selected is %s", strName);
		AfxMessageBox(strMess);
	}
	
}
