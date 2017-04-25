
// Exp8Doc.h : interface of the CExp8Doc class
//


#pragma once


class CExp8Doc : public CDocument
{
protected: // create from serialization only
	CExp8Doc();
	DECLARE_DYNCREATE(CExp8Doc)

// Attributes
public:
	CRect m_crlRect;
	CString m_pStr;

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CExp8Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


