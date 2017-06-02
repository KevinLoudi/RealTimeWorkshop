// AClockCtl.cpp : Implementation of the CAClockCtrl ActiveX Control class.

#include "stdafx.h"
#include "AClock.h"
#include "AClockCtl.h"
#include "AClockPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CAClockCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CAClockCtrl, COleControl)
	//{{AFX_MSG_MAP(CAClockCtrl)
	ON_WM_TIMER()
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CAClockCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CAClockCtrl)
	DISP_STOCKPROP_BACKCOLOR()
	DISP_STOCKPROP_FORECOLOR()
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CAClockCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CAClockCtrl, COleControl)
	//{{AFX_EVENT_MAP(CAClockCtrl)
	// NOTE - ClassWizard will add and remove event map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CAClockCtrl, 1)
	PROPPAGEID(CAClockPropPage::guid)
END_PROPPAGEIDS(CAClockCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CAClockCtrl, "ACLOCK.AClockCtrl.1",
	0x87c61453, 0x9feb, 0x4d16, 0xa9, 0x2f, 0x41, 0xf5, 0xde, 0x4e, 0x6c, 0x87)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CAClockCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DAClock =
		{ 0xf36a090d, 0x45bc, 0x408a, { 0x8b, 0xc7, 0x1d, 0xf0, 0x44, 0x1, 0x3b, 0xbe } };
const IID BASED_CODE IID_DAClockEvents =
		{ 0xebe0f905, 0xc451, 0x4076, { 0x9d, 0xc8, 0x38, 0x7d, 0xc3, 0xd1, 0x44, 0xeb } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwAClockOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CAClockCtrl, IDS_ACLOCK, _dwAClockOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CAClockCtrl::CAClockCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CAClockCtrl

BOOL CAClockCtrl::CAClockCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_ACLOCK,
			IDB_ACLOCK,
			afxRegApartmentThreading,
			_dwAClockOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CAClockCtrl::CAClockCtrl - Constructor

CAClockCtrl::CAClockCtrl()
{
	InitializeIIDs(&IID_DAClock, &IID_DAClockEvents);

	// TODO: Initialize your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CAClockCtrl::~CAClockCtrl - Destructor

CAClockCtrl::~CAClockCtrl()
{
	// TODO: Cleanup your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CAClockCtrl::OnDraw - Drawing function

void CAClockCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	// TODO: Replace the following code with your own drawing code.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);

	//set color
	CBrush brush(TranslateColor(GetBackColor()));
	pdc->FillRect(rcBounds, &brush);
	pdc->SetTextColor(TranslateColor(GetForeColor()));

	CTime time=CTime::GetCurrentTime();
	CString str=time.Format("%H: %M :%S");
	pdc->TextOut(0,0,str);
}


/////////////////////////////////////////////////////////////////////////////
// CAClockCtrl::DoPropExchange - Persistence support

void CAClockCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.

}


/////////////////////////////////////////////////////////////////////////////
// CAClockCtrl::OnResetState - Reset control to default state

void CAClockCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// CAClockCtrl::AboutBox - Display an "About" box to the user

void CAClockCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_ACLOCK);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CAClockCtrl message handlers

void CAClockCtrl::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	InvalidateControl(NULL); //update control show	
	COleControl::OnTimer(nIDEvent);
}



int CAClockCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	SetTimer(1,1000,NULL); //set up a timer, trigged every 1sec
	
	return 0;
}
