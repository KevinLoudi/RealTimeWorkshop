
// m_VC3View.cpp : implementation of the Cm_VC3View class
//

#include "stdafx.h"
#include "m_VC3.h"

#include "m_VC3Doc.h"
#include "m_VC3View.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cm_VC3View

IMPLEMENT_DYNCREATE(Cm_VC3View, CView)

BEGIN_MESSAGE_MAP(Cm_VC3View, CView)
END_MESSAGE_MAP()

// Cm_VC3View construction/destruction

Cm_VC3View::Cm_VC3View()
{
	// TODO: add construction code here
	//initial screen show
	for (int i=0; i<SCREEN_SIZE; ++i)
	{
		poi_x[i]=0; poi_y[i]=0;
	}
	col_back=RGB(220,220,220);
	par_m=0; par_z=4;
}

Cm_VC3View::~Cm_VC3View()
{
}

BOOL Cm_VC3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Cm_VC3View drawing

void Cm_VC3View::OnDraw(CDC* /*pDC*/)
{
	Cm_VC3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}

void Cm_VC3View::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cm_VC3View::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// Cm_VC3View diagnostics

#ifdef _DEBUG
void Cm_VC3View::AssertValid() const
{
	CView::AssertValid();
}

void Cm_VC3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cm_VC3Doc* Cm_VC3View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cm_VC3Doc)));
	return (Cm_VC3Doc*)m_pDocument;
}

void Cm_VC3View::FillRect0(CDC* pDc, COLORREF col, CPoint point, int chd,int kd)
{
	CBrush newBrush(col);
	CBrush* pBrush=pDc->SelectObject(&newBrush); //use new brush and save the old brush
	pDc->FillRect(CRect(point.x,point.y,point.x+chd,point.y+kd),&newBrush); //fill a rectangel

	pDc->SelectObject(pBrush); //recover brush
	newBrush.DeleteObject(); //delete the new brush style
	return;
}

void Cm_VC3View::Line0(CDC* pDc,UINT x1,UINT y1, UINT x2, UINT y2, UINT swid, COLORREF scol)
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

void Cm_VC3View::Sin0()
{
	for (int i=0; i<SCREEN_SIZE; ++i)
	{
		poi_x[i]=i;
		poi_y[i]=sin(poi_x[i]*PI/180);
	}
}

void Cm_VC3View::Cos0()
{
	for (int i=0; i<SCREEN_SIZE; ++i)
	{
		poi_x[i]=i;
		poi_y[i]=cos(poi_x[i]*PI/180);
	}
}

void Cm_VC3View::SinCos0()
{
	for (int i=0; i<SCREEN_SIZE; ++i)
	{
		poi_x[i]=i;
		poi_y[i]=sqrt(3.0)*sin(poi_x[i]*PI/180)*cos(poi_x[i]*PI/180);
	}
}

void Cm_VC3View::Axis(CDC* pDc)
{
	CString buf;
	pDc->SetBkColor(col_back);
	int tick=0, x=0, y=0;
	int x_pos=-40, y_pos=-10
	wsprintf(buf,"%d",tick);
	pDc->TextOut(x_pos,y_pos,buf,strlen(buf)); //label origin
	Line0(pDc,-10,0,75,0,4,RGB(0,0,0)); //X-axis
	pDc->TextOut(int(h_ratio*72.5),-40,"X/Degree");
	//set x-axis tickle
	for (int j=0; j<24; ++j)
	{
		int step=3, tick_step=30;
		x_pos+=step; tick++tick_step;
		wsprintf(buf, "%d", tick);
		if (tick%90==0)
		{
			pDc->TextOut()
		}
	}
    Line0(pDc,0,-20,0,20,RGB(0,0,0)); //Y-axis
	pDc->TextOut(-60,int(h_ratio*24),"Y");

}

#endif //_DEBUG


// Cm_VC3View message handlers
