
// Doc_ViewDoc.cpp : CDoc_ViewDoc 类的实现
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


// CDoc_ViewDoc 构造/析构

CDoc_ViewDoc::CDoc_ViewDoc()
{
	// TODO: 在此添加一次性构造代码
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

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CDoc_ViewDoc 序列化

void CDoc_ViewDoc::Serialize(CArchive& ar)
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


// CDoc_ViewDoc 诊断

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


// CDoc_ViewDoc 命令
