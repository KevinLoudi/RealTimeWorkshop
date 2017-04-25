
// Exp7View.cpp : implementation of the CExp7View class
//

#include "stdafx.h"
#include "Exp7.h"

#include "Exp7Doc.h"
#include "Exp7View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExp7View

IMPLEMENT_DYNCREATE(CExp7View, CView)

BEGIN_MESSAGE_MAP(CExp7View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_NCMOUSEMOVE()
END_MESSAGE_MAP()

// CExp7View construction/destruction

CExp7View::CExp7View()
{
	// TODO: add construction code here

}

CExp7View::~CExp7View()
{
}

BOOL CExp7View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CExp7View drawing

void CExp7View::OnDraw(CDC* pDC)
{
	CExp7Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	pDC->Rectangle(pDoc->m_tagRect);

	CPoint point(30,30);
	pDC->MoveTo(point);
	pDC->LineTo(pDoc->m_Point);
}


// CExp7View diagnostics

#ifdef _DEBUG
void CExp7View::AssertValid() const
{
	CView::AssertValid();
}

void CExp7View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExp7Doc* CExp7View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExp7Doc)));
	return (CExp7Doc*)m_pDocument;
}
#endif //_DEBUG


// CExp7View message handlers

void CExp7View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CExp7Doc* pDoc=GetDocument();
	if (nFlags&MK_SHIFT)
	{
		pDoc->m_tagRect.left=30;
		pDoc->m_tagRect.top=30;
		pDoc->m_tagRect.right=350;
		pDoc->m_tagRect.bottom=300;
	}
	else
	{
		pDoc->m_tagRect.left=point.x;
		pDoc->m_tagRect.top=point.y;
		pDoc->m_tagRect.right=point.x+320;
		pDoc->m_tagRect.bottom=point.y+270;
	}
	InvalidateRect(NULL,TRUE);
	CView::OnLButtonDown(nFlags, point);
}

void CExp7View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CExp7Doc* pDoc=GetDocument();
	pDoc->m_Point=point;
	InvalidateRect(NULL,TRUE);
	CView::OnMouseMove(nFlags, point);
}

void CExp7View::OnNcMouseMove(UINT nHitTest, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC clientDC(this);
	char s[20];
	wsprintf(s,"X=%d  Y=%d ",point.x, point.y);
	clientDC.TextOut(20,20,s);
	CView::OnNcMouseMove(nHitTest, point);
}
