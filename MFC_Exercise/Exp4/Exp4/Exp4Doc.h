
// Exp4Doc.h : interface of the CExp4Doc class
//


#pragma once


class CExp4Doc : public CDocument
{
protected: // create from serialization only
	CExp4Doc();
	DECLARE_DYNCREATE(CExp4Doc)

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
	virtual ~CExp4Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


