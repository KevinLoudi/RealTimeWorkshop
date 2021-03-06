
// m_VC2View.h : interface of the Cm_VC2View class
//


#pragma once


class Cm_VC2View : public CView
{
protected: // create from serialization only
	Cm_VC2View();
	DECLARE_DYNCREATE(Cm_VC2View)

// Attributes
public:
	Cm_VC2Doc* GetDocument() const;

// Operations
public:
	//1,2:color of brush,3:left-top point of rectangle, 4:width of rectangle, 
	void FillRect0(CDC* pDc, COLORREF col, CPoint point, int chd,int kd);
	void Rectangle0(CDC* pDc,UINT top_left,UINT bottom_left, UINT top_right, UINT bottom_right,
		COLORREF col);
  
	void Line0(CDC* pDc,UINT x1,UINT y1, UINT x2, UINT y2, UINT swid,
		COLORREF scol);
	//mb: brush type
	void Ellipse0(CDC* pDc,UINT left,UINT top, UINT right, UINT bottom, UINT swid,
		COLORREF scol,BOOL mb); 

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~Cm_VC2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in m_VC2View.cpp
inline Cm_VC2Doc* Cm_VC2View::GetDocument() const
   { return reinterpret_cast<Cm_VC2Doc*>(m_pDocument); }
#endif

