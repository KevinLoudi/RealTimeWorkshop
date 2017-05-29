// MAccess.h: interface for the MAccess class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MACCESS_H__FB838244_8375_43D8_B9D3_B721F06DE00C__INCLUDED_)
#define AFX_MACCESS_H__FB838244_8375_43D8_B9D3_B721F06DE00C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include"afxdb.h" 

class MAccess  
{
public:
	MAccess();
	virtual ~MAccess();

	BOOL ConnectDB(const char*szDNS,const char*szUID,const char*szAuthStr); 
	BOOL DisConnectDB();   //断开连接
	BOOL ExeSqlDirect(const char*szSQL);    //执行SQL语句
	SQLHENV m_henv;       //环境句柄
	SQLHDBC m_hdbc;       //连接句柄
	SQLHSTMT m_hstmt;     //文字句柄

};

#endif // !defined(AFX_MACCESS_H__FB838244_8375_43D8_B9D3_B721F06DE00C__INCLUDED_)
