#if !defined(AFX_ACLOCKPPG_H__59434F9D_32E4_46E3_A8FC_390F5904AA13__INCLUDED_)
#define AFX_ACLOCKPPG_H__59434F9D_32E4_46E3_A8FC_390F5904AA13__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// AClockPpg.h : Declaration of the CAClockPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CAClockPropPage : See AClockPpg.cpp.cpp for implementation.

class CAClockPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CAClockPropPage)
	DECLARE_OLECREATE_EX(CAClockPropPage)

// Constructor
public:
	CAClockPropPage();

// Dialog Data
	//{{AFX_DATA(CAClockPropPage)
	enum { IDD = IDD_PROPPAGE_ACLOCK };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CAClockPropPage)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ACLOCKPPG_H__59434F9D_32E4_46E3_A8FC_390F5904AA13__INCLUDED)
