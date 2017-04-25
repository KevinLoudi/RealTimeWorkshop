
// Exp8View.h : interface of the CExp8View class
//


#pragma once


class CExp8View : public CView
{
protected: // create from serialization only
	CExp8View();
	DECLARE_DYNCREATE(CExp8View)

// Attributes
public:
	CExp8Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnSetFocus(CWnd* pOldWnd);
	virtual void OnKillFocus(CWnd* pNewWnd);
protected:

// Implementation
public:
	virtual ~CExp8View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in Exp8View.cpp
inline CExp8Doc* CExp8View::GetDocument() const
   { return reinterpret_cast<CExp8Doc*>(m_pDocument); }
#endif

