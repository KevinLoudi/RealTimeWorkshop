
// ExpSDIView.cpp : implementation of the CExpSDIView class
//

#include "stdafx.h"
#include "ExpSDI.h"

#include "ExpSDIDoc.h"
#include "ExpSDIView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExpSDIView

IMPLEMENT_DYNCREATE(CExpSDIView, CView)

BEGIN_MESSAGE_MAP(CExpSDIView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CExpSDIView construction/destruction

CExpSDIView::CExpSDIView()
{
	// TODO: add construction code here

}

CExpSDIView::~CExpSDIView()
{
}

BOOL CExpSDIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CExpSDIView drawing

void CExpSDIView::OnDraw(CDC* pDC)
{
	CExpSDIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	pDC->TextOut(30,6,CString(pDoc->m_lLetter));
	pDC->TextOut(30,26,CString(pDoc->m_Letter.GetLetter()));
}


// CExpSDIView diagnostics

#ifdef _DEBUG
void CExpSDIView::AssertValid() const
{
	CView::AssertValid();
}

void CExpSDIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExpSDIDoc* CExpSDIView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExpSDIDoc)));
	return (CExpSDIDoc*)m_pDocument;
}
#endif //_DEBUG


// CExpSDIView message handlers

void CExpSDIView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CExpSDIDoc* pDoc=GetDocument();
	pDoc->m_lLetter='M';
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}

void CExpSDIView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CExpSDIDoc* pDoc=GetDocument();
	pDoc->m_Letter.SetLetter('N');
	Invalidate();
	CView::OnRButtonDown(nFlags, point);
}
