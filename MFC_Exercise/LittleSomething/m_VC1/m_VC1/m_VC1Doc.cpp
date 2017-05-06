
// m_VC1Doc.cpp : implementation of the Cm_VC1Doc class
//

#include "stdafx.h"
#include "m_VC1.h"

#include "m_VC1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cm_VC1Doc

IMPLEMENT_DYNCREATE(Cm_VC1Doc, CDocument)

BEGIN_MESSAGE_MAP(Cm_VC1Doc, CDocument)
END_MESSAGE_MAP()


// Cm_VC1Doc construction/destruction

Cm_VC1Doc::Cm_VC1Doc()
{
	// TODO: add one-time construction code here

}

Cm_VC1Doc::~Cm_VC1Doc()
{
}

BOOL Cm_VC1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// Cm_VC1Doc serialization

void Cm_VC1Doc::Serialize(CArchive& ar)
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


// Cm_VC1Doc diagnostics

#ifdef _DEBUG
void Cm_VC1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void Cm_VC1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Cm_VC1Doc commands
