
// Exp2Doc.cpp : CExp2Doc 类的实现
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


// CExp2Doc 构造/析构

CExp2Doc::CExp2Doc()
{
	// TODO: 在此添加一次性构造代码

}

CExp2Doc::~CExp2Doc()
{
}

BOOL CExp2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CExp2Doc 序列化

void CExp2Doc::Serialize(CArchive& ar)
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


// CExp2Doc 诊断

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


// CExp2Doc 命令
