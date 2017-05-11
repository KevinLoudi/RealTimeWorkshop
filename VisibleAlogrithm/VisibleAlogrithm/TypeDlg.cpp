// TypeDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "VisibleAlogrithm.h"
#include "TypeDlg.h"


// CTypeDlg 对话框

IMPLEMENT_DYNAMIC(CTypeDlg, CDialog)

CTypeDlg::CTypeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTypeDlg::IDD, pParent)
	, m_count(0)
	, m_num(0)
	, m_note(_T(""))
{

}

CTypeDlg::~CTypeDlg()
{
}

void CTypeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SHOW, m_show);
	DDX_Control(pDX, IDC_INPUT, m_input);
	DDX_Text(pDX, IDC_NUM, m_num);
	DDX_Text(pDX, IDC_WORD, m_note);
	DDX_Control(pDX, IDC_NUM, m_Spinnum);
}


BEGIN_MESSAGE_MAP(CTypeDlg, CDialog)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_UPDATE, &CTypeDlg::OnBnClickedUpdate)
	ON_EN_CHANGE(IDC_INPUT, &CTypeDlg::OnEnChangeInput)
	ON_BN_CLICKED(IDOK, &CTypeDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_UPDATE2, &CTypeDlg::OnBnClickedUpdate2)
END_MESSAGE_MAP()

class _declspec(dllimport) Student
{
public:
	Student(void);
	~Student(void);
	bool SetAge(int iAge);
private:
	int m_age;
};

// CTypeDlg 消息处理程序

int CTypeDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	Student stu;
	if (! stu.SetAge(10))
	{
		AfxMessageBox("Fail to set student age!!");
		return 0;
	}

	return 0;
}

void CTypeDlg::OnBnClickedUpdate()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strWord[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
	
	UpdateData(TRUE);
	if (m_num<0|m_num>9)
	{
		AfxMessageBox("Illegal input");
		return;
	}

	m_note=strWord[m_num];
	UpdateData(FALSE);
}

void CTypeDlg::OnEnChangeInput()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	CString strShow;
	m_show.GetWindowText(strShow);
	CString strInput;
	m_input.GetWindowText(strInput);

	strInput.MakeUpper();

	//check if input result is right 
	if (strInput==strShow)
	{
		m_count++;
	}

	//reset
	m_input.SetSel(0,-1);
	char ch='A'+rand()%26;
	strShow=ch;
	m_show.SetWindowText(strShow);
	return;
}

void CTypeDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strMess;
	strMess.Format("You have input %d characters",m_count);
	AfxMessageBox(strMess);

	OnOK();
}


BOOL CTypeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_show.SetReadOnly();
	char ch='A'+rand()%26;
	CString str(ch);
	m_show.SetWindowText(str);


	return TRUE;
}

void CTypeDlg::OnBnClickedUpdate2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strWord[]={"zero","one","two","three","four","five","six","seven","eight","nine"};

	UpdateData(TRUE);
	int len=sizeof(strWord)/sizeof(strWord[0])-1;
	int ix=len;
	for (; ix>=0; --ix)
	{
		//find the matched character
		if (strWord[ix]==m_note)
		{
			break;
		}
	}

	if (ix==-1)
	{
		AfxMessageBox("Not found, illegal input!");
		return;
	}

	m_num=ix;
	UpdateData(FALSE);
}
