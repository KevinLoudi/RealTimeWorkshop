// OutputView.cpp : 实现文件
//

#include "stdafx.h"
#include "SingalDocView.h"
#include "OutputView.h"
#include "SingalDocDoc.h"

// COutputView

IMPLEMENT_DYNCREATE(COutputView, CScrollView)

COutputView::COutputView()
{

}

COutputView::~COutputView()
{
}


BEGIN_MESSAGE_MAP(COutputView, CScrollView)
END_MESSAGE_MAP()


// COutputView 绘图

void COutputView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 计算此视图的合计大小
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

void COutputView::OnDraw(CDC* pDC)
{
	CSingalDocDoc* pDoc = (CSingalDocDoc*)GetDocument();
	if (pDoc==NULL)
	{
		ASSERT(FALSE);
		return;
	}
	// TODO: 在此添加绘制代码
	CString buf;
	buf.Format("Student No# = %d, Exam score = %d",pDoc->i_curStu.m_number, 
		pDoc->i_curStu.m_score);
	pDC->TextOut(0,100,buf);

}


// COutputView 诊断

#ifdef _DEBUG
void COutputView::AssertValid() const
{
	CScrollView::AssertValid();
}

#ifndef _WIN32_WCE
void COutputView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif
#endif //_DEBUG


// COutputView 消息处理程序
