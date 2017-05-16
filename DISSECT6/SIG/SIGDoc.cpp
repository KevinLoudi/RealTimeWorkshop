// SIGDoc.cpp : implementation of the CSIGDoc class
//

#include "stdafx.h"
#include "SIG.h"

#include "SIGDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSIGDoc

IMPLEMENT_DYNCREATE(CSIGDoc, CDocument)

BEGIN_MESSAGE_MAP(CSIGDoc, CDocument)
	//{{AFX_MSG_MAP(CSIGDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSIGDoc construction/destruction

CSIGDoc::CSIGDoc()
{
	// TODO: add one-time construction code here
	m_strText="";
	m_clickTimes=0;

}

CSIGDoc::~CSIGDoc()
{
}

BOOL CSIGDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSIGDoc serialization

void CSIGDoc::Serialize(CArchive& ar)
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

/////////////////////////////////////////////////////////////////////////////
// CSIGDoc diagnostics

#ifdef _DEBUG
void CSIGDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSIGDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSIGDoc commands
