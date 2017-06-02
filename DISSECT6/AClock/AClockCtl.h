#if !defined(AFX_ACLOCKCTL_H__9EB709DB_288A_45BE_A186_4D6DB5DBEC4C__INCLUDED_)
#define AFX_ACLOCKCTL_H__9EB709DB_288A_45BE_A186_4D6DB5DBEC4C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// AClockCtl.h : Declaration of the CAClockCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CAClockCtrl : See AClockCtl.cpp for implementation.

class CAClockCtrl : public COleControl
{
	DECLARE_DYNCREATE(CAClockCtrl)

// Constructor
public:
	CAClockCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAClockCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// Implementation
protected:
	~CAClockCtrl();

	DECLARE_OLECREATE_EX(CAClockCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CAClockCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CAClockCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CAClockCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CAClockCtrl)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CAClockCtrl)
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CAClockCtrl)
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CAClockCtrl)
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ACLOCKCTL_H__9EB709DB_288A_45BE_A186_4D6DB5DBEC4C__INCLUDED)
