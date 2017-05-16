// SIGView.cpp : implementation of the CSIGView class
//

#include "stdafx.h"
#include "SIG.h"

#include "SIGDoc.h"
#include "SIGView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSIGView

IMPLEMENT_DYNCREATE(CSIGView, CView)

BEGIN_MESSAGE_MAP(CSIGView, CView)
	//{{AFX_MSG_MAP(CSIGView)
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSIGView construction/destruction

CSIGView::CSIGView()
{
	// TODO: add construction code here

}

CSIGView::~CSIGView()
{
}

BOOL CSIGView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSIGView drawing

void CSIGView::OnDraw(CDC* pDC)
{
	CSIGDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->TextOut(0,0,pDoc->m_strText);
	/*for (int i=0; i<50000; ++i)
	{
		
	}*/
	Invalidate(NULL);

}

/////////////////////////////////////////////////////////////////////////////
// CSIGView printing

BOOL CSIGView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSIGView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSIGView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSIGView diagnostics

#ifdef _DEBUG
void CSIGView::AssertValid() const
{
	CView::AssertValid();
}

void CSIGView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSIGDoc* CSIGView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSIGDoc)));
	return (CSIGDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSIGView message handlers

void CSIGView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	CSIGDoc* pDoc=GetDocument();
	//pDoc->m_strText+=nChar;

	//CClientDC dc(this);
	//dc.TextOut(0,0,pDoc->m_strText);
	RedrawWindow();
	
	CView::OnChar(nChar, nRepCnt, nFlags);
}

void CSIGView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CSIGDoc *pDoc=GetDocument();
	pDoc->m_clickTimes++;
	pDoc->m_strText.Format("Left-click mouse at %d, %d, total click time %d",point.x,
		point.y, pDoc->m_clickTimes);
	
	CView::OnLButtonDown(nFlags, point);
}
