
// ExpMultiThreadDoc.cpp : implementation of the CExpMultiThreadDoc class
//

#include "stdafx.h"
#include "ExpMultiThread.h"

#include "ExpMultiThreadDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExpMultiThreadDoc

IMPLEMENT_DYNCREATE(CExpMultiThreadDoc, CDocument)

BEGIN_MESSAGE_MAP(CExpMultiThreadDoc, CDocument)
END_MESSAGE_MAP()


// CExpMultiThreadDoc construction/destruction

CExpMultiThreadDoc::CExpMultiThreadDoc()
{
	// TODO: add one-time construction code here

}

CExpMultiThreadDoc::~CExpMultiThreadDoc()
{
}

BOOL CExpMultiThreadDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CExpMultiThreadDoc serialization

void CExpMultiThreadDoc::Serialize(CArchive& ar)
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


// CExpMultiThreadDoc diagnostics

#ifdef _DEBUG
void CExpMultiThreadDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CExpMultiThreadDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CExpMultiThreadDoc commands
