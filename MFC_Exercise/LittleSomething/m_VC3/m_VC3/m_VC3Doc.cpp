
// m_VC3Doc.cpp : implementation of the Cm_VC3Doc class
//

#include "stdafx.h"
#include "m_VC3.h"

#include "m_VC3Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cm_VC3Doc

IMPLEMENT_DYNCREATE(Cm_VC3Doc, CDocument)

BEGIN_MESSAGE_MAP(Cm_VC3Doc, CDocument)
END_MESSAGE_MAP()


// Cm_VC3Doc construction/destruction

Cm_VC3Doc::Cm_VC3Doc()
{
	// TODO: add one-time construction code here

}

Cm_VC3Doc::~Cm_VC3Doc()
{
}

BOOL Cm_VC3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// Cm_VC3Doc serialization

void Cm_VC3Doc::Serialize(CArchive& ar)
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


// Cm_VC3Doc diagnostics

#ifdef _DEBUG
void Cm_VC3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void Cm_VC3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Cm_VC3Doc commands
