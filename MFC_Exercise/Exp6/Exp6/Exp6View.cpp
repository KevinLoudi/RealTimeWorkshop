
// Exp6View.cpp : implementation of the CExp6View class
//

#include "stdafx.h"
#include "Exp6.h"

#include "Exp6Doc.h"
#include "Exp6View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExp6View

IMPLEMENT_DYNCREATE(CExp6View, CScrollView)

BEGIN_MESSAGE_MAP(CExp6View, CScrollView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CExp6View construction/destruction

CExp6View::CExp6View()
{
	// TODO: add construction code here
	m_ViewDrRect=new CDrawRect;
}

CExp6View::~CExp6View()
{
}

BOOL CExp6View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// CExp6View drawing

void CExp6View::OnDraw(CDC* pDC)
{
	CExp6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	for (int i=0;i<pDoc->m_Rectag.GetSize();++i)
	{
		pDC->Rectangle(pDoc->m_Rectag[i]);
	}

	for (int i=0;i<pDoc->m_Drawtag.GetSize();++i)
	{
		pDC->Ellipse(pDoc->m_Drawtag[i]);
	}
}

void CExp6View::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	CDrawRect *pDrawRect=(CDrawRect*)pHint;
	CRect ret=pDrawRect->m_DrawRect;
	CClientDC dc(this);
	OnPrepareDC(&dc);
	dc.LPtoDP(&ret);
	InvalidateRect(pDrawRect->m_DrawRect,FALSE);
}

void CExp6View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	//CSize sizeTotal;
	// TODO: calculate the total size of this view
	//sizeTotal.cx = sizeTotal.cy = 100;
	CSize sizeTotal(3000,2000);
	CSize sizePage(50,50);
	CSize sizeLine(10,10);
	SetScrollSizes(MM_TEXT, sizeTotal,sizePage,sizeLine);
}


// CExp6View diagnostics

#ifdef _DEBUG
void CExp6View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CExp6View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CExp6Doc* CExp6View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExp6Doc)));
	return (CExp6Doc*)m_pDocument;
}
#endif //_DEBUG


// CExp6View message handlers

//void CExp6View::OnLButtonDown(UINT nFlags, CPoint point)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//	CClientDC dc(this); //get view dc
//	OnPrepareDC(&dc); //coordinates
//	dc.DPtoLP(&point); //coordinate transform
//	CExp6Doc* pDoc=GetDocument();
//	int r=rand()%50+5;
//	CRect rct(point.x-r,point.y-r,point.x+r,point.y+r);
//	pDoc->m_Rectag.Add(rct);
//	pDoc->UpdateAllViews(NULL);
//	dc.LPtoDP(&rct);
//	InvalidateRect(rct,FALSE);
//	CScrollView::OnLButtonDown(nFlags, point);
//}

void CExp6View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this); //get view dc
	OnPrepareDC(&dc); //coordinates
	dc.DPtoLP(&point); //coordinate transform

	CExp6Doc* pDoc=GetDocument();
	int r=rand()%50+5;
	CRect ret(point.x-r,point.y-r,point.x+r,point.y+r);
	pDoc->m_Drawtag.Add(ret);
	m_ViewDrRect->m_DrawRect=ret;

	dc.LPtoDP(&ret);
	InvalidateRect(ret,FALSE);
	pDoc->UpdateAllViews(this,0L,m_ViewDrRect);
	CScrollView::OnRButtonDown(nFlags, point);
}
