
// Doc_ViewDoc.h : CDoc_ViewDoc 类的接口
//


#pragma once


class CDoc_ViewDoc : public CDocument
{
protected: // 仅从序列化创建
	CDoc_ViewDoc();
	DECLARE_DYNCREATE(CDoc_ViewDoc)

// 属性
public:
	int Array[3];

// 操作
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

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// 实现
public:
	virtual ~CDoc_ViewDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};


