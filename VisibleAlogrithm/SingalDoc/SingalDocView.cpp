
// SingalDocView.cpp : implementation of the CSingalDocView class
//

#include "stdafx.h"
#include "SingalDoc.h"

#include "SingalDocDoc.h"
#include "SingalDocView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSingalDocView

IMPLEMENT_DYNCREATE(CSingalDocView, CFormView)

BEGIN_MESSAGE_MAP(CSingalDocView, CFormView)
	ON_BN_CLICKED(IDC_FIND, &CSingalDocView::OnBnClickedFind)
END_MESSAGE_MAP()

// CSingalDocView construction/destruction

CSingalDocView::CSingalDocView()
	: CFormView(CSingalDocView::IDD)
	, m_iStuNo(0)
{
	// TODO: add construction code here

}

CSingalDocView::~CSingalDocView()
{
}

void CSingalDocView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STUNO, m_iStuNo);
}

BOOL CSingalDocView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CSingalDocView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

void CSingalDocView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSingalDocView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// CSingalDocView diagnostics

#ifdef _DEBUG
void CSingalDocView::AssertValid() const
{
	CFormView::AssertValid();
}

void CSingalDocView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CSingalDocDoc* CSingalDocView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSingalDocDoc)));
	return (CSingalDocDoc*)m_pDocument;
}
#endif //_DEBUG


// CSingalDocView message handlers

void CSingalDocView::OnBnClickedFind()
{
	// TODO: 在此添加控件通知处理程序代码
	CSingalDocDoc* pDoc=GetDocument();
	if (pDoc==NULL)
	{
		ASSERT(false);
		return;
	}

	UpdateData();

	if (!pDoc->SetCurrentStudent(m_iStuNo))
	{
		AfxMessageBox("Cannot find the student");
		return;
	}

	pDoc->UpdateAllViews(NULL);
}
