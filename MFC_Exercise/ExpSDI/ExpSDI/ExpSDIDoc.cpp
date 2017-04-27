
// ExpSDIDoc.cpp : implementation of the CExpSDIDoc class
//

#include "stdafx.h"
#include "ExpSDI.h"

#include "ExpSDIDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExpSDIDoc

IMPLEMENT_DYNCREATE(CExpSDIDoc, CDocument)

BEGIN_MESSAGE_MAP(CExpSDIDoc, CDocument)
END_MESSAGE_MAP()


// CExpSDIDoc construction/destruction

CExpSDIDoc::CExpSDIDoc()
{
	// TODO: add one-time construction code here
	m_lLetter=' ';
}

CExpSDIDoc::~CExpSDIDoc()
{
}

void CExpSDIDoc::NewLetter(int x, int y)
{
	CLetter* pLetterItem=new CLetter('M',x,y);
	m_LetterList.AddTail(pLetterItem);
	SetModifiedFlag();
}

void CExpSDIDoc::DrawLetter(CDC* pDC)
{
	POSITION pos=m_LetterList.GetHeadPosition();
	while(pos!=NULL)
	{
		CLetter* letter=m_LetterList.GetNext(pos);
		//show letter on the specified position
		pDC->TextOut(letter->m_x-5,letter->m_y-5,CString(letter->m_sLetter));
	}
}

BOOL CExpSDIDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CExpSDIDoc serialization

void CExpSDIDoc::Serialize(CArchive& ar)
{
	//if (ar.IsStoring())
	//{
	//	// TODO: add storing code here
	//	ar<<m_lLetter;
	//}
	//else
	//{
	//	// TODO: add loading code here
	//	ar>>m_lLetter;
	//}
	m_Letter.Serialize(ar);
}


// CExpSDIDoc diagnostics

#ifdef _DEBUG
void CExpSDIDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CExpSDIDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CExpSDIDoc commands
