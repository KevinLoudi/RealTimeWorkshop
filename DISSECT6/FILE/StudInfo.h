// StudInfo.h: interface for the StudInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STUDINFO_H__8228CF30_3BB4_4660_80C2_1FB9B10C9C16__INCLUDED_)
#define AFX_STUDINFO_H__8228CF30_3BB4_4660_80C2_1FB9B10C9C16__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class StudInfo  
{
public:
	StudInfo();
	virtual ~StudInfo();
	bool CstrToChar(char m_char[],CString &str, int char_len=10) ;//convert CString to char[]

public:
	char m_name[10];
	char m_num[15];
	char m_major[20];

};	

#endif // !defined(AFX_STUDINFO_H__8228CF30_3BB4_4660_80C2_1FB9B10C9C16__INCLUDED_)
