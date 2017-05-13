// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "PCombox.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	ON_CBN_SELCHANGE(IDC_MCOMBOX, OnSelChangeCombo)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}


int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	//ZGY
	//get toolbar information
	CToolBarCtrl& toolCtrl=m_wndToolBar.GetToolBarCtrl();
	int iCount=toolCtrl.GetButtonCount();
	m_wndToolBar.SetButtonInfo(iCount-1, ID_SEPARATOR, TBBS_SEPARATOR,100);

	//calculate the size of combox
	CRect r;
	m_wndToolBar.GetItemRect(iCount-1,&r);
	r.bottom=r.top+120;

	//create combox
	if (!m_comBox.Create(CBS_DROPDOWN|WS_VISIBLE|WS_VSCROLL|CBS_AUTOHSCROLL,
		r,&m_wndToolBar,IDC_MCOMBOX))
	{
		AfxMessageBox("Fail to create comboBox");
	}
	else
	{
		//add items to the combox
		m_comBox.AddString("China");
		m_comBox.AddString("England");
	}

	m_comBox.SetCurSel(1);

	return 0;
}

void CMainFrame::OnSelChangeCombo()
{

	//show the current selected item in message box
	int nSel=m_comBox.GetCurSel();
	CString strMess;
	strMess.Format("Select %d",nSel+1);
	AfxMessageBox(strMess);
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

