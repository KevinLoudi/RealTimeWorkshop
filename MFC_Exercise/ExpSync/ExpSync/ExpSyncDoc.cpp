
// ExpSyncDoc.cpp : implementation of the CExpSyncDoc class
//

#include "stdafx.h"
#include "ExpSync.h"

#include "ExpSyncDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExpSyncDoc

IMPLEMENT_DYNCREATE(CExpSyncDoc, CDocument)

BEGIN_MESSAGE_MAP(CExpSyncDoc, CDocument)
END_MESSAGE_MAP()


// CExpSyncDoc construction/destruction

CExpSyncDoc::CExpSyncDoc()
{
	// TODO: add one-time construction code here

}

CExpSyncDoc::~CExpSyncDoc()
{
}

BOOL CExpSyncDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CExpSyncDoc serialization

void CExpSyncDoc::Serialize(CArchive& ar)
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


// CExpSyncDoc diagnostics

#ifdef _DEBUG
void CExpSyncDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CExpSyncDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CExpSyncDoc commands
