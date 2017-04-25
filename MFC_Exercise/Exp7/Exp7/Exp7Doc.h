
// Exp7Doc.h : interface of the CExp7Doc class
//


#pragma once


class CExp7Doc : public CDocument
{
protected: // create from serialization only
	CExp7Doc();
	DECLARE_DYNCREATE(CExp7Doc)

// Attributes
public:
	CRect m_tagRect;
	CPoint m_Point;

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CExp7Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


