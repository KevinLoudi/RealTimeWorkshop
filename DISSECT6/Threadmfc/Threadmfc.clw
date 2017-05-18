; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CThreadmfcDlg
LastTemplate=CWinThread
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Threadmfc.h"

ClassCount=5
Class1=CThreadmfcApp
Class2=CThreadmfcDlg
Class3=CAboutDlg

ResourceCount=6
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_THREADMFC_DIALOG
Resource4=IDD_ABOUTBOX (English (U.S.))
Resource5=IDD_THREADMFC_DIALOG (English (U.S.))
Class5=CNewThread
Class4=CNewDlg
Resource6=IDD_DIALOG1

[CLS:CThreadmfcApp]
Type=0
HeaderFile=Threadmfc.h
ImplementationFile=Threadmfc.cpp
Filter=N

[CLS:CThreadmfcDlg]
Type=0
HeaderFile=ThreadmfcDlg.h
ImplementationFile=ThreadmfcDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CThreadmfcDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=ThreadmfcDlg.h
ImplementationFile=ThreadmfcDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg


[DLG:IDD_THREADMFC_DIALOG]
Type=1
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Class=CThreadmfcDlg

[DLG:IDD_THREADMFC_DIALOG (English (U.S.))]
Type=1
Class=CThreadmfcDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_BUTTON_SHOW,button,1342242816

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DIALOG1]
Type=1
Class=CNewDlg
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[CLS:CNewDlg]
Type=0
HeaderFile=NewDlg.h
ImplementationFile=NewDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CNewDlg

[CLS:CNewThread]
Type=0
HeaderFile=NewThread.h
ImplementationFile=NewThread.cpp
BaseClass=CWinThread
Filter=N

