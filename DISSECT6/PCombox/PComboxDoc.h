// PComboxDoc.h : interface of the CPComboxDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCOMBOXDOC_H__AD52DB11_D9CE_40B9_AF2C_1DDC8282F8CD__INCLUDED_)
#define AFX_PCOMBOXDOC_H__AD52DB11_D9CE_40B9_AF2C_1DDC8282F8CD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPComboxDoc : public CDocument
{
protected: // create from serialization only
	CPComboxDoc();
	DECLARE_DYNCREATE(CPComboxDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPComboxDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPComboxDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPComboxDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PCOMBOXDOC_H__AD52DB11_D9CE_40B9_AF2C_1DDC8282F8CD__INCLUDED_)
