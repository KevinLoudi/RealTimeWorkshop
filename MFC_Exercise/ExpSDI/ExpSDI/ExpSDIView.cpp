
// ExpSDIView.cpp : implementation of the CExpSDIView class
//

#include "stdafx.h"
#include "ExpSDI.h"

#include "ExpSDIDoc.h"
#include "ExpSDIView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExpSDIView

IMPLEMENT_DYNCREATE(CExpSDIView, CView)

BEGIN_MESSAGE_MAP(CExpSDIView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_CREATE()
	ON_BN_CLICKED(IDB_BUTTON1,OnButton1Clicked)
	ON_BN_CLICKED(IDB_BUTTON2,OnButton2Clicked)
	ON_EN_MAXTEXT(IDC_EDIT1,OnMaxText)

	ON_WM_TIMER()
END_MESSAGE_MAP()

// CExpSDIView construction/destruction

CExpSDIView::CExpSDIView()
{
	// TODO: add construction code here

}

CExpSDIView::~CExpSDIView()
{
}

BOOL CExpSDIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CExpSDIView drawing

void CExpSDIView::OnDraw(CDC* pDC)
{
	CExpSDIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	//pDC->TextOut(30,6,CString(pDoc->m_lLetter));
	//pDC->TextOut(30,26,CString(pDoc->m_Letter.GetLetter()));

	pDoc->DrawLetter(pDC);
}


// CExpSDIView diagnostics

#ifdef _DEBUG
void CExpSDIView::AssertValid() const
{
	CView::AssertValid();
}

void CExpSDIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExpSDIDoc* CExpSDIView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExpSDIDoc)));
	return (CExpSDIDoc*)m_pDocument;
}
#endif //_DEBUG


void CExpSDIView::InitSpinner()
{	
	m_spin.Create(WS_CHILD|WS_VISIBLE|WS_BORDER|UDS_SETBUDDYINT|
		UDS_ALIGNLEFT|UDS_ARROWKEYS,
		CRect(500,20,600,600),this,IDC_SPINNER);
	m_spin.SetBuddy(&m_spin);
	m_spin.SetRange(0,100);
	m_spin.SetPos(0);
}

void CExpSDIView::InitProgressBar()
{
	m_progBar1.Create(WS_CHILD|WS_BORDER|WS_VISIBLE,
		CRect(300,20,400,60),this,IDC_PROGBAR1);
	m_progBar1.SetRange(0,100);
	m_progBar1.SetStep(10);
	m_progBar1.SetPos(0);

	m_progBar2.Create(WS_CHILD|WS_BORDER|WS_VISIBLE|PBS_VERTICAL|PBS_SMOOTH,
		CRect(300,60,340,160),this,IDC_PROGBAR2);
	m_progBar2.SetRange(0,100);
	m_progBar2.SetStep(10);
	m_progBar2.SetPos(0);
}

// CExpSDIView message handlers

void CExpSDIView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CExpSDIDoc* pDoc=GetDocument();
	pDoc->NewLetter(point.x,point.y);
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}

void CExpSDIView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CExpSDIDoc* pDoc=GetDocument();
	pDoc->m_Letter.SetLetter('N');
	Invalidate();
	CView::OnRButtonDown(nFlags, point);
}

int CExpSDIView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代
	m_label1.Create("Write Board",WS_VISIBLE|SS_CENTER,
			CRect(10,20,200,60),this,0);

	m_button1.Create("Responds",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE|WS_BORDER,
		CRect(10,80,200,120),this, IDB_BUTTON1);

	m_button2.Create("Impulse",WS_CHILD|BS_CHECKBOX|WS_VISIBLE,
		CRect(10,120,200,160),this,IDB_BUTTON2);

	m_edit1.Create(WS_CHILD|WS_VISIBLE|WS_BORDER|ES_LEFT|ES_WANTRETURN|
		ES_MULTILINE, CRect(10,160,200,200),this,IDC_EDIT1);

	return 0;
}

void CExpSDIView::OnButton1Clicked()
{
	MessageBox("This is responds",MB_OK);
}

void CExpSDIView::OnButton2Clicked()
{
	int checked=m_button2.GetCheck();
	if (checked==BST_CHECKED)
	{
		m_button2.SetCheck(!checked);
		MessageBox("Unchecked impluse");
	} 
	else if(checked==BST_UNCHECKED)
	{
		m_button2.SetCheck(!checked);
		MessageBox("Checked impluse");
	}
}

void CExpSDIView::OnMaxText()
{
	MessageBox("Text overflow",MB_OK);
}

void CExpSDIView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_progBar1.SetPos(m_spin.GetPos());
	m_progBar2.SetPos(m_spin.GetPos());
	CView::OnTimer(nIDEvent);
}
