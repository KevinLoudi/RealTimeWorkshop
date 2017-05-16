// MLPView.cpp : implementation of the CMLPView class
//

#include "stdafx.h"
#include "MLP.h"

#include "MLPDoc.h"
#include "MLPView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMLPView

IMPLEMENT_DYNCREATE(CMLPView, CView)

BEGIN_MESSAGE_MAP(CMLPView, CView)
	//{{AFX_MSG_MAP(CMLPView)
	ON_WM_CHAR()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMLPView construction/destruction

CMLPView::CMLPView()
{
	// TODO: add construction code here

}

CMLPView::~CMLPView()
{
}

BOOL CMLPView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMLPView drawing

void CMLPView::OnDraw(CDC* pDC)
{
	CMLPDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	pDC->TextOut(0,0,pDoc->m_strText);

	Invalidate(NULL);
}

/////////////////////////////////////////////////////////////////////////////
// CMLPView printing

BOOL CMLPView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMLPView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMLPView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMLPView diagnostics

#ifdef _DEBUG
void CMLPView::AssertValid() const
{
	CView::AssertValid();
}

void CMLPView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMLPDoc* CMLPView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMLPDoc)));
	return (CMLPDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMLPView message handlers

void CMLPView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	CMLPDoc *pDoc=GetDocument();
	pDoc->m_strText+=nChar;

	CClientDC dc(this);
	dc.TextOut(0,0,pDoc->m_strText);

	//update all views of the same document
	pDoc->UpdateAllViews(this);
	Invalidate(NULL);
	
	CView::OnChar(nChar, nRepCnt, nFlags);
}
