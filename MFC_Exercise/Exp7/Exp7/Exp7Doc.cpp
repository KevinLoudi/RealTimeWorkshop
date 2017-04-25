
// Exp7Doc.cpp : implementation of the CExp7Doc class
//

#include "stdafx.h"
#include "Exp7.h"

#include "Exp7Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExp7Doc

IMPLEMENT_DYNCREATE(CExp7Doc, CDocument)

BEGIN_MESSAGE_MAP(CExp7Doc, CDocument)
END_MESSAGE_MAP()


// CExp7Doc construction/destruction

CExp7Doc::CExp7Doc()
{
	// TODO: add one-time construction code here
	m_tagRect.left=30;
	m_tagRect.top=30;
	m_tagRect.right=350;
	m_tagRect.bottom=300;
}

CExp7Doc::~CExp7Doc()
{
}

BOOL CExp7Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CExp7Doc serialization

void CExp7Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}


// CExp7Doc diagnostics

#ifdef _DEBUG
void CExp7Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CExp7Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CExp7Doc commands
