
// m_VC2View.cpp : implementation of the Cm_VC2View class
//

#include "stdafx.h"
#include "m_VC2.h"

#include "m_VC2Doc.h"
#include "m_VC2View.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cm_VC2View

IMPLEMENT_DYNCREATE(Cm_VC2View, CView)

BEGIN_MESSAGE_MAP(Cm_VC2View, CView)
END_MESSAGE_MAP()

// Cm_VC2View construction/destruction

Cm_VC2View::Cm_VC2View()
{
	// TODO: add construction code here

}

Cm_VC2View::~Cm_VC2View()
{
}

BOOL Cm_VC2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Cm_VC2View drawing

void Cm_VC2View::OnDraw(CDC* pDC)
{
	Cm_VC2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_LOMETRIC);
	pDC->SetViewportOrg(int(rect.right/2),int(rect.bottom/2));
	//fill a rectangle without border
	FillRect0(pDC,RGB(192,192,192),(0,0),700,500);
	Rectangle0(pDC,-700,0,0,-500,RGB(128,128,128));
	Line0(pDC,-700,500,700,-500,4,RGB(255,0,0));
	Line0(pDC,-700,-500,700,500,4,RGB(0,255,0));
	Ellipse0(pDC,-300,500,0,0,1,RGB(192,192,192),LTGRAY_BRUSH);
}


// Cm_VC2View diagnostics

#ifdef _DEBUG
void Cm_VC2View::AssertValid() const
{
	CView::AssertValid();
}

void Cm_VC2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cm_VC2Doc* Cm_VC2View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cm_VC2Doc)));
	return (Cm_VC2Doc*)m_pDocument;
}

void Cm_VC2View::FillRect0(CDC* pDc, COLORREF col, CPoint point, int chd,int kd)
{
	CBrush newBrush(col);
	CBrush* pBrush=pDc->SelectObject(&newBrush); //use new brush and save the old brush
	pDc->FillRect(CRect(point.x,point.y,point.x+chd,point.y+kd),&newBrush); //fill a rectangel
	pDc->SelectObject(pBrush); //recover brush
	newBrush.DeleteObject(); //delete the new brush style
	return;
}

void Cm_VC2View::Rectangle0(CDC* pDc,UINT top_left,UINT bottom_left, UINT top_right, UINT bottom_right, COLORREF col)
{
	CBrush eiBrush;
	CBrush* pOldBrush;
	CPen* pOldPen;

	//select pen and brush to plot
	pOldPen=(CPen*)pDc->SelectStockObject(NULL_PEN); //select a null pen and get its pointer
	eiBrush.CreateSolidBrush(col);
	pOldBrush=pDc->SelectObject(&eiBrush);
	pDc->Rectangle(top_left,top_right,bottom_left,bottom_right); //plot a rectangle

	//recover original pen and brush
	pDc->SelectObject(pOldPen);
	pDc->SelectObject(pOldBrush);
	eiBrush.DeleteObject();
	return;
}

void Cm_VC2View::Line0(CDC* pDc,UINT x1,UINT y1, UINT x2, UINT y2, UINT swid,
					   COLORREF scol)
{
	CPen sPen;
	CPen* oPen;
	sPen.CreatePen(PS_SOLID,swid,scol);

	//plot a line with the created pen
	oPen=pDc->SelectObject(&sPen);
	pDc->MoveTo(x1,y1);
	pDc->LineTo(x2,y2);

	pDc->SelectObject(oPen);
	sPen.DeleteObject();
	return;
}

void Cm_VC2View::Ellipse0(CDC* pDc,UINT left,UINT top, UINT right, UINT bottom, UINT swid, COLORREF scol,BOOL mb)
{
	CPen sPen;
	CPen* oPen;
	CBrush* pBrush=(CBrush*)pDc->SelectStockObject(mb);

	//plot ellipse with the create pen and selected brush
	sPen.CreatePen(PS_SOLID,swid,scol);
	oPen=pDc->SelectObject(&sPen);
	pDc->Ellipse(left,top,right,left);

	pDc->SelectObject(oPen);
	pDc->SelectObject(pBrush);
	sPen.DeleteObject();
	return;
}

#endif //_DEBUG


// Cm_VC2View message handlers
