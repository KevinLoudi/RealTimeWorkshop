
// Exp6Doc.h : interface of the CExp6Doc class
//


#pragma once


class CExp6Doc : public CDocument
{
protected: // create from serialization only
	CExp6Doc();
	DECLARE_DYNCREATE(CExp6Doc)

// Attributes
public:
	CArray<CRect,CRect&>m_Rectag; //CRect array
	CArray<CRect,CRect&>m_Drawtag;
// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CExp6Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


