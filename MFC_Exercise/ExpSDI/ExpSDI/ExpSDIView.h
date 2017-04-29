
// ExpSDIView.h : interface of the CExpSDIView class
//


#pragma once


class CExpSDIView : public CView
{
protected: // create from serialization only
	CExpSDIView();
	DECLARE_DYNCREATE(CExpSDIView)

// Attributes
public:
	CExpSDIDoc* GetDocument() const;


// Operations
public:
	CStatic m_label1;
	CButton m_button1;
	CButton m_button2;
	CEdit	m_edit1;

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CExpSDIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	//CFont m_spinEditFont;
	CSpinButtonCtrl m_spin;
	CEdit m_spinEdit;				//object related to spin controler
	void	InitSpinner();				//initial spin controler

	CProgressCtrl m_progBar1, m_progBar2;
	void InitProgressBar();

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnButton1Clicked();
	afx_msg void OnButton2Clicked();
	afx_msg void OnMaxText();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // debug version in ExpSDIView.cpp
inline CExpSDIDoc* CExpSDIView::GetDocument() const
   { return reinterpret_cast<CExpSDIDoc*>(m_pDocument); }
#endif

