#include <afxwin.h>

//define application freamwork
class CmApp: public CWinApp
{
public:
	BOOL InitInstance();
};

//define doc class
class CmDoc: public CDocument
{
private:
	int Array[3];
protected:
	CmDoc();
	//DECLARE_DYNCREATE(CmDoc)
public:
	void SetMember(UINT ix, int m);
	const int GetMember(UINT ix); 
public:
	//virtual BOOL OnNewDocument();
	//virtual void Serialize(CArchive& ar);
	virtual ~CmDoc();
	//DECLARE_MESSAGE_MAP()
};

CmDoc::CmDoc()
{
	for (int ix=0; ix<3; ++ix)
	{
		Array[ix]=0;
	}
}

void CmDoc::SetMember(UINT ix, int m)
{
	ASSERT(ix<3);
	Array[ix]=m;
}

const int CmDoc::GetMember(UINT ix)
{
	return Array[ix];
}

CmDoc::~CmDoc()
{

}

CmApp theApp;

BOOL CmApp::InitInstance()
{
	CFrameWnd *pMainWnd=new CFrameWnd;
	pMainWnd->Create(NULL,"Basic MFC Application");
	pMainWnd->ShowWindow(m_nCmdShow);
	pMainWnd->UpdateData();
	m_pMainWnd=pMainWnd;
	return TRUE;
}

