
// ToolBarView.cpp : implementation of the CToolBarView class
//

#include "stdafx.h"
#include "ToolBar.h"

#include "ToolBarDoc.h"
#include "ToolBarView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CToolBarView

IMPLEMENT_DYNCREATE(CToolBarView, CView)

BEGIN_MESSAGE_MAP(CToolBarView, CView)
END_MESSAGE_MAP()

// CToolBarView construction/destruction

CToolBarView::CToolBarView()
{
	// TODO: add construction code here

}

CToolBarView::~CToolBarView()
{
}

BOOL CToolBarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CToolBarView drawing

void CToolBarView::OnDraw(CDC* /*pDC*/)
{
	CToolBarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}

void CToolBarView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CToolBarView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// CToolBarView diagnostics

#ifdef _DEBUG
void CToolBarView::AssertValid() const
{
	CView::AssertValid();
}

void CToolBarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CToolBarDoc* CToolBarView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CToolBarDoc)));
	return (CToolBarDoc*)m_pDocument;
}
#endif //_DEBUG


// CToolBarView message handlers
