// SerDoc.cpp : implementation of the CSerDoc class
//

#include "stdafx.h"
#include "Ser.h"

#include "SerDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSerDoc

IMPLEMENT_DYNCREATE(CSerDoc, CDocument)

BEGIN_MESSAGE_MAP(CSerDoc, CDocument)
	//{{AFX_MSG_MAP(CSerDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSerDoc construction/destruction

CSerDoc::CSerDoc()
{
	// TODO: add one-time construction code here
	m_strName="Kevin";

}

CSerDoc::~CSerDoc()
{
}

BOOL CSerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	//SetTitle("Secret");

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSerDoc serialization

void CSerDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		ar<<m_strName;
	}
	else
	{
		// TODO: add loading code here
		CString strTmp;
		ar<<strTmp;
		AfxMessageBox(strTmp);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CSerDoc diagnostics

#ifdef _DEBUG
void CSerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSerDoc commands
