
// Exp5Doc.h : interface of the CExp5Doc class
//


#pragma once


class CExp5Doc : public CDocument
{
protected: // create from serialization only
	CExp5Doc();
	DECLARE_DYNCREATE(CExp5Doc)

// Attributes
public:
	CArray<CRect,CRect&>m_Rectag; //CRect array

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CExp5Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


