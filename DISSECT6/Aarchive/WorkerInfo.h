// WorkerInfo.h: interface for the CWorkerInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WORKERINFO_H__CA44E279_8036_409C_9484_C9F7F65A628D__INCLUDED_)
#define AFX_WORKERINFO_H__CA44E279_8036_409C_9484_C9F7F65A628D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "StdAfx.h"

class CWorkerInfo : public CObject  
{
public:
	CWorkerInfo();
	virtual ~CWorkerInfo();
	void SaveInfo(CString ,CString , UINT ,CString,CString);
	void ReadInfo(CString& ,CString& , UINT& ,CString&,CString&);

	virtual void Serialize(CArchive &ar);
	DECLARE_SERIAL(CWorkerInfo)

public:
	CString	m_strName;
	CString	m_strJnum;
	UINT	m_uintPay;
	CString	m_strPos;
	CString	m_strRemark;

};

#endif // !defined(AFX_WORKERINFO_H__CA44E279_8036_409C_9484_C9F7F65A628D__INCLUDED_)
