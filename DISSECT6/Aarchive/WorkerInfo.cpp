// WorkerInfo.cpp: implementation of the CWorkerInfo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Aarchive.h"
#include "WorkerInfo.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWorkerInfo::CWorkerInfo()
{

}

CWorkerInfo::~CWorkerInfo()
{

}

void CWorkerInfo::SaveInfo(CString name,CString jnum, UINT pay,CString pos,
						   CString remark)
{
	m_strName=name; m_strJnum=jnum;
	m_uintPay=pay; m_strPos=pos;
	m_strRemark=remark;
	
}

void CWorkerInfo::ReadInfo(CString& name,CString& jnum, UINT& pay,CString& pos,
						   CString& remark)
{
	name=m_strName; jnum=m_strJnum;
	pay=m_uintPay; pos=m_strPos;
	remark=m_strRemark;
}

void CWorkerInfo::Serialize(CArchive &ar)
{
	CObject::Serialize(ar);

	if (ar.IsStoring())
	{
		ar<<m_strName<<m_strJnum<<m_strPos<<m_uintPay<<m_strRemark;
	} 
	else
	{
		ar>>m_strName>>m_strJnum>>m_strPos>>m_uintPay>>m_strRemark;
	}
	
}
