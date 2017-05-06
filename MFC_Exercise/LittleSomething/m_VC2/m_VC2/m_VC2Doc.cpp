
// m_VC2Doc.cpp : implementation of the Cm_VC2Doc class
//

#include "stdafx.h"
#include "m_VC2.h"

#include "m_VC2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cm_VC2Doc

IMPLEMENT_DYNCREATE(Cm_VC2Doc, CDocument)

BEGIN_MESSAGE_MAP(Cm_VC2Doc, CDocument)
END_MESSAGE_MAP()


// Cm_VC2Doc construction/destruction

Cm_VC2Doc::Cm_VC2Doc()
{
	// TODO: add one-time construction code here

}

Cm_VC2Doc::~Cm_VC2Doc()
{
}

BOOL Cm_VC2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// Cm_VC2Doc serialization

void Cm_VC2Doc::Serialize(CArchive& ar)
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


// Cm_VC2Doc diagnostics

#ifdef _DEBUG
void Cm_VC2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void Cm_VC2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Cm_VC2Doc commands
