
// Exp1Doc.cpp : CExp1Doc 类的实现
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


// CExp1Doc 构造/析构

CExp1Doc::CExp1Doc()
{
	// TODO: 在此添加一次性构造代码
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

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CExp1Doc 序列化

void CExp1Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CExp1Doc 诊断

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


// CExp1Doc 命令
