; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CThreadProgressDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ThreadProgress.h"

ClassCount=3
Class1=CThreadProgressApp
Class2=CThreadProgressDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_THREADPROGRESS_DIALOG
Resource4=IDD_ABOUTBOX (English (U.S.))
Resource5=IDD_THREADPROGRESS_DIALOG (English (U.S.))

[CLS:CThreadProgressApp]
Type=0
HeaderFile=ThreadProgress.h
ImplementationFile=ThreadProgress.cpp
Filter=N

[CLS:CThreadProgressDlg]
Type=0
HeaderFile=ThreadProgressDlg.h
ImplementationFile=ThreadProgressDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_PROGRESS1

[CLS:CAboutDlg]
Type=0
HeaderFile=ThreadProgressDlg.h
ImplementationFile=ThreadProgressDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg


[DLG:IDD_THREADPROGRESS_DIALOG]
Type=1
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Class=CThreadProgressDlg

[DLG:IDD_THREADPROGRESS_DIALOG (English (U.S.))]
Type=1
Class=CThreadProgressDlg
ControlCount=11
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_BUTTON_START,button,1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_PROGRESS1,msctls_progress32,1350565888
Control9=IDC_PROGRESS2,msctls_progress32,1350565888
Control10=IDC_PROGRESS3,msctls_progress32,1350565888
Control11=IDC_PROGRESS4,msctls_progress32,1350565888

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=?
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

