
// Exp2Doc.cpp : CExp2Doc ���ʵ��
//

#include "stdafx.h"
#include "Exp2.h"

#include "Exp2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExp2Doc

IMPLEMENT_DYNCREATE(CExp2Doc, CDocument)

BEGIN_MESSAGE_MAP(CExp2Doc, CDocument)
END_MESSAGE_MAP()


// CExp2Doc ����/����

CExp2Doc::CExp2Doc()
{
	// TODO: �ڴ����һ���Թ������

}

CExp2Doc::~CExp2Doc()
{
}

BOOL CExp2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CExp2Doc ���л�

void CExp2Doc::Serialize(CArchive& ar)
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


// CExp2Doc ���

#ifdef _DEBUG
void CExp2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CExp2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CExp2Doc ����
