
// Exp4View.cpp : implementation of the CExp4View class
//

#include "stdafx.h"
#include "Exp4.h"

#include "Exp4Doc.h"
#include "Exp4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExp4View

IMPLEMENT_DYNCREATE(CExp4View, CListView)

BEGIN_MESSAGE_MAP(CExp4View, CListView)
	ON_WM_STYLECHANGED()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CExp4View construction/destruction

CExp4View::CExp4View()
{
	// TODO: add construction code here

}

CExp4View::~CExp4View()
{
}

BOOL CExp4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CListView::PreCreateWindow(cs);
}

void CExp4View::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	// TODO: You may populate your ListView with items by directly accessing
	//  its list control through a call to GetListCtrl().
}


// CExp4View diagnostics

#ifdef _DEBUG
void CExp4View::AssertValid() const
{
	CListView::AssertValid();
}

void CExp4View::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CExp4Doc* CExp4View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExp4Doc)));
	return (CExp4Doc*)m_pDocument;
}
#endif //_DEBUG


// CExp4View message handlers
void CExp4View::OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct)
{
	//TODO: add code to react to the user changing the view style of your window	
	CListView::OnStyleChanged(nStyleType,lpStyleStruct);	
}

void CExp4View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CExp4Doc *pDoc=GetDocument();
	int r=rand()%50+5;
	CRect Ret(point.x-r,point.y-r,point.x+r,point.y+r);
	CListView::OnLButtonDown(nFlags, point);
}
