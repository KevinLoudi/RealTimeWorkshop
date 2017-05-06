
// m_VC1View.cpp : implementation of the Cm_VC1View class
//

#include "stdafx.h"
#include "m_VC1.h"

#include "m_VC1Doc.h"
#include "m_VC1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cm_VC1View

IMPLEMENT_DYNCREATE(Cm_VC1View, CView)

BEGIN_MESSAGE_MAP(Cm_VC1View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cm_VC1View::OnFilePrintPreview)
END_MESSAGE_MAP()

// Cm_VC1View construction/destruction

Cm_VC1View::Cm_VC1View()
{
	// TODO: add construction code here

}

Cm_VC1View::~Cm_VC1View()
{
}

BOOL Cm_VC1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Cm_VC1View drawing

void Cm_VC1View::OnDraw(CDC* pDC)
{
	Cm_VC1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	Text1(); //20,10
	pDC->TextOut(20,50,"Not need to release dc pointer in OnDraw"); //20,50
	Text2(20,90); //20,90
	Text3(2.356,6.9845); //20,130
	//200,10
}


// Cm_VC1View printing


void Cm_VC1View::OnFilePrintPreview()
{
	AFXPrintPreview(this);
}

BOOL Cm_VC1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Cm_VC1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Cm_VC1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void Cm_VC1View::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cm_VC1View::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// Cm_VC1View diagnostics

#ifdef _DEBUG
void Cm_VC1View::AssertValid() const
{
	CView::AssertValid();
}

void Cm_VC1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cm_VC1Doc* Cm_VC1View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cm_VC1Doc)));
	return (Cm_VC1Doc*)m_pDocument;
}

void Cm_VC1View::Text1()
{
	CDC *pDc=GetDC(); //initial device context
	pDc->SetTextColor(RGB(255,0,0)); //red text
	pDc->SetBkMode(OPAQUE); //background show
	pDc->SetBkColor(RGB(0,0,255)); //blue background
	pDc->TextOut(20,10,"Text from CDC"); //output text
	ReleaseDC(pDc); //release device context
}

void Cm_VC1View::Text2(UINT x_pos, UINT y_pos)
{
	CDC *pDc=GetDC(); //initial device context
	char buf[30];
	//create and select font
	CFont fnBig;
	CFont* pFont;
	fnBig.CreatePointFont(180,"Arial",pDc); //create a new font, named "Arial", with 180 pixels
	pFont=pDc->SelectObject(&fnBig); //select a new font and save the original font

	wsprintf(buf,"Position: (%f,%f)",x_pos,y_pos); //float number
	pDc->TextOut(x_pos,y_pos,buf,strlen(buf)); //output string in a length

	pDc->SelectObject(pFont); //release and recover the original font
	ReleaseDC(pDc); //release device context
}

void Cm_VC1View::Text3(float width, float height)
{
	CDC *pDc=GetDC(); //initial device context
	CString buf;
	buf.Format("Area: (%5.2f)",width*height); //control output format
	pDc->TextOut(20,130,buf,strlen(buf));
	ReleaseDC(pDc); //release device context
}

void Cm_VC1View::SetRectangle()
{
	CDC *pDc=GetDC(); //initial device context
	CRect rect;
	GetClientRect(&rect); //get client window size
	pDc->SetMapMode(MM_LOMETRIC); //set map mode, per 0.1mm
	pDc->SetViewportOrg(int(rect.right/2),int(rect.bottom/2)); //set origi point
	ReleaseDC(pDc); //release device context
}

#endif //_DEBUG


// Cm_VC1View message handlers
