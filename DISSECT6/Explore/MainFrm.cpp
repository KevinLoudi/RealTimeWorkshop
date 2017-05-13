// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Explore.h"

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
	ON_WM_CREATE()
	ON_NOTIFY(TBN_DROPDOWN,AFX_IDW_TOOLBAR,OnToolbarDropDown)
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

	//enable toolbar upside arrow
	DWORD dwExStyle=TBSTYLE_EX_DRAWDDARROWS;
	m_wndToolBar.GetToolBarCtrl().SendMessage(TB_SETEXTENDEDSTYLE,0,(LPARAM)dwExStyle);

	//add downside arrow on "Open" meun
	DWORD dwStyle=m_wndToolBar.GetButtonStyle(m_wndToolBar.CommandToIndex(ID_FILE_OPEN));
	dwStyle|=TBSTYLE_DROPDOWN;
	m_wndToolBar.SetButtonStyle(m_wndToolBar.CommandToIndex(ID_FILE_OPEN),dwStyle);

	return 0;
}

void CMainFrame::OnToolbarDropDown(NMTOOLBAR* pnmh, LRESULT* plRes)
{
	if (ID_FILE_OPEN==pnmh->iItem)
	{
		//get current meun item
		CMenu menu;
		menu.LoadMenu(IDR_OPEN_MENU);
		CMenu* pPopup=menu.GetSubMenu(0);
		ASSERT(pPopup);

		//get button position
		CRect r;
		m_wndToolBar.SendMessage(TB_GETRECT,pnmh->iItem, (LPARAM)&r);
		m_wndToolBar.ClientToScreen(&r);

		//set popup menu
		pPopup->TrackPopupMenu(TPM_LEFTALIGN|TPM_LEFTBUTTON|TPM_VERTICAL,
			r.left,r.bottom,this, &r);
		
	}
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

