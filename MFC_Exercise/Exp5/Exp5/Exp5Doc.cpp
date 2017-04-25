
// Exp5Doc.cpp : implementation of the CExp5Doc class
//

#include "stdafx.h"
#include "Exp5.h"

#include "Exp5Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExp5Doc

IMPLEMENT_DYNCREATE(CExp5Doc, CDocument)

BEGIN_MESSAGE_MAP(CExp5Doc, CDocument)
END_MESSAGE_MAP()


// CExp5Doc construction/destruction

CExp5Doc::CExp5Doc()
{
	// TODO: add one-time construction code here
	m_Rectag.SetSize(256,256);
}

CExp5Doc::~CExp5Doc()
{
}

BOOL CExp5Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CExp5Doc serialization

void CExp5Doc::Serialize(CArchive& ar)
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


// CExp5Doc diagnostics

#ifdef _DEBUG
void CExp5Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CExp5Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CExp5Doc commands
