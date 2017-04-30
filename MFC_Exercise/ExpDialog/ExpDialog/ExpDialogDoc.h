
// ExpDialogDoc.h : interface of the CExpDialogDoc class
//


#pragma once


class CExpDialogDoc : public CDocument
{
protected: // create from serialization only
	CExpDialogDoc();
	DECLARE_DYNCREATE(CExpDialogDoc)

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
	virtual ~CExpDialogDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


