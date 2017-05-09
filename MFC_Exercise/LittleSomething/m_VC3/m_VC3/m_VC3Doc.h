
// m_VC3Doc.h : interface of the Cm_VC3Doc class
//


#pragma once


class Cm_VC3Doc : public CDocument
{
protected: // create from serialization only
	Cm_VC3Doc();
	DECLARE_DYNCREATE(Cm_VC3Doc)

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
	virtual ~Cm_VC3Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


