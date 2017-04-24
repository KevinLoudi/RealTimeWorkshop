
// Exp3Doc.cpp : implementation of the CExp3Doc class
//

#include "stdafx.h"
#include "Exp3.h"

#include "Exp3Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExp3Doc

IMPLEMENT_DYNCREATE(CExp3Doc, CDocument)

BEGIN_MESSAGE_MAP(CExp3Doc, CDocument)
END_MESSAGE_MAP()


// CExp3Doc construction/destruction

CExp3Doc::CExp3Doc()
{
	// TODO: add one-time construction code here

}

CExp3Doc::~CExp3Doc()
{
}

BOOL CExp3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CExp3Doc serialization

void CExp3Doc::Serialize(CArchive& ar)
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


// CExp3Doc diagnostics

#ifdef _DEBUG
void CExp3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CExp3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CExp3Doc commands
