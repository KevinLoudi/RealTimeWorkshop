
// Exp4View.h : interface of the CExp4View class
//


#pragma once


class CExp4View : public CListView
{
protected: // create from serialization only
	CExp4View();
	DECLARE_DYNCREATE(CExp4View)

// Attributes
public:
	CExp4Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct

// Implementation
public:
	virtual ~CExp4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in Exp4View.cpp
inline CExp4Doc* CExp4View::GetDocument() const
   { return reinterpret_cast<CExp4Doc*>(m_pDocument); }
#endif

