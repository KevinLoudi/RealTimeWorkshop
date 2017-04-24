
// Exp1Doc.h : CExp1Doc 类的接口
//


#pragma once

//Database of the program
class CExp1Doc : public CDocument
{
protected: // 仅从序列化创建
	CExp1Doc();
	DECLARE_DYNCREATE(CExp1Doc)

// 属性
public:
	char* m_Text;

private:
	int Array[3];

// 操作
public:
	void SetMember(UINT ix, int x);
	int GetMember(UINT ix) const;

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// 实现
public:
	virtual ~CExp1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};


