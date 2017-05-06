
// m_VC2Doc.h : interface of the Cm_VC2Doc class
//


#pragma once


class Cm_VC2Doc : public CDocument
{
protected: // create from serialization only
	Cm_VC2Doc();
	DECLARE_DYNCREATE(Cm_VC2Doc)

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
	virtual ~Cm_VC2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


