
// ExpDialogView.cpp : implementation of the CExpDialogView class
//

#include "stdafx.h"
#include "ExpDialog.h"

#include "ExpDialogDoc.h"
#include "ExpDialogView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExpDialogView

IMPLEMENT_DYNCREATE(CExpDialogView, CView)

BEGIN_MESSAGE_MAP(CExpDialogView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CExpDialogView construction/destruction

CExpDialogView::CExpDialogView()
{
	// TODO: add construction code here

}

CExpDialogView::~CExpDialogView()
{
}

BOOL CExpDialogView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CExpDialogView drawing

void CExpDialogView::OnDraw(CDC* pDC)
{
	CExpDialogDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	pDC->TextOut(10,10,m_ShowIn);
	pDC->TextOut(100,10,m_ShowOut);
}

void CExpDialogView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CExpDialogView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// CExpDialogView diagnostics

#ifdef _DEBUG
void CExpDialogView::AssertValid() const
{
	CView::AssertValid();
}

void CExpDialogView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExpDialogDoc* CExpDialogView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExpDialogDoc)));
	return (CExpDialogDoc*)m_pDocument;
}
#endif //_DEBUG


// CExpDialogView message handlers

void CExpDialogView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString m_info;
	CmDialog dlg;
	dlg.DoModal(); //run the defined dialog
	CView::OnLButtonDown(nFlags, point);
}

void CExpDialogView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CIODialog dlg;
	int result=dlg.DoModal();
	if (result==IDOK)
	{
		m_ShowIn=dlg.m_Edit_in;
		m_ShowOut=dlg.m_Edit_out;
		Invalidate();
	}
	CView::OnRButtonDown(nFlags, point);
}
