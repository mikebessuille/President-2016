# Microsoft Developer Studio Generated NMAKE File, Format Version 4.10
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=President - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to President - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "President - Win32 Release" && "$(CFG)" !=\
 "President - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "President.mak" CFG="President - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "President - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "President - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
# PROP Target_Last_Scanned "President - Win32 Debug"
CPP=cl.exe
RSC=rc.exe
MTL=mktyplib.exe

!IF  "$(CFG)" == "President - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
OUTDIR=.\Release
INTDIR=.\Release

ALL : "$(OUTDIR)\President.exe"

CLEAN : 
	-@erase "$(INTDIR)\coords.obj"
	-@erase "$(INTDIR)\doc.obj"
	-@erase "$(INTDIR)\mainfrm.obj"
	-@erase "$(INTDIR)\map.obj"
	-@erase "$(INTDIR)\newmapdg.obj"
	-@erase "$(INTDIR)\President.obj"
	-@erase "$(INTDIR)\President.pch"
	-@erase "$(INTDIR)\President.res"
	-@erase "$(INTDIR)\Splash.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\view.obj"
	-@erase "$(OUTDIR)\President.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/President.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/"\
 /c 
CPP_OBJS=.\Release/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/President.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/President.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/President.pdb" /machine:I386 /out:"$(OUTDIR)/President.exe" 
LINK32_OBJS= \
	"$(INTDIR)\coords.obj" \
	"$(INTDIR)\doc.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\map.obj" \
	"$(INTDIR)\newmapdg.obj" \
	"$(INTDIR)\President.obj" \
	"$(INTDIR)\President.res" \
	"$(INTDIR)\Splash.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\view.obj"

"$(OUTDIR)\President.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "President - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
OUTDIR=.\Debug
INTDIR=.\Debug

ALL : "$(OUTDIR)\President.exe"

CLEAN : 
	-@erase "$(INTDIR)\coords.obj"
	-@erase "$(INTDIR)\doc.obj"
	-@erase "$(INTDIR)\mainfrm.obj"
	-@erase "$(INTDIR)\map.obj"
	-@erase "$(INTDIR)\newmapdg.obj"
	-@erase "$(INTDIR)\President.obj"
	-@erase "$(INTDIR)\President.pch"
	-@erase "$(INTDIR)\President.res"
	-@erase "$(INTDIR)\Splash.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(INTDIR)\view.obj"
	-@erase "$(OUTDIR)\President.exe"
	-@erase "$(OUTDIR)\President.ilk"
	-@erase "$(OUTDIR)\President.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/President.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/President.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/President.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)/President.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)/President.exe" 
LINK32_OBJS= \
	"$(INTDIR)\coords.obj" \
	"$(INTDIR)\doc.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\map.obj" \
	"$(INTDIR)\newmapdg.obj" \
	"$(INTDIR)\President.obj" \
	"$(INTDIR)\President.res" \
	"$(INTDIR)\Splash.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\view.obj"

"$(OUTDIR)\President.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Target

# Name "President - Win32 Release"
# Name "President - Win32 Debug"

!IF  "$(CFG)" == "President - Win32 Release"

!ELSEIF  "$(CFG)" == "President - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\ReadMe.txt

!IF  "$(CFG)" == "President - Win32 Release"

!ELSEIF  "$(CFG)" == "President - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\President.cpp
DEP_CPP_PRESI=\
	"..\..\include\const.h"\
	"..\..\include\macro.h"\
	"..\..\include\proto.h"\
	".\doc.h"\
	".\mainfrm.h"\
	".\map.h"\
	".\President.h"\
	".\Splash.h"\
	".\StdAfx.h"\
	".\view.h"\
	{$(INCLUDE)}"\Mike.h"\
	

"$(INTDIR)\President.obj" : $(SOURCE) $(DEP_CPP_PRESI) "$(INTDIR)"\
 "$(INTDIR)\President.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "President - Win32 Release"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/President.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/"\
 /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\President.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "President - Win32 Debug"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/President.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\President.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\mainfrm.cpp
DEP_CPP_MAINF=\
	"..\..\include\const.h"\
	"..\..\include\macro.h"\
	"..\..\include\proto.h"\
	".\mainfrm.h"\
	".\President.h"\
	".\Splash.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"\Mike.h"\
	

"$(INTDIR)\mainfrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\President.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\doc.cpp
DEP_CPP_DOC_C=\
	"..\..\include\const.h"\
	"..\..\include\macro.h"\
	"..\..\include\proto.h"\
	".\doc.h"\
	".\map.h"\
	".\newmapdg.h"\
	".\President.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"\Mike.h"\
	

"$(INTDIR)\doc.obj" : $(SOURCE) $(DEP_CPP_DOC_C) "$(INTDIR)"\
 "$(INTDIR)\President.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\view.cpp
DEP_CPP_VIEW_=\
	"..\..\include\const.h"\
	"..\..\include\macro.h"\
	"..\..\include\proto.h"\
	".\doc.h"\
	".\ids.h"\
	".\map.h"\
	".\President.h"\
	".\StdAfx.h"\
	".\view.h"\
	{$(INCLUDE)}"\Mike.h"\
	

"$(INTDIR)\view.obj" : $(SOURCE) $(DEP_CPP_VIEW_) "$(INTDIR)"\
 "$(INTDIR)\President.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\President.rc
DEP_RSC_PRESID=\
	".\res\backgrou.bmp"\
	".\res\bitmap1.bmp"\
	".\res\doc.ico"\
	".\res\President.ico"\
	".\res\President.rc2"\
	".\res\stickman.bmp"\
	".\res\Toolbar.bmp"\
	".\Splsh16.bmp"\
	

"$(INTDIR)\President.res" : $(SOURCE) $(DEP_RSC_PRESID) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\map.cpp
DEP_CPP_MAP_C=\
	"..\..\include\const.h"\
	"..\..\include\macro.h"\
	"..\..\include\proto.h"\
	".\doc.h"\
	".\ids.h"\
	".\map.h"\
	".\President.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"\Mike.h"\
	

"$(INTDIR)\map.obj" : $(SOURCE) $(DEP_CPP_MAP_C) "$(INTDIR)"\
 "$(INTDIR)\President.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Splash.cpp
DEP_CPP_SPLAS=\
	".\Splash.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Splash.obj" : $(SOURCE) $(DEP_CPP_SPLAS) "$(INTDIR)"\
 "$(INTDIR)\President.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\coords.cpp
DEP_CPP_COORD=\
	"..\..\include\const.h"\
	"..\..\include\macro.h"\
	"..\..\include\proto.h"\
	".\map.h"\
	".\President.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"\Mike.h"\
	

"$(INTDIR)\coords.obj" : $(SOURCE) $(DEP_CPP_COORD) "$(INTDIR)"\
 "$(INTDIR)\President.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\newmapdg.cpp
DEP_CPP_NEWMA=\
	"..\..\include\const.h"\
	"..\..\include\macro.h"\
	"..\..\include\proto.h"\
	".\newmapdg.h"\
	".\President.h"\
	".\StdAfx.h"\
	{$(INCLUDE)}"\Mike.h"\
	

"$(INTDIR)\newmapdg.obj" : $(SOURCE) $(DEP_CPP_NEWMA) "$(INTDIR)"\
 "$(INTDIR)\President.pch"


# End Source File
# End Target
# End Project
################################################################################
################################################################################
# Section President : {85C9E590-274D-11CF-AB99-00C0F00683EB}
# 	0:8:Splash.h:D:\Dev\Project\pres\Splash.h
# 	0:10:Splash.cpp:D:\Dev\Project\pres\Splash.cpp
# 	1:10:IDB_SPLASH:105
# 	2:10:ResHdrName:resource.h
# 	2:11:ProjHdrName:stdafx.h
# 	2:10:WrapperDef:_SPLASH_SCRN_
# 	2:12:SplClassName:CSplashWnd
# 	2:21:SplashScreenInsertKey:4.0
# 	2:10:HeaderName:Splash.h
# 	2:10:ImplemName:Splash.cpp
# 	2:7:BmpID16:IDB_SPLASH
# End Section
################################################################################
################################################################################
# Section President : {85C9E593-274D-11CF-AB99-00C0F00683EB}
# 	1:17:CG_IDS_DISK_SPACE:103
# 	1:19:CG_IDS_PHYSICAL_MEM:102
# 	1:25:CG_IDS_DISK_SPACE_UNAVAIL:104
# 	2:10:SysInfoKey:1234
# End Section
################################################################################
