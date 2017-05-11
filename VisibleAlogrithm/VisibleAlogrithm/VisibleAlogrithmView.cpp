
// VisibleAlogrithmView.cpp : implementation of the CVisibleAlogrithmView class
//

#include "stdafx.h"
#include "VisibleAlogrithm.h"

#include "VisibleAlogrithmDoc.h"
#include "VisibleAlogrithmView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CVisibleAlogrithmView

IMPLEMENT_DYNCREATE(CVisibleAlogrithmView, CView)

BEGIN_MESSAGE_MAP(CVisibleAlogrithmView, CView)
	ON_COMMAND(ID_TYPE, &CVisibleAlogrithmView::OnType)
END_MESSAGE_MAP()

// CVisibleAlogrithmView construction/destruction

CVisibleAlogrithmView::CVisibleAlogrithmView()
{
	// TODO: add construction code here

}

CVisibleAlogrithmView::~CVisibleAlogrithmView()
{
}

BOOL CVisibleAlogrithmView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CVisibleAlogrithmView drawing

void CVisibleAlogrithmView::OnDraw(CDC* /*pDC*/)
{
	CVisibleAlogrithmDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}

void CVisibleAlogrithmView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CVisibleAlogrithmView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// CVisibleAlogrithmView diagnostics

#ifdef _DEBUG
void CVisibleAlogrithmView::AssertValid() const
{
	CView::AssertValid();
}

void CVisibleAlogrithmView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CVisibleAlogrithmDoc* CVisibleAlogrithmView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CVisibleAlogrithmDoc)));
	return (CVisibleAlogrithmDoc*)m_pDocument;
}
#endif //_DEBUG


// CVisibleAlogrithmView message handlers

void CVisibleAlogrithmView::OnType()
{
	// TODO: 在此添加命令处理程序代码
	CTypeDlg dlg;
	dlg.DoModal();
}
