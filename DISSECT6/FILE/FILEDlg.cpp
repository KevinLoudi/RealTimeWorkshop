// FILEDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FILE.h"
#include "FILEDlg.h"

//IO File stream
#include "string"
#include "fstream"
using namespace std;

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
// CFILEDlg dialog

CFILEDlg::CFILEDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFILEDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFILEDlg)
	m_strText = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFILEDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFILEDlg)
	DDX_Text(pDX, IDC_EDIT_TEXT, m_strText);
	DDV_MaxChars(pDX, m_strText, 1000);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFILEDlg, CDialog)
	//{{AFX_MSG_MAP(CFILEDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_READ, OnButtonRead)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, OnButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_I, OnButtonI)
	ON_BN_CLICKED(IDC_BUTTON_O, OnButtonO)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFILEDlg message handlers

BOOL CFILEDlg::OnInitDialog()
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

void CFILEDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFILEDlg::OnPaint() 
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
HCURSOR CFILEDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFILEDlg::OnButtonRead() 
{
	// TODO: Add your control notification handler code here
	FILE *fp=NULL;

	fp=fopen(TMPFILE,"rb");

	if (fp==NULL)
	{
		AfxMessageBox("File open failed");
		return;
	}

	char str[1000];
	memset(str, 0, sizeof(str)); //reserve memory
	fread(str,sizeof(str),1,fp); //read

	m_strText=str;

	fclose(fp);
	UpdateData(FALSE);

	
}

void CFILEDlg::OnButtonSave() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	
	FILE *fp=NULL;
	fp=fopen(TMPFILE,
		"wb");
	
	if (fp==NULL)
	{
		AfxMessageBox("File open failed");
		return;
	}
	
	//get text from text editor
	char* str=m_strText.GetBuffer(m_strText.GetLength());

	if (fwrite(str,m_strText.GetLength(),1,fp)!=1)
	{
		AfxMessageBox("File write failed");
		return;
	}

	fclose(fp);
	

	
}

void CFILEDlg::OnButtonI() 
{
	// TODO: Add your control notification handler code here
	//C++ style
	fstream file;

	file.open(TMPFILE,ios::in);

	string str;

	file>>str;

	m_strText.Format("%s",str.c_str());

	file.close();

	UpdateData(FALSE);

	
}

void CFILEDlg::OnButtonO() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	string str(m_strText.GetBuffer(m_strText.GetLength()));

	fstream file;

	file.open(TMPFILE, ios::out);

	file<<str;

	file.close();
	
}
