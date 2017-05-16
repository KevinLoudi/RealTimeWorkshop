// MLPDoc.h : interface of the CMLPDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MLPDOC_H__12AA5972_FA9C_4D6A_B106_8C04AF5E75E8__INCLUDED_)
#define AFX_MLPDOC_H__12AA5972_FA9C_4D6A_B106_8C04AF5E75E8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMLPDoc : public CDocument
{
protected: // create from serialization only
	CMLPDoc();
	DECLARE_DYNCREATE(CMLPDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMLPDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	CString m_strText;
	virtual ~CMLPDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMLPDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MLPDOC_H__12AA5972_FA9C_4D6A_B106_8C04AF5E75E8__INCLUDED_)
