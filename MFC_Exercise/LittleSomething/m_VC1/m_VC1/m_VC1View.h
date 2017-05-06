
// m_VC1View.h : interface of the Cm_VC1View class
//


#pragma once


class Cm_VC1View : public CView
{
protected: // create from serialization only
	Cm_VC1View();
	DECLARE_DYNCREATE(Cm_VC1View)

// Attributes
public:
	Cm_VC1Doc* GetDocument() const;

// Operations
public:
	void Text1();
	void Text2(UINT x_pos, UINT y_pos);
	void Text3(float width, float height);
	void SetRectangle();

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~Cm_VC1View();
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
};

#ifndef _DEBUG  // debug version in m_VC1View.cpp
inline Cm_VC1Doc* Cm_VC1View::GetDocument() const
   { return reinterpret_cast<Cm_VC1Doc*>(m_pDocument); }
#endif

