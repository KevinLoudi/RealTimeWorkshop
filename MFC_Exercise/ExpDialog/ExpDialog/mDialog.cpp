// mDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ExpDialog.h"
#include "mDialog.h"


// CmDialog �Ի���

IMPLEMENT_DYNAMIC(CmDialog, CDialog)

CmDialog::CmDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CmDialog::IDD, pParent)
{

}

CmDialog::~CmDialog()
{
}

void CmDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


void CmDialog::OnOK()
{
	MessageBox("Push OK button!!!");
	CDialog::OnOK();
}

BEGIN_MESSAGE_MAP(CmDialog, CDialog)
END_MESSAGE_MAP()


// CmDialog ��Ϣ�������
