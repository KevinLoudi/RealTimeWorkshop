
// ExpSyncDoc.h : interface of the CExpSyncDoc class
//


#pragma once


class CExpSyncDoc : public CDocument
{
protected: // create from serialization only
	CExpSyncDoc();
	DECLARE_DYNCREATE(CExpSyncDoc)

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
	virtual ~CExpSyncDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


