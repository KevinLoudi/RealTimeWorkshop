
// Doc_ViewView.cpp : CDoc_ViewView 类的实现
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

// CDoc_ViewView 构造/析构

CDoc_ViewView::CDoc_ViewView()
{
	// TODO: 在此处添加构造代码

}

CDoc_ViewView::~CDoc_ViewView()
{
}

BOOL CDoc_ViewView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDoc_ViewView 绘制

void CDoc_ViewView::OnDraw(CDC* pDC)
{
	CDoc_ViewDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
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


// CDoc_ViewView 诊断

#ifdef _DEBUG
void CDoc_ViewView::AssertValid() const
{
	CView::AssertValid();
}

void CDoc_ViewView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDoc_ViewDoc* CDoc_ViewView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDoc_ViewDoc)));
	return (CDoc_ViewDoc*)m_pDocument;
}
#endif //_DEBUG


// CDoc_ViewView 消息处理程序
