// ExploreView.cpp : implementation of the CExploreView class
//

#include "stdafx.h"
#include "Explore.h"

#include "ExploreDoc.h"
#include "ExploreView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExploreView

IMPLEMENT_DYNCREATE(CExploreView, CHtmlView)

BEGIN_MESSAGE_MAP(CExploreView, CHtmlView)

	//{{AFX_MSG_MAP(CExploreView)
	ON_COMMAND(ID_CSDN, OnCsdn)
	ON_COMMAND(ID_VCSHARE, OnVcshare)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExploreView construction/destruction

CExploreView::CExploreView()
{
	// TODO: add construction code here

}

CExploreView::~CExploreView()
{
}

BOOL CExploreView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CHtmlView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CExploreView drawing

void CExploreView::OnDraw(CDC* pDC)
{
	CExploreDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

void CExploreView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	// TODO: This code navigates to a popular spot on the web.
	//  change the code to go where you'd like.
	Navigate2(_T("https://www.google.com/"),NULL,NULL);
}

/////////////////////////////////////////////////////////////////////////////
// CExploreView diagnostics

#ifdef _DEBUG
void CExploreView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CExploreView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CExploreDoc* CExploreView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExploreDoc)));
	return (CExploreDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExploreView message handlers

//handle for popup menu
void CExploreView::OnCsdn() 
{
	// TODO: Add your command handler code here
	Navigate2(_T("http://www.csdn.net"),NULL,NULL);
	
}


void CExploreView::OnVcshare() 
{
	// TODO: Add your command handler code here
	Navigate2(_T("http://www.vcshare.net"),NULL,NULL);
	
}
