
// Exp2View.cpp : CExp2View 类的实现
//

#include "stdafx.h"
#include "Exp2.h"

#include "Exp2Doc.h"
#include "Exp2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExp2View

IMPLEMENT_DYNCREATE(CExp2View, CView)

BEGIN_MESSAGE_MAP(CExp2View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CExp2View 构造/析构

CExp2View::CExp2View()
{
	// TODO: 在此处添加构造代码

}

CExp2View::~CExp2View()
{
}

BOOL CExp2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExp2View 绘制

void CExp2View::OnDraw(CDC* pDC)
{
	CExp2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	//use brush
	int red=0,green=0,blue=0;
	int width=2, row=20;

	int style[]={HS_BDIAGONAL,HS_CROSS,HS_DIAGCROSS,HS_FDIAGONAL,
					HS_VERTICAL};

	//[20 200 20 170]
	for (int ix=0;ix<5; ++ix)
	{
		int m_color=RGB(red,green,blue);
		CBrush m_Brush(m_color);
		CBrush* old_Brush=pDC->SelectObject(&m_Brush);
		pDC->Rectangle(20,row,200,row+20);
		pDC->SelectObject(old_Brush);
		red+=34; green+=16; blue+=8;
		row+=30;
	}

	row=20;

	//[220 400 20 170]
	for (int ix=0; ix<5; ++ix)
	{
		CBrush m_Brush(style[ix],RGB(0,0,0));
		CBrush* old_Brush=pDC->SelectObject(&m_Brush);
		pDC->Rectangle(220,row,400,row+20);
		pDC->SelectObject(&old_Brush);
		row+=30;
	}

	//plot a rectangle
	int m_Margin=5;
	CRect rect(420,420,190,190);
	pDC->Rectangle(&rect);

	pDC->TextOut(450,450,"Today is another day");
	pDC->SetTextAlign(TA_RIGHT);
	pDC->TextOut(450,470,"Yesterday is not controllable");
	pDC->SetTextAlign(TA_LEFT);
	pDC->SetTextCharacterExtra(10);
	pDC->SetTextColor(RGB(255,0,0));
	pDC->SetBkColor(RGB(0,0,255));
	//SetROP2(R2_BLACK); //set plot pattern
	return;
}


void CExp2View::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CExp2View::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// CExp2View 诊断

#ifdef _DEBUG
void CExp2View::AssertValid() const
{
	CView::AssertValid();
}

void CExp2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExp2Doc* CExp2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExp2Doc)));
	return (CExp2Doc*)m_pDocument;
}
#endif //_DEBUG


// CExp2View 消息处理程序

void CExp2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CRect rc;
	GetClientRect(&rc);

	dc.MoveTo(0,(rc.bottom+rc.top)/2);
	dc.LineTo((rc.right+rc.left)/2,0);
	dc.LineTo(rc.right,(rc.bottom+rc.top)/2);
	dc.LineTo((rc.bottom+rc.top)/2,rc.bottom);
	dc.LineTo(0,(rc.bottom+rc.top)/2);

	CView::OnLButtonDown(nFlags, point);
}
