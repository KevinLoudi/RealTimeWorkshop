// SerDoc.h : interface of the CSerDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SERDOC_H__419DF2B1_2184_4637_B9F0_F1FECBD1E498__INCLUDED_)
#define AFX_SERDOC_H__419DF2B1_2184_4637_B9F0_F1FECBD1E498__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSerDoc : public CDocument
{
protected: // create from serialization only
	CSerDoc();
	DECLARE_DYNCREATE(CSerDoc)

// Attributes
public:
	CString m_strName;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSerDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSerDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERDOC_H__419DF2B1_2184_4637_B9F0_F1FECBD1E498__INCLUDED_)
