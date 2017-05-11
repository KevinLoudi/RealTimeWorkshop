
// VisibleAlogrithmDoc.cpp : implementation of the CVisibleAlogrithmDoc class
//

#include "stdafx.h"
#include "VisibleAlogrithm.h"

#include "VisibleAlogrithmDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CVisibleAlogrithmDoc

IMPLEMENT_DYNCREATE(CVisibleAlogrithmDoc, CDocument)

BEGIN_MESSAGE_MAP(CVisibleAlogrithmDoc, CDocument)
END_MESSAGE_MAP()


// CVisibleAlogrithmDoc construction/destruction

CVisibleAlogrithmDoc::CVisibleAlogrithmDoc()
{
	// TODO: add one-time construction code here

}

CVisibleAlogrithmDoc::~CVisibleAlogrithmDoc()
{
}

BOOL CVisibleAlogrithmDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CVisibleAlogrithmDoc serialization

void CVisibleAlogrithmDoc::Serialize(CArchive& ar)
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


// CVisibleAlogrithmDoc diagnostics

#ifdef _DEBUG
void CVisibleAlogrithmDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CVisibleAlogrithmDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CVisibleAlogrithmDoc commands
