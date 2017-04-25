
// Exp8View.cpp : implementation of the CExp8View class
//

#include "stdafx.h"
#include "Exp8.h"

#include "Exp8Doc.h"
#include "Exp8View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExp8View

IMPLEMENT_DYNCREATE(CExp8View, CView)

BEGIN_MESSAGE_MAP(CExp8View, CView)
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CExp8View construction/destruction

CExp8View::CExp8View()
{
	// TODO: add construction code here

}

CExp8View::~CExp8View()
{
}

BOOL CExp8View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

void CExp8View::OnSetFocus(CWnd* pOldWnd)
{
	CView::OnSetFocus(pOldWnd);

	CExp8Doc* pDoc=GetDocument();
	pDoc->m_pStr=CString("Get input focus!!!");
	InvalidateRect(NULL,TRUE);
}

void CExp8View::OnKillFocus(CWnd* pNewWnd)
{
	CView::OnKillFocus(pNewWnd);

	CExp8Doc* pDoc=GetDocument();
	pDoc->m_pStr=CString("Loss input focus!!!");
	InvalidateRect(NULL,TRUE);
}

// CExp8View drawing

void CExp8View::OnDraw(CDC* pDC)
{
	CExp8Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	pDC->Ellipse(pDoc->m_crlRect);
	pDC->TextOut(20,20,pDoc->m_pStr);
}


// CExp8View diagnostics

#ifdef _DEBUG
void CExp8View::AssertValid() const
{
	CView::AssertValid();
}

void CExp8View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExp8Doc* CExp8View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExp8Doc)));
	return (CExp8Doc*)m_pDocument;
}
#endif //_DEBUG


// CExp8View message handlers

void CExp8View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CExp8Doc* pDoc=GetDocument();
	CRect clientRct;
	GetClientRect(&clientRct);
	UINT step=1; UINT speed=10;
	step=step*speed;

	switch(nChar)
	{
	case VK_LEFT:
		if (pDoc->m_crlRect.left>0)
		{
			pDoc->m_crlRect.left-=step;
			pDoc->m_crlRect.right-=step;
		}
		break;
	case VK_RIGHT:
		if (pDoc->m_crlRect.right<=(clientRct.right-clientRct.left))
		{
			pDoc->m_crlRect.left+=step;
			pDoc->m_crlRect.right+=step;
		}
		break;
	case VK_UP:
		if (pDoc->m_crlRect.top>0)
		{
			pDoc->m_crlRect.top-=step;
			pDoc->m_crlRect.bottom-=step;
		}
		break;
	case VK_DOWN:
		if (pDoc->m_crlRect.bottom<=(clientRct.bottom-clientRct.top))
		{
			pDoc->m_crlRect.top+=step;
			pDoc->m_crlRect.bottom+=step;
		}
		break;
	}
	InvalidateRect(NULL, TRUE);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CExp8View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	MessageBeep(1);
	CView::OnLButtonDown(nFlags, point);
}
