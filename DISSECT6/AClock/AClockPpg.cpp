// AClockPpg.cpp : Implementation of the CAClockPropPage property page class.

#include "stdafx.h"
#include "AClock.h"
#include "AClockPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CAClockPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CAClockPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CAClockPropPage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CAClockPropPage, "ACLOCK.AClockPropPage.1",
	0x90814519, 0xc638, 0x4980, 0x9a, 0x47, 0x93, 0x46, 0x36, 0xa0, 0xe8, 0xa5)


/////////////////////////////////////////////////////////////////////////////
// CAClockPropPage::CAClockPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CAClockPropPage

BOOL CAClockPropPage::CAClockPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_ACLOCK_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CAClockPropPage::CAClockPropPage - Constructor

CAClockPropPage::CAClockPropPage() :
	COlePropertyPage(IDD, IDS_ACLOCK_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CAClockPropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CAClockPropPage::DoDataExchange - Moves data between page and properties

void CAClockPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CAClockPropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CAClockPropPage message handlers

