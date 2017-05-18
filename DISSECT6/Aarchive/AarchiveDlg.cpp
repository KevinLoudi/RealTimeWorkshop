// AarchiveDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Aarchive.h"
#include "AarchiveDlg.h"

#include "WorkerInfo.h"

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
// CAarchiveDlg dialog

CAarchiveDlg::CAarchiveDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAarchiveDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAarchiveDlg)
	m_strName = _T("");
	m_strJnum = _T("");
	m_uintPay = 0;
	m_strPos = _T("");
	m_strRemark = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAarchiveDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAarchiveDlg)
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_NUM, m_strJnum);
	DDX_Text(pDX, IDC_EDIT_PAY, m_uintPay);
	DDX_Text(pDX, IDC_EDIT_POS, m_strPos);
	DDX_Text(pDX, IDC_EDIT_REMARK, m_strRemark);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAarchiveDlg, CDialog)
	//{{AFX_MSG_MAP(CAarchiveDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_READ, OnButtonRead)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, OnButtonSave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAarchiveDlg message handlers

BOOL CAarchiveDlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAarchiveDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAarchiveDlg::OnPaint() 
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
HCURSOR CAarchiveDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CAarchiveDlg::OnButtonRead() 
{
	// TODO: Add your control notification handler code here
	CFile file(TMPTEXT, CFile::modeRead);

	CArchive ar(&file,CArchive::load);

	Serialize(ar);

	//in the same order with save
	//ar>>m_strName>>m_strJnum>>m_strPos>>m_uintPay>>m_strRemark;
	/*CWorkerInfo* wrInfo;
	ar>>wrInfo;
	wrInfo->ReadInfo(m_strName,m_strJnum,
		m_uintPay,m_strPos,m_strRemark);*/

	UpdateData(FALSE);
	
}

void CAarchiveDlg::OnButtonSave() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	
	//file object
	CFile file(TMPTEXT, CFile::modeCreate|CFile::modeWrite);
	
	//archive object
	CArchive ar(&file, CArchive::store);

	Serialize(ar);
	
	//save in the file
	//ar<<m_strName<<m_strJnum<<m_strPos<<m_uintPay<<m_strRemark;
	/*CWorkerInfo wrInfo;
	wrInfo.SaveInfo(m_strName,m_strJnum,m_uintPay,m_strPos,
		m_strRemark);

	ar<<&wrInfo;*/
	
}
