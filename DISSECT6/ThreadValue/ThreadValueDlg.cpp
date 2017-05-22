// ThreadValueDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ThreadValue.h"
#include "ThreadValueDlg.h"

#include "Afxmt.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

char str[11];
CCriticalSection crSec;
CEvent evtObj;
CMutex mutex;

UINT ThreadProc1_(LPVOID lpParameter)
{
	Sleep(1);
	//crSec.Lock();
	//evtObj.Lock();
	mutex.Lock();

	for (int i=0; i<10; ++i)
	{
		Sleep(1);
		str[i]='1';
	}
	str[10]='\0';
	//crSec.Unlock();
	mutex.Unlock();
	return 0;
}

UINT ThreadProc2_(LPVOID lpParameter)
{
	//crSec.Lock();
	//evtObj.Lock();
	mutex.Lock();
	for (int i=9; i>=0; --i)
	{
		Sleep(1);
		str[i]='0';
	}
	str[10]='\0';
	//crSec.Unlock();
	mutex.Unlock();
	return 0;
}

//////////////////////////////////////////////////////////////////////////
CSemaphore semaphore(2,2);

UINT Thread1(LPVOID pParam)
{
	semaphore.Lock();
	AfxMessageBox("Thread 1 is running");
	semaphore.Unlock();
	return 0;
}

UINT Thread2(LPVOID pParam)
{
	semaphore.Lock();
	AfxMessageBox("Thread 2 is running");
	semaphore.Unlock();
	return 0;
}

UINT Thread3(LPVOID pParam)
{
	semaphore.Lock();
	AfxMessageBox("Thread 3 is running");
	semaphore.Unlock();
	return 0;
}

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
// CThreadValueDlg dialog

CThreadValueDlg::CThreadValueDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CThreadValueDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CThreadValueDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CThreadValueDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CThreadValueDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CThreadValueDlg, CDialog)
	//{{AFX_MSG_MAP(CThreadValueDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ASS, OnButtonAss)
	ON_BN_CLICKED(IDC_BUTTON_LOOK, OnButtonLook)
	ON_BN_CLICKED(IDC_BUTTON_RELEASE, OnButtonRelease)
	ON_BN_CLICKED(IDC_BUTTON_RUN, OnButtonRun)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CThreadValueDlg message handlers

BOOL CThreadValueDlg::OnInitDialog()
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

void CThreadValueDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CThreadValueDlg::OnPaint() 
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
HCURSOR CThreadValueDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CThreadValueDlg::OnButtonAss() 
{
	// TODO: Add your control notification handler code here
	AfxBeginThread(ThreadProc1_, NULL);
	AfxBeginThread(ThreadProc2_, NULL);
	
}

void CThreadValueDlg::OnButtonLook() 
{
	// TODO: Add your control notification handler code here
	CString cstr;
	cstr.Format("%s",str);
	AfxMessageBox(cstr);
	
}

void CThreadValueDlg::OnButtonRelease() 
{
	// TODO: Add your control notification handler code here
	evtObj.SetEvent();
	
}

void CThreadValueDlg::OnButtonRun() 
{
	// TODO: Add your control notification handler code here
	AfxBeginThread(Thread1, NULL);
	AfxBeginThread(Thread2, NULL);
	AfxBeginThread(Thread3, NULL);
}
