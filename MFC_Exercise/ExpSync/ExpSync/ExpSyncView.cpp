
// ExpSyncView.cpp : implementation of the CExpSyncView class
//

#include "stdafx.h"
#include "ExpSync.h"

#include "ExpSyncDoc.h"
#include "ExpSyncView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CEvent eventObj; //event object

// CExpSyncView

IMPLEMENT_DYNCREATE(CExpSyncView, CView)

BEGIN_MESSAGE_MAP(CExpSyncView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CExpSyncView construction/destruction

CExpSyncView::CExpSyncView()
{
	// TODO: add construction code here

}

CExpSyncView::~CExpSyncView()
{
}

BOOL CExpSyncView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CExpSyncView drawing

void CExpSyncView::OnDraw(CDC* /*pDC*/)
{
	CExpSyncDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}

void CExpSyncView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CExpSyncView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// CExpSyncView diagnostics

#ifdef _DEBUG
void CExpSyncView::AssertValid() const
{
	CView::AssertValid();
}

void CExpSyncView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExpSyncDoc* CExpSyncView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExpSyncDoc)));
	return (CExpSyncDoc*)m_pDocument;
}
#endif //_DEBUG


// CExpSyncView message handlers

UINT MessageThread1(LPVOID pParam)
{
	char* pMessage="Thread1 started";
	CWnd* pMainWnd=AfxGetMainWnd();
	::MessageBox(pMainWnd->m_hWnd,pMessage,"Thread Message",MB_OK);
	eventObj.Lock();  //put thread 1 in wait condition
	pMessage="Thread1 unblocked";
	::MessageBox(pMainWnd->m_hWnd,pMessage,"Thread1 Message",MB_OK);  //unblock thread1
	eventObj.Lock();
	pMessage="Thread1 unblocked again";
	::MessageBox(pMainWnd->m_hWnd,pMessage,"Thread1 Message",MB_OK);
	return 0;
}

UINT MessageThread2(LPVOID pParam)
{
	char* pMessage="Thread2 started";
	CWnd* pMainWnd=AfxGetMainWnd();
	::MessageBox(pMainWnd->m_hWnd,pMessage,"Thread Message",MB_OK);
	eventObj.Lock();
	pMessage="Thread2 unblocked";
	::MessageBox(pMainWnd->m_hWnd,pMessage,"Thread2 Message",MB_OK);  //unblock thread2
	return 0;
}

UINT MessageThread3(LPVOID pParam)
{
	eventObj.SetEvent();
	return 0;
}

void CExpSyncView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	AfxBeginThread(MessageThread1,"A thread is started");
	AfxBeginThread(MessageThread2,"A thread is started");
	CView::OnLButtonDown(nFlags, point);
}

void CExpSyncView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	AfxBeginThread(MessageThread3,"Thread is unblock");
	CView::OnRButtonDown(nFlags, point);
}
