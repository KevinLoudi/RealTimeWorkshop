
// NotePadView.h : interface of the CNotePadView class
//


#pragma once


class CNotePadView : public CEditView
{
protected: // create from serialization only
	CNotePadView();
	DECLARE_DYNCREATE(CNotePadView)

// Attributes
public:
	CNotePadDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CNotePadView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStyleFont();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in NotePadView.cpp
inline CNotePadDoc* CNotePadView::GetDocument() const
   { return reinterpret_cast<CNotePadDoc*>(m_pDocument); }
#endif

