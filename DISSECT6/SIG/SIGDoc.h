// SIGDoc.h : interface of the CSIGDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SIGDOC_H__EBAE238F_9D6A_4033_B7F5_8D7318E52C82__INCLUDED_)
#define AFX_SIGDOC_H__EBAE238F_9D6A_4033_B7F5_8D7318E52C82__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSIGDoc : public CDocument
{
protected: // create from serialization only
	CSIGDoc();
	DECLARE_DYNCREATE(CSIGDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSIGDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	int m_clickTimes;
    CString m_strText;
	virtual ~CSIGDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSIGDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIGDOC_H__EBAE238F_9D6A_4033_B7F5_8D7318E52C82__INCLUDED_)
