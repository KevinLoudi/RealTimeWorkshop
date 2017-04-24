
// Exp3View.cpp : implementation of the CExp3View class
//

#include "stdafx.h"
#include "Exp3.h"

#include "Exp3Doc.h"
#include "Exp3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExp3View

IMPLEMENT_DYNCREATE(CExp3View, CView)

BEGIN_MESSAGE_MAP(CExp3View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CExp3View construction/destruction

CExp3View::CExp3View()
{
	// TODO: add construction code here
	m_Rectag.SetSize(256,256);
}

CExp3View::~CExp3View()
{
}

BOOL CExp3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CExp3View drawing

void CExp3View::OnDraw(CDC* pDC)
{
	CExp3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	for (int ix=0;ix<m_Rectag.GetSize();++ix)
	{
		pDC->Rectangle(m_Rectag[ix]);
	}
}

void CExp3View::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CExp3View::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// CExp3View diagnostics

#ifdef _DEBUG
void CExp3View::AssertValid() const
{
	CView::AssertValid();
}

void CExp3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExp3Doc* CExp3View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExp3Doc)));
	return (CExp3Doc*)m_pDocument;
}
#endif //_DEBUG


// CExp3View message handlers

void CExp3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString str1="This ";
	CString str2="is ", str3="concantenation ";
	CString str=str1+str2+str3;
	AfxMessageBox(str, MB_OK|MB_ICONINFORMATION);
	CView::OnLButtonDown(nFlags, point);
}

void CExp3View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int r=rand()%50+5;
	CRect Ret(point.x-r,point.y-r,point.x+r,point.y+r);
	m_Rectag.Add(Ret);
	InvalidateRect(Ret,FALSE); //call OnDraw()
	CView::OnRButtonDown(nFlags, point);
}
