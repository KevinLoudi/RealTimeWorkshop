class CMyWinApp : public CWinApp
{
public:
	BOOL InitInstance();
};

class CMyFreamWnd: public CFrameWnd
{
public:
	CMyFreamWnd();
	afx_msg void OnPaint();
	afx_msg void OnAbout();

private:
	DECLARE_MESSAGE_MAP()
	static VOID CALLBACK LineDDACallback(int ,int, LPARAM);
};