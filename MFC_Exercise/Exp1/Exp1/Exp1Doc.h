
// Exp1Doc.h : CExp1Doc ��Ľӿ�
//


#pragma once

//Database of the program
class CExp1Doc : public CDocument
{
protected: // �������л�����
	CExp1Doc();
	DECLARE_DYNCREATE(CExp1Doc)

// ����
public:
	char* m_Text;

private:
	int Array[3];

// ����
public:
	void SetMember(UINT ix, int x);
	int GetMember(UINT ix) const;

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CExp1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


