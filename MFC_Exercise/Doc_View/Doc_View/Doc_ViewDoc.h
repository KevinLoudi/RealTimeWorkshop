
// Doc_ViewDoc.h : CDoc_ViewDoc ��Ľӿ�
//


#pragma once


class CDoc_ViewDoc : public CDocument
{
protected: // �������л�����
	CDoc_ViewDoc();
	DECLARE_DYNCREATE(CDoc_ViewDoc)

// ����
public:
	int Array[3];

// ����
public:
	void SetMember(UINT ix, int m)
	{
		Array[ix]=m;
		return;
	}

	int GetMember(UINT ix)
	{
		return Array[ix];
	}

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CDoc_ViewDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


