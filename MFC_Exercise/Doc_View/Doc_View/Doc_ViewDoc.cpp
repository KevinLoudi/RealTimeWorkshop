
// Doc_ViewDoc.cpp : CDoc_ViewDoc ���ʵ��
//

#include "stdafx.h"
#include "Doc_View.h"

#include "Doc_ViewDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDoc_ViewDoc

IMPLEMENT_DYNCREATE(CDoc_ViewDoc, CDocument)

BEGIN_MESSAGE_MAP(CDoc_ViewDoc, CDocument)
END_MESSAGE_MAP()


// CDoc_ViewDoc ����/����

CDoc_ViewDoc::CDoc_ViewDoc()
{
	// TODO: �ڴ����һ���Թ������
	for(int ix=0; ix<3; ++ix)
	{
		Array[ix]=0;
	}
}

CDoc_ViewDoc::~CDoc_ViewDoc()
{
}

BOOL CDoc_ViewDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CDoc_ViewDoc ���л�

void CDoc_ViewDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CDoc_ViewDoc ���

#ifdef _DEBUG
void CDoc_ViewDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDoc_ViewDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDoc_ViewDoc ����
