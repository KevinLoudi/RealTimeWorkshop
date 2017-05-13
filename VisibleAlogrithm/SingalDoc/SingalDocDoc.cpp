
// SingalDocDoc.cpp : implementation of the CSingalDocDoc class
//

#include "stdafx.h"
#include "SingalDoc.h"

#include "SingalDocDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSingalDocDoc

IMPLEMENT_DYNCREATE(CSingalDocDoc, CDocument)

BEGIN_MESSAGE_MAP(CSingalDocDoc, CDocument)
END_MESSAGE_MAP()


// CSingalDocDoc construction/destruction

CSingalDocDoc::CSingalDocDoc()
{
	// TODO: add one-time construction code here
	Student stu;
	//stu.m_age=12;
	stu.m_number=1;
	stu.m_score=95;
	m_arrStu.Add(stu);

	//stu.m_age=11;
	stu.m_number=2;
	stu.m_score=75;
	m_arrStu.Add(stu);

	//stu.m_age=13;
	stu.m_number=3;
	stu.m_score=56;
	m_arrStu.Add(stu);

	i_curStu=m_arrStu[0];

}

CSingalDocDoc::~CSingalDocDoc()
{
}

BOOL CSingalDocDoc::SetCurrentStudent(int iStuNo)
{
	int i=-1;
	for (i=m_arrStu.GetSize()-1;i>=0; --i)
	{
		if (iStuNo==m_arrStu[i].m_number)
		{
			i_curStu=m_arrStu[i];
			break;
		}
	}

	if (i>=0)
	{
		return TRUE; //have found matches
	}
	else
	{
		return FALSE;
	}
}

BOOL CSingalDocDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CSingalDocDoc serialization

void CSingalDocDoc::Serialize(CArchive& ar)
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


// CSingalDocDoc diagnostics

#ifdef _DEBUG
void CSingalDocDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSingalDocDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSingalDocDoc commands
