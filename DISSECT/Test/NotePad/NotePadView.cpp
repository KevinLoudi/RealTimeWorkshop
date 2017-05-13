
// NotePadView.cpp : implementation of the CNotePadView class
//

#include "stdafx.h"
#include "NotePad.h"

#include "NotePadDoc.h"
#include "NotePadView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNotePadView

IMPLEMENT_DYNCREATE(CNotePadView, CEditView)

BEGIN_MESSAGE_MAP(CNotePadView, CEditView)
	ON_COMMAND(ID_STYLE_FONT, &CNotePadView::OnStyleFont)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CNotePadView construction/destruction

CNotePadView::CNotePadView()
{
	// TODO: add construction code here

}

CNotePadView::~CNotePadView()
{
}

BOOL CNotePadView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// Enable word-wrapping

	return bPreCreated;
}

void CNotePadView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CNotePadView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// CNotePadView diagnostics

#ifdef _DEBUG
void CNotePadView::AssertValid() const
{
	CEditView::AssertValid();
}

void CNotePadView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CNotePadDoc* CNotePadView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNotePadDoc)));
	return (CNotePadDoc*)m_pDocument;
}
#endif //_DEBUG


// CNotePadView message handlers

void CNotePadView::OnStyleFont()
{
	// TODO: 在此添加命令处理程序代码
	CFontDialog dlg(NULL,CF_SCREENFONTS);
	//check if user click OK
	if (IDOK==dlg.DoModal())
	{
		LOGFONT lf;
		dlg.GetCurrentFont(&lf);

		static CFont font; //global font variable
		font.DeleteObject();
		font.CreateFontIndirect(&lf);

		CEdit &edit=GetEditCtrl(); //get edit control input
		edit.SetFont(&font); //set font
	}
}

void CNotePadView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMenu menu;
	//menu.LoadMenu(IDR_MAINFRAME);

	//CMenu *pMenu=menu.GetSubMenu(1); //get the second col
	//if (pMenu==NULL)
	//{
	//	ASSERT(FALSE);
	//	return;
	//}

	//define a menu
	//menu.CreatePopupMenu();
	//menu.AppendMenu(MF_STRING,ID_EDIT_UNDO,"Undo\tCtrl+Z");
	//menu.AppendMenu(MF_STRING,ID_EDIT_CUT,"Cut\tCtrl+X");

	//this->ClientToScreen(&point);
	//menu.TrackPopupMenu(TPM_LEFTALIGN,point.x, point.y,this);
	////pMenu->TrackPopupMenu(TPM_LEFTALIGN,point.x+10, point.y+10,this);

	CEditView::OnLButtonDown(nFlags, point);
}
