
// ExpMultiThreadDoc.h : interface of the CExpMultiThreadDoc class
//


#pragma once


class CExpMultiThreadDoc : public CDocument
{
protected: // create from serialization only
	CExpMultiThreadDoc();
	DECLARE_DYNCREATE(CExpMultiThreadDoc)

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
	virtual ~CExpMultiThreadDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


