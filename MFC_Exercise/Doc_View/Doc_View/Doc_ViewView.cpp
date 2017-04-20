
// Doc_ViewView.cpp : CDoc_ViewView ���ʵ��
//

#include "stdafx.h"
#include "Doc_View.h"

#include "Doc_ViewDoc.h"
#include "Doc_ViewView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDoc_ViewView

IMPLEMENT_DYNCREATE(CDoc_ViewView, CView)

BEGIN_MESSAGE_MAP(CDoc_ViewView, CView)
END_MESSAGE_MAP()

// CDoc_ViewView ����/����

CDoc_ViewView::CDoc_ViewView()
{
	// TODO: �ڴ˴���ӹ������

}

CDoc_ViewView::~CDoc_ViewView()
{
}

BOOL CDoc_ViewView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CDoc_ViewView ����

void CDoc_ViewView::OnDraw(CDC* pDC)
{
	CDoc_ViewDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	//create a rectangle length Array[1]
	pDoc->SetMember(1,100);
	CRect rt(40,40,40+pDoc->GetMember(1),40+pDoc->GetMember(1));
	pDC->Rectangle(&rt);
}

void CDoc_ViewView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDoc_ViewView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// CDoc_ViewView ���

#ifdef _DEBUG
void CDoc_ViewView::AssertValid() const
{
	CView::AssertValid();
}

void CDoc_ViewView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDoc_ViewDoc* CDoc_ViewView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDoc_ViewDoc)));
	return (CDoc_ViewDoc*)m_pDocument;
}
#endif //_DEBUG


// CDoc_ViewView ��Ϣ�������
