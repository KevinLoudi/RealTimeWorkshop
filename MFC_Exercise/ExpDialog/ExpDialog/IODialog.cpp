// IODialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ExpDialog.h"
#include "IODialog.h"


// CIODialog �Ի���

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


// CIODialog ��Ϣ�������

void CIODialog::OnBnClickedButtonIn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
}

void CIODialog::OnBnClickedButtonOut()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_Edit_out=m_Edit_in;
	UpdateData(FALSE);
}
