
// SingalDocDoc.h : interface of the CSingalDocDoc class
//


#pragma once

#include <afxtempl.h>

class _declspec(dllimport) Student
{
public:
	Student(void);
	~Student(void);
	bool SetAge(int iAge);

public:
	int m_number;
	int m_score;

private:
	int m_age;
};

class CSingalDocDoc : public CDocument
{
protected: // create from serialization only
	CSingalDocDoc();
	DECLARE_DYNCREATE(CSingalDocDoc)

// Attributes
public:
	Student i_curStu;

// Operations
public:
	//set i_curStu
	BOOL SetCurrentStudent(int iStuNo);

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CSingalDocDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CArray<Student, Student&> m_arrStu;

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


