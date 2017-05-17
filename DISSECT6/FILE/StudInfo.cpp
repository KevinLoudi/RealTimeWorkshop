// StudInfo.cpp: implementation of the StudInfo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "FILE.h"
#include "StudInfo.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

StudInfo::StudInfo()
{

}

StudInfo::~StudInfo()
{

}

bool StudInfo::CstrToChar(char m_char[],CString &str,int char_len)
{
	int len=str.GetLength();
	if (len>char_len-1)
	{
		//shortage of space
		return false;
	}
	memcpy(m_char,str.GetBuffer(len),len);
	m_char[len]=0;
	return true;
	
}
