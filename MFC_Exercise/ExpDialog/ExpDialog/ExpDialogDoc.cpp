
// ExpDialogDoc.cpp : implementation of the CExpDialogDoc class
//

#include "stdafx.h"
#include "ExpDialog.h"

#include "ExpDialogDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExpDialogDoc

IMPLEMENT_DYNCREATE(CExpDialogDoc, CDocument)

BEGIN_MESSAGE_MAP(CExpDialogDoc, CDocument)
END_MESSAGE_MAP()


// CExpDialogDoc construction/destruction

CExpDialogDoc::CExpDialogDoc()
{
	// TODO: add one-time construction code here

}

CExpDialogDoc::~CExpDialogDoc()
{
}

BOOL CExpDialogDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CExpDialogDoc serialization

void CExpDialogDoc::Serialize(CArchive& ar)
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


// CExpDialogDoc diagnostics

#ifdef _DEBUG
void CExpDialogDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CExpDialogDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CExpDialogDoc commands
