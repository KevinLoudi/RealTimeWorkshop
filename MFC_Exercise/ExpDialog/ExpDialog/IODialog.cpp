// IODialog.cpp : 实现文件
//

#include "stdafx.h"
#include "ExpDialog.h"
#include "IODialog.h"


// CIODialog 对话框

IMPLEMENT_DYNAMIC(CIODialog, CDialog)

CIODialog::CIODialog(CWnd* pParent /*=NULL*/)
	: CDialog(CIODialog::IDD, pParent)
{

}

CIODialog::~CIODialog()
{
}

void CIODialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CIODialog, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_IN, &CIODialog::OnBnClickedButtonIn)
	ON_BN_CLICKED(IDC_BUTTON_OUT, &CIODialog::OnBnClickedButtonOut)
END_MESSAGE_MAP()


// CIODialog 消息处理程序

void CIODialog::OnBnClickedButtonIn()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
}

void CIODialog::OnBnClickedButtonOut()
{
	// TODO: 在此添加控件通知处理程序代码
	m_Edit_out=m_Edit_in;
	UpdateData(FALSE);
}
