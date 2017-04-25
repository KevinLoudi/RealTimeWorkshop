
// Exp6Doc.cpp : implementation of the CExp6Doc class
//

#include "stdafx.h"
#include "Exp6.h"

#include "Exp6Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExp6Doc

IMPLEMENT_DYNCREATE(CExp6Doc, CDocument)

BEGIN_MESSAGE_MAP(CExp6Doc, CDocument)
END_MESSAGE_MAP()


// CExp6Doc construction/destruction

CExp6Doc::CExp6Doc()
{
	// TODO: add one-time construction code here
	m_Rectag.SetSize(256,256);
}

CExp6Doc::~CExp6Doc()
{
}

BOOL CExp6Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CExp6Doc serialization

void CExp6Doc::Serialize(CArchive& ar)
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


// CExp6Doc diagnostics

#ifdef _DEBUG
void CExp6Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CExp6Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CExp6Doc commands
