// MLPDoc.cpp : implementation of the CMLPDoc class
//

#include "stdafx.h"
#include "MLP.h"

#include "MLPDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMLPDoc

IMPLEMENT_DYNCREATE(CMLPDoc, CDocument)

BEGIN_MESSAGE_MAP(CMLPDoc, CDocument)
	//{{AFX_MSG_MAP(CMLPDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMLPDoc construction/destruction

CMLPDoc::CMLPDoc()
{
	// TODO: add one-time construction code here
	m_strText="";

}

CMLPDoc::~CMLPDoc()
{
}

BOOL CMLPDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMLPDoc serialization

void CMLPDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		//ar<<m_strText;
	}
	else
	{
		// TODO: add loading code here
		//ar>>m_strText;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMLPDoc diagnostics

#ifdef _DEBUG
void CMLPDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMLPDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMLPDoc commands
