
// Exp4Doc.cpp : implementation of the CExp4Doc class
//

#include "stdafx.h"
#include "Exp4.h"

#include "Exp4Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExp4Doc

IMPLEMENT_DYNCREATE(CExp4Doc, CDocument)

BEGIN_MESSAGE_MAP(CExp4Doc, CDocument)
END_MESSAGE_MAP()


// CExp4Doc construction/destruction

CExp4Doc::CExp4Doc()
{
	// TODO: add one-time construction code here

}

CExp4Doc::~CExp4Doc()
{
}

BOOL CExp4Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CExp4Doc serialization

void CExp4Doc::Serialize(CArchive& ar)
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


// CExp4Doc diagnostics

#ifdef _DEBUG
void CExp4Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CExp4Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CExp4Doc commands
