
// SingalDocView.h : interface of the CSingalDocView class
//


#pragma once
#include "SingalDocDoc.h"
#include "Resource.h"


class CSingalDocView : public CFormView
{
protected: // create from serialization only
	CSingalDocView();
	DECLARE_DYNCREATE(CSingalDocView)

public:
	enum{ IDD = IDD_SINGALDOC_FORM };

// Attributes
public:
	CSingalDocDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct

// Implementation
public:
	virtual ~CSingalDocView();
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
	// Input student number
	int m_iStuNo;
	afx_msg void OnBnClickedFind();
};

#ifndef _DEBUG  // debug version in SingalDocView.cpp
inline CSingalDocDoc* CSingalDocView::GetDocument() const
   { return reinterpret_cast<CSingalDocDoc*>(m_pDocument); }
#endif

