// PComboxDoc.cpp : implementation of the CPComboxDoc class
//

#include "stdafx.h"
#include "PCombox.h"

#include "PComboxDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPComboxDoc

IMPLEMENT_DYNCREATE(CPComboxDoc, CDocument)

BEGIN_MESSAGE_MAP(CPComboxDoc, CDocument)
	//{{AFX_MSG_MAP(CPComboxDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPComboxDoc construction/destruction

CPComboxDoc::CPComboxDoc()
{
	// TODO: add one-time construction code here

}

CPComboxDoc::~CPComboxDoc()
{
}

BOOL CPComboxDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	((CEditView*)m_viewList.GetHead())->SetWindowText(NULL);

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPComboxDoc serialization

void CPComboxDoc::Serialize(CArchive& ar)
{
	// CEditView contains an edit control which handles all serialization
	((CEditView*)m_viewList.GetHead())->SerializeRaw(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CPComboxDoc diagnostics

#ifdef _DEBUG
void CPComboxDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPComboxDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPComboxDoc commands
