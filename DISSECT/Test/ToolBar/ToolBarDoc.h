
// ToolBarDoc.h : interface of the CToolBarDoc class
//


#pragma once


class CToolBarDoc : public CDocument
{
protected: // create from serialization only
	CToolBarDoc();
	DECLARE_DYNCREATE(CToolBarDoc)

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
	virtual ~CToolBarDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


