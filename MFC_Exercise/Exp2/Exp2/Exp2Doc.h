
// Exp2Doc.h : CExp2Doc ��Ľӿ�
//


#pragma once


class CExp2Doc : public CDocument
{
protected: // �������л�����
	CExp2Doc();
	DECLARE_DYNCREATE(CExp2Doc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CExp2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


