// Letter.cpp : 实现文件
//

#include "stdafx.h"
#include "ExpSDI.h"
#include "Letter.h"


// CLetter
IMPLEMENT_SERIAL(CLetter,CObject,1)

CLetter::CLetter()
{
	//m_sLetter=' ';
}

CLetter::CLetter(char ch, int x, int y)
{
	m_sLetter=ch; m_x=x; m_y=y;
}

void CLetter::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar<<m_sLetter<<m_x<<m_y;
	} 
	else
	{
		ar>>m_sLetter>>m_x>>m_y;
	}
}

void CLetter::SetLetter(char ch)
{
	m_sLetter=ch;
}

char CLetter::GetLetter()
{
	return m_sLetter;
}

CLetter::~CLetter()
{
}


// CLetter 成员函数
