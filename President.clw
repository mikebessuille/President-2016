; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=NewMapDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "President.h"
LastPage=0

ClassCount=7
Class1=CPresidentApp
Class2=CPresDoc
Class3=CPresView
Class4=CMainFrame

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDD_NEWMAP
Class5=CAboutDlg
Class6=CSplashWnd
Class7=NewMapDlg
Resource3=IDR_MAINFRAME

[CLS:CPresidentApp]
Type=0
HeaderFile=President.h
ImplementationFile=President.cpp
Filter=N

[CLS:CPresDoc]
Type=0
HeaderFile=doc.h
ImplementationFile=doc.cpp
Filter=N
LastObject=CPresDoc
BaseClass=CDocument
VirtualFilter=DC

[CLS:CPresView]
Type=0
HeaderFile=view.h
ImplementationFile=view.cpp
Filter=C
BaseClass=CScrollView
VirtualFilter=VWC
LastObject=CPresView

[CLS:CMainFrame]
Type=0
HeaderFile=mainfrm.h
ImplementationFile=mainfrm.cpp
Filter=T



[CLS:CAboutDlg]
Type=0
HeaderFile=President.cpp
ImplementationFile=President.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY
Command10=ID_EDIT_PASTE
Command11=ID_VIEW_TOOLBAR
Command12=ID_VIEW_STATUS_BAR
Command13=ID_APP_ABOUT
CommandCount=13

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[TB:IDR_MAINFRAME]
Type=1
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[CLS:CSplashWnd]
Type=0
HeaderFile=Splash.h
ImplementationFile=Splash.cpp
BaseClass=CWnd

[DLG:IDD_NEWMAP]
Type=1
Class=NewMapDlg
ControlCount=9
Control1=IDC_WIDTH,edit,1350770816
Control2=IDC_SPINW,msctls_updown32,1342177330
Control3=IDC_HEIGHT,edit,1350770816
Control4=IDC_SPINH,msctls_updown32,1342177330
Control5=IDOK,button,1342242817
Control6=IDCANCEL,button,1342242816
Control7=IDC_STATIC,button,1342177287
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352

[CLS:NewMapDlg]
Type=0
HeaderFile=newmapdg.h
ImplementationFile=newmapdg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_HEIGHT
VirtualFilter=dWC

