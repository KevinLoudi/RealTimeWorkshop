
// VisibleAlogrithmDoc.h : interface of the CVisibleAlogrithmDoc class
//


#pragma once


class CVisibleAlogrithmDoc : public CDocument
{
protected: // create from serialization only
	CVisibleAlogrithmDoc();
	DECLARE_DYNCREATE(CVisibleAlogrithmDoc)

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
	virtual ~CVisibleAlogrithmDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


