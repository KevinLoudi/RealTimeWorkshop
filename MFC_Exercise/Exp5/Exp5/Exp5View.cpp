
// Exp5View.cpp : implementation of the CExp5View class
//

#include "stdafx.h"
#include "Exp5.h"

#include "Exp5Doc.h"
#include "Exp5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExp5View

IMPLEMENT_DYNCREATE(CExp5View, CView)

BEGIN_MESSAGE_MAP(CExp5View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CExp5View construction/destruction

CExp5View::CExp5View()
{
	// TODO: add construction code here
}

CExp5View::~CExp5View()
{
}

BOOL CExp5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CExp5View drawing

void CExp5View::OnDraw(CDC* pDC)
{
	CExp5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	for (int i=0;i<pDoc->m_Rectag.GetSize();++i)
	{
		pDC->Rectangle(pDoc->m_Rectag[i]);
	}
}


// CExp5View diagnostics

#ifdef _DEBUG
void CExp5View::AssertValid() const
{
	CView::AssertValid();
}

void CExp5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExp5Doc* CExp5View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExp5Doc)));
	return (CExp5Doc*)m_pDocument;
}
#endif //_DEBUG


// CExp5View message handlers

void CExp5View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CExp5Doc* pDoc=GetDocument();
	int r=rand()%50+5;
	CRect rct(point.x-r,point.y-r,point.x+r,point.y+r);
	pDoc->m_Rectag.Add(rct);
	pDoc->UpdateAllViews(NULL);
	//InvalidateRect(rct,FALSE);
	CView::OnLButtonDown(nFlags, point);
}
