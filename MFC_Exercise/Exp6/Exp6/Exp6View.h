
// Exp6View.h : interface of the CExp6View class
//


#pragma once


class CExp6View : public CScrollView
{
protected: // create from serialization only
	CExp6View();
	DECLARE_DYNCREATE(CExp6View)

// Attributes
public:
	CExp6Doc* GetDocument() const;
	CDrawRect* m_ViewDrRect; 

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct

// Implementation
public:
	virtual ~CExp6View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	//afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in Exp6View.cpp
inline CExp6Doc* CExp6View::GetDocument() const
   { return reinterpret_cast<CExp6Doc*>(m_pDocument); }
#endif

