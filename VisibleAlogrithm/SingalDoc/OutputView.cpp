// OutputView.cpp : ʵ���ļ�
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


// COutputView ��ͼ

void COutputView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: �������ͼ�ĺϼƴ�С
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
	// TODO: �ڴ���ӻ��ƴ���
	CString buf;
	buf.Format("Student No# = %d, Exam score = %d",pDoc->i_curStu.m_number, 
		pDoc->i_curStu.m_score);
	pDC->TextOut(0,100,buf);

}


// COutputView ���

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


// COutputView ��Ϣ�������
