
// Exp1Doc.cpp : CExp1Doc ���ʵ��
//

#include "stdafx.h"
#include "Exp1.h"

#include "Exp1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExp1Doc

IMPLEMENT_DYNCREATE(CExp1Doc, CDocument)

BEGIN_MESSAGE_MAP(CExp1Doc, CDocument)
END_MESSAGE_MAP()


// CExp1Doc ����/����

CExp1Doc::CExp1Doc()
{
	// TODO: �ڴ����һ���Թ������
	for (UINT ix=0; ix<3; ++ix)
	{
		Array[ix]=0;
	}

	m_Text="Today is another day!!";

}

CExp1Doc::~CExp1Doc()
{

}

void CExp1Doc::SetMember(UINT ix, int x)
{
	Array[ix]=x;
}

int CExp1Doc::GetMember(UINT ix) const
{
	return Array[ix];
}

BOOL CExp1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CExp1Doc ���л�

void CExp1Doc::Serialize(CArchive& ar)
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


// CExp1Doc ���

#ifdef _DEBUG
void CExp1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CExp1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CExp1Doc ����
