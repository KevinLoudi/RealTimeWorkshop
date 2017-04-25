
// Exp7View.h : interface of the CExp7View class
//


#pragma once


class CExp7View : public CView
{
protected: // create from serialization only
	CExp7View();
	DECLARE_DYNCREATE(CExp7View)

// Attributes
public:
	CExp7Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CExp7View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnNcMouseMove(UINT nHitTest, CPoint point);
};

#ifndef _DEBUG  // debug version in Exp7View.cpp
inline CExp7Doc* CExp7View::GetDocument() const
   { return reinterpret_cast<CExp7Doc*>(m_pDocument); }
#endif

