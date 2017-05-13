// PComboxView.cpp : implementation of the CPComboxView class
//

#include "stdafx.h"
#include "PCombox.h"

#include "PComboxDoc.h"
#include "PComboxView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPComboxView

IMPLEMENT_DYNCREATE(CPComboxView, CEditView)

BEGIN_MESSAGE_MAP(CPComboxView, CEditView)
	//{{AFX_MSG_MAP(CPComboxView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPComboxView construction/destruction

CPComboxView::CPComboxView()
{
	// TODO: add construction code here

}

CPComboxView::~CPComboxView()
{
}

BOOL CPComboxView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// Enable word-wrapping

	return bPreCreated;
}

/////////////////////////////////////////////////////////////////////////////
// CPComboxView drawing

void CPComboxView::OnDraw(CDC* pDC)
{
	CPComboxDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CPComboxView diagnostics

#ifdef _DEBUG
void CPComboxView::AssertValid() const
{
	CEditView::AssertValid();
}

void CPComboxView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CPComboxDoc* CPComboxView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPComboxDoc)));
	return (CPComboxDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPComboxView message handlers
