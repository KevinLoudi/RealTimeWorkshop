
// Doc_ViewView.h : CDoc_ViewView ��Ľӿ�
//


#pragma once


class CDoc_ViewView : public CView
{
protected: // �������л�����
	CDoc_ViewView();
	DECLARE_DYNCREATE(CDoc_ViewView)

// ����
public:
	CDoc_ViewDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CDoc_ViewView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Doc_ViewView.cpp �еĵ��԰汾
inline CDoc_ViewDoc* CDoc_ViewView::GetDocument() const
   { return reinterpret_cast<CDoc_ViewDoc*>(m_pDocument); }
#endif

