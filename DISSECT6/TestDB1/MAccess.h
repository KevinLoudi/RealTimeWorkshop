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
	BOOL DisConnectDB();   //�Ͽ�����
	BOOL ExeSqlDirect(const char*szSQL);    //ִ��SQL���
	SQLHENV m_henv;       //�������
	SQLHDBC m_hdbc;       //���Ӿ��
	SQLHSTMT m_hstmt;     //���־��

};

#endif // !defined(AFX_MACCESS_H__FB838244_8375_43D8_B9D3_B721F06DE00C__INCLUDED_)
