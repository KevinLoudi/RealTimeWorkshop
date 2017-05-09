
// m_VC3View.h : interface of the Cm_VC3View class
//


#pragma once


class Cm_VC3View : public CView
{
protected: // create from serialization only
	Cm_VC3View();
	DECLARE_DYNCREATE(Cm_VC3View)

// Attributes
public:
	Cm_VC3Doc* GetDocument() const;

// Operations
public:
	//pDc: Device context pointer,    col: color of brush,    point: point of rectangle top-left 
	//len: rectangle length,     height: rectangle hight
	void FillRect0(CDC* pDc, COLORREF col, CPoint point, int len,int height);
	//pDc: Device context pointer,    (x1,y1):start point ,     (x2,y2): stop point, 
	//swid:line width,     scol:line color
	void Line0(CDC* pDc,UINT x1,UINT y1, UINT x2, UINT y2, UINT swid,
		COLORREF scol);

	//calculation of sin-cos functions
	void Sin0();
	void Cos0();
	void SinCos0();

	//do plot
	void Axis(CDC* pDc);
	void Curve(CDC* pDc);


// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	#define PI 3.1415926
	#define SCREEN_SIZE 722

	COLORREF col_back; //background color
	double h_ratio, poi_x[SCREEN_SIZE], poi_y[SCREEN_SIZE]; //script ratio and position
	int par_m, par_z; //parmeters for screen showing
	virtual ~Cm_VC3View();
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

#ifndef _DEBUG  // debug version in m_VC3View.cpp
inline Cm_VC3Doc* Cm_VC3View::GetDocument() const
   { return reinterpret_cast<Cm_VC3Doc*>(m_pDocument); }
#endif

