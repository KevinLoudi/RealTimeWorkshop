
// Exp1View.cpp : CExp1View 类的实现
//

#include "stdafx.h"
#include "Exp1.h"

#include "Exp1Doc.h"
#include "Exp1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExp1View

IMPLEMENT_DYNCREATE(CExp1View, CView)

BEGIN_MESSAGE_MAP(CExp1View, CView)
END_MESSAGE_MAP()

// CExp1View 构造/析构

CExp1View::CExp1View()
{
	// TODO: 在此处添加构造代码

}

CExp1View::~CExp1View()
{
}

BOOL CExp1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExp1View 绘制

void CExp1View::OnDraw(CDC* pDC)
{
	CExp1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	//show rectangle
	pDoc->SetMember(1,100);
	CRect rt(40,40,40+pDoc->GetMember(1),40+pDoc->GetMember(1));
	pDC->Rectangle(&rt);

	//show text
	pDC->TextOut(50,50,pDoc->m_Text,6);
	pDC->TextOut(190,50,pDoc->GetTitle()); //show doc title

	//use pen
	//pen attributions
	int red=0,green=0,blue=0;
	int width=2, row=20;
	int color=RGB(red,green,blue);
	int style[]={PS_SOLID,PS_DASH,PS_DASHDOT,
			PS_DOT,PS_DASHDOTDOT};

	for (int ix=0;ix<5;++ix)
	{
		//CPen m_Pen(style[ix],width,color); //create a new pen
		CPen m_Pen(style[ix],1,RGB(0,0,0));
		CPen* oldPen=pDC->SelectObject(&m_Pen); //use the new pen
		//Point m_Point(20,row);
		pDC->MoveTo(300,row);
		pDC->LineTo(800,row);
		//red+=32; green+=16; blue+=8;
		//width+=2; 
		row+=30;
	}

	//use brush
	red=0,green=0,blue=0;
	width=2, row=20;
	for (int ix=0;ix<5; ++ix)
	{
		int m_color=RGB(red,green,blue);
		CBrush m_Brush(m_color);
		CBrush* oldBrush=pDC->SelectObject(&m_Brush);
		pDC->Rectangle(20,row,200,row+20);
		pDC->SelectObject(oldBrush);
		red+=32; green+=16; blue+=8;
		width+=30;
	}
	return;
}

void CExp1View::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CExp1View::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// CExp1View 诊断

#ifdef _DEBUG
void CExp1View::AssertValid() const
{
	CView::AssertValid();
}

void CExp1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExp1Doc* CExp1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExp1Doc)));
	return (CExp1Doc*)m_pDocument;
}
#endif //_DEBUG


// CExp1View 消息处理程序
