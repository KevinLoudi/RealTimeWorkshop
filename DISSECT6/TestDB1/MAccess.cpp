// MAccess.cpp: implementation of the MAccess class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TestDB1.h"
#include "MAccess.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MAccess::MAccess()
{
	this->m_hdbc=NULL;
	this->m_henv=NULL;
	this->m_hstmt=NULL;
}

MAccess::~MAccess()
{
	DisConnectDB();
}

BOOL MAccess::ConnectDB(const char*szDNS,const char*szUID,const char*szAuthStr)
{
	SQLRETURN ret;
	ret=SQLAllocHandle(SQL_HANDLE_ENV,SQL_NULL_HANDLE,&m_henv);
	if((ret!=SQL_SUCCESS) && (ret!=SQL_SUCCESS_WITH_INFO))
	{
		AfxMessageBox("���价�����ʧ�ܣ�");
		return FALSE;
	}
	ret=SQLSetEnvAttr(m_henv,SQL_ATTR_ODBC_VERSION,(void*)SQL_OV_ODBC3,0);
	if((ret!=SQL_SUCCESS) && (ret!=SQL_SUCCESS_WITH_INFO))
	{
		AfxMessageBox("���û������ԣ�");
		return FALSE;
	}
	ret=SQLAllocHandle(SQL_HANDLE_DBC,m_henv,&m_hdbc);
	if((ret!=SQL_SUCCESS) && (ret!=SQL_SUCCESS_WITH_INFO))
	{
		AfxMessageBox("�������Ӿ��ʧ�ܣ�");
		return FALSE;
	}
	ret=SQLConnect(m_hdbc,(SQLTCHAR*)szDNS,SQL_NTS,(SQLTCHAR*)szUID,SQL_NTS,(SQLTCHAR*)szAuthStr,SQL_NTS);
	if((ret!=SQL_SUCCESS) && (ret!=SQL_SUCCESS_WITH_INFO))
	{
		AfxMessageBox("�������ݿ�ʧ�ܣ�");
		return FALSE;
	}
return TRUE;	
}

BOOL MAccess::DisConnectDB()
{
	if(this->m_hdbc!=NULL)
	{
		SQLFreeHandle(SQL_HANDLE_DBC,m_hdbc);
		m_hdbc=NULL;
	}
	if(this->m_henv!=NULL)
	{
		SQLFreeHandle(SQL_HANDLE_ENV,m_henv);
		m_henv=NULL;
	}
	if(this->m_hstmt!=NULL)
	{
		SQLFreeHandle(SQL_HANDLE_STMT,m_hstmt);
		m_hstmt=NULL;
	}
	return TRUE;	
}

BOOL MAccess::ExeSqlDirect(const char*szSQL)
{
	SQLRETURN retcode;
	if(m_hstmt!=NULL)
	{
		SQLFreeHandle(SQL_HANDLE_STMT,m_hstmt);
		m_hstmt=NULL;
	}
	if(this->m_hdbc==NULL)
	{
		AfxMessageBox("δ���������ݿ⣬���Ƚ������ӣ�");
		return FALSE;
	}
	retcode=SQLAllocHandle(SQL_HANDLE_STMT,m_hdbc,&m_hstmt);
	if((retcode!=SQL_SUCCESS)&&(retcode!=SQL_SUCCESS_WITH_INFO))
	{
		AfxMessageBox("���������ʧ�ܣ�");
		return FALSE;
	}
	retcode=SQLExecDirect(m_hstmt,(SQLTCHAR*)szSQL,SQL_NTS);
	if((retcode!=SQL_SUCCESS)&&(retcode!=SQL_SUCCESS_WITH_INFO))
	{
		AfxMessageBox("ִ��SQL���ʧ�ܣ�");
		return FALSE;
	}
	return TRUE;	
}