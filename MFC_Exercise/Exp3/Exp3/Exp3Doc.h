
// Exp3Doc.h : interface of the CExp3Doc class
//


#pragma once


class CExp3Doc : public CDocument
{
protected: // create from serialization only
	CExp3Doc();
	DECLARE_DYNCREATE(CExp3Doc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CExp3Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


