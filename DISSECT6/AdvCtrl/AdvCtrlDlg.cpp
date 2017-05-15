// AdvCtrlDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AdvCtrl.h"
#include "AdvCtrlDlg.h"

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
// CAdvCtrlDlg dialog

CAdvCtrlDlg::CAdvCtrlDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAdvCtrlDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAdvCtrlDlg)
	m_tempCity = _T("");
	m_strHint = _T("");
	m_strCity = _T("");
	m_strNumber = _T("");
	m_strName = _T("");
	m_strPos = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAdvCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAdvCtrlDlg)
	DDX_Control(pDX, IDC_LIST_INFO, m_listCtrl);
	DDX_Control(pDX, IDC_COMBO_CITY, m_ctrlCity);
	DDX_Control(pDX, IDC_LIST_CITY, m_listCity);
	DDX_Text(pDX, IDC_CITY, m_tempCity);
	DDX_Text(pDX, IDC_EDIT_HINT, m_strHint);
	DDX_CBString(pDX, IDC_COMBO_CITY, m_strCity);
	DDX_Text(pDX, IDC_EDIT_NO, m_strNumber);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_POS, m_strPos);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAdvCtrlDlg, CDialog)
	//{{AFX_MSG_MAP(CAdvCtrlDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_LBN_SELCHANGE(IDC_LIST_CITY, OnSelchangeListCity)
	ON_BN_CLICKED(IDC_BUTTON_ENTER, OnButtonEnter)
	ON_CBN_SELCHANGE(IDC_COMBO_CITY, OnSelchangeComboCity)
	ON_BN_CLICKED(IDC_BUTTON_ADD1, OnButtonAdd1)
	ON_BN_CLICKED(IDC_BUTTON_DEL1, OnButtonDel1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAdvCtrlDlg message handlers

BOOL CAdvCtrlDlg::OnInitDialog()
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
	m_listCtrl.SetExtendedStyle(m_listCtrl.GetExtendedStyle()|LVS_EX_GRIDLINES);
	m_listCtrl.InsertColumn(0,"Number",LVCFMT_LEFT,70);
	m_listCtrl.InsertColumn(1,"Name",LVCFMT_LEFT,80);
	m_listCtrl.InsertColumn(2,"Position",LVCFMT_LEFT,100);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAdvCtrlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAdvCtrlDlg::OnPaint() 
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
HCURSOR CAdvCtrlDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CAdvCtrlDlg::OnButtonAdd() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE); //get control data

	m_listCity.AddString(m_tempCity);

	m_tempCity="";

	UpdateData(FALSE); //update control show

	GetDlgItem(IDC_CITY)->SetFocus(); //fot the convient for user input

	
}

void CAdvCtrlDlg::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
	//delete the seleced item
	int index;
	index=m_listCity.GetCurSel();
	m_listCity.DeleteString(index);
	
}

void CAdvCtrlDlg::OnSelchangeListCity() 
{
	// TODO: Add your control notification handler code here

	//response to user's selection
	int index;
	CString res="Your choice is ", str;
	index=m_listCity.GetCurSel();
	m_listCity.GetText(index,str);
	res+=str;
	AfxMessageBox(res);

	
	
}

void CAdvCtrlDlg::OnButtonEnter() 
{
	// TODO: Add your control notification handler code here
	if (m_strCity=="")
	{
		AfxMessageBox("Please select a city");
		GetDlgItem(IDC_COMBO_CITY)->SetFocus();
		return;
	}

	m_strHint="Welcom to ";
	m_strHint+=m_strCity;

	int index=m_ctrlCity.FindStringExact(-1,m_strCity);

	if (index==CB_ERR)
	{
		//if index value is CB_ERR(-1), No found
		m_ctrlCity.InsertString(0,m_strCity);
	} 
	else
	{
		//if has record, delete and re-insert
		m_ctrlCity.DeleteString(index);
		m_ctrlCity.InsertString(0, m_strCity);
	}

	m_strCity="";
	UpdateData(FALSE);
}

void CAdvCtrlDlg::OnSelchangeComboCity() 
{
	// TODO: Add your control notification handler code here
	int index=m_ctrlCity.GetCurSel();

	//get string
	m_ctrlCity.GetLBText(index,m_strCity);

	m_ctrlCity.DeleteString(index);
	m_ctrlCity.InsertString(0,m_strCity);

	m_strHint="Welcom you again to ";
	m_strHint+=m_strCity;
	UpdateData(FALSE);
}

void CAdvCtrlDlg::OnButtonAdd1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	if (m_strNumber=="")
	{
		AfxMessageBox("Cannot assign empty number");
		return;
	}
	
	int iCount=m_listCtrl.GetItemCount();
	m_listCtrl.InsertItem(iCount,m_strNumber);
	m_listCtrl.SetItemText(iCount,1,m_strName);
	m_listCtrl.SetItemText(iCount,2,m_strPos);

	//reset
	m_strNumber="";
	m_strName="";
	m_strPos="";

	//Set focus
	GetDlgItem(IDC_EDIT_NO)->SetFocus();

	UpdateData(FALSE);
}

void CAdvCtrlDlg::OnButtonDel1() 
{
	// TODO: Add your control notification handler code here
	int index=m_listCtrl.GetNextItem(-1, LVNI_SELECTED);
	m_listCtrl.DeleteItem(index);
}
