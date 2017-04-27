
// ExpSDIDoc.h : interface of the CExpSDIDoc class
//


#pragma once
#include "Letter.h"
#include <afxtempl.h>


class CExpSDIDoc : public CDocument
{
protected: // create from serialization only
	CExpSDIDoc();
	DECLARE_DYNCREATE(CExpSDIDoc)

// Attributes
public:
	char m_lLetter;
	CLetter m_Letter;
	CTypedPtrList<CObList,CLetter*> m_LetterList;

// Operations
public:
	void NewLetter(int x, int y);
	void DrawLetter(CDC* pDC);

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CExpSDIDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


