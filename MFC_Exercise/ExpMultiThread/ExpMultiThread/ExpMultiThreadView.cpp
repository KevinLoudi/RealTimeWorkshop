
// ExpMultiThreadView.cpp : implementation of the CExpMultiThreadView class
//

#include "stdafx.h"
#include "ExpMultiThread.h"

#include "ExpMultiThreadDoc.h"
#include "ExpMultiThreadView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExpMultiThreadView

IMPLEMENT_DYNCREATE(CExpMultiThreadView, CView)

BEGIN_MESSAGE_MAP(CExpMultiThreadView, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CExpMultiThreadView construction/destruction

CExpMultiThreadView::CExpMultiThreadView()
{
	// TODO: add construction code here

}

CExpMultiThreadView::~CExpMultiThreadView()
{
}

BOOL CExpMultiThreadView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CExpMultiThreadView drawing

void CExpMultiThreadView::OnDraw(CDC* /*pDC*/)
{
	CExpMultiThreadDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}

void CExpMultiThreadView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CExpMultiThreadView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// CExpMultiThreadView diagnostics

#ifdef _DEBUG
void CExpMultiThreadView::AssertValid() const
{
	CView::AssertValid();
}

void CExpMultiThreadView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

UINT MessageThread(LPVOID pParam)
{
	char* pMessage=(char*)pParam;
	CWnd* pMainWnd=AfxGetMainWnd();
	::MessageBox(pMainWnd->m_hWnd,pMessage,"Thread message",MB_OK);
	return 0;
}

CExpMultiThreadDoc* CExpMultiThreadView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExpMultiThreadDoc)));
	return (CExpMultiThreadDoc*)m_pDocument;
}
#endif //_DEBUG


// CExpMultiThreadView message handlers

void CExpMultiThreadView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//AfxBeginThread(MessageThread,"Greeting from my thread");
	AfxBeginThread(RUNTIME_CLASS(CmThread));
	CView::OnLButtonDown(nFlags, point);
}
