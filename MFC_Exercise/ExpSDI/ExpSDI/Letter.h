#pragma once

// CLetter ����Ŀ��

class CLetter : public CObject
{
private:
	DECLARE_SERIAL(CLetter)
	char m_sLetter;
	int m_x, m_y;
public:
	CLetter();
	CLetter(char ch, int x, int y);
	virtual void Serialize(CArchive& ar);
	void SetLetter(char ch);
	char GetLetter();
	virtual ~CLetter();
};


