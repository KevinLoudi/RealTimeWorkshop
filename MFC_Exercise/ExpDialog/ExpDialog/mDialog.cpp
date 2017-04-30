// mDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "ExpDialog.h"
#include "mDialog.h"


// CmDialog 对话框

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


// CmDialog 消息处理程序
