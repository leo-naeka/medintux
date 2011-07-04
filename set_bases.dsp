# Microsoft Developer Studio Project File - Name="" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86)  Application" 0x0101

CFG= - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f ".mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f ".mak" CFG=" - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE " - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE " - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == " - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "obj"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "obj"
# PROP Target_Dir ""
# ADD CPP -MD /W3 /I "$(QTDIR)\include" /I "ui" /I "." /I "." /I "moc" /I "C:\Qt3\3.3.4\mkspecs\win32-msvc" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D UNICODE /D QT_DLL /D QT_THREAD_SUPPORT /D "QT_NO_DEBUG" /FD /c -nologo -Zm200 -GX -O1 
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BSC32 /nologo
LINK32=link.exe
# ADD LINK32  "qt-mt334.lib"  "qtmain.lib"  "kernel32.lib"  "user32.lib"  "gdi32.lib"  "comdlg32.lib"  "advapi32.lib"  "shell32.lib"  "ole32.lib"  "oleaut32.lib"  "uuid.lib"  "imm32.lib"  "winmm.lib"  "wsock32.lib"  "winspool.lib"  "kernel32.lib"  "user32.lib"  "gdi32.lib"  "comdlg32.lib"  "advapi32.lib"  "shell32.lib"  "ole32.lib"  "oleaut32.lib"  "uuid.lib"  "imm32.lib"  "winmm.lib"  "wsock32.lib"  "winspool.lib"  "opengl32.lib"  "glu32.lib"  "delayimp.lib"   /NOLOGO /SUBSYSTEM:windows /LIBPATH:"$(QTDIR)\lib" delayimp.lib /DELAYLOAD:comdlg32.dll /DELAYLOAD:oleaut32.dll /DELAYLOAD:winmm.dll /DELAYLOAD:wsock32.dll /DELAYLOAD:winspool.dll  /out:"../bin/set_bases.exe


!ELSEIF  "$(CFG)" == " - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD CPP -MDd /W3 /GZ /ZI /Od /I "$(QTDIR)\include" /I "ui" /I "." /I "." /I "moc" /I "C:\Qt3\3.3.4\mkspecs\win32-msvc" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D UNICODE /D QT_DLL /D QT_THREAD_SUPPORT /FD /c -nologo -Zm200 -GX -Zi  
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BSC32 /nologo
LINK32=link.exe
# ADD LINK32  "qt-mt334.lib"  "qtmain.lib"  "kernel32.lib"  "user32.lib"  "gdi32.lib"  "comdlg32.lib"  "advapi32.lib"  "shell32.lib"  "ole32.lib"  "oleaut32.lib"  "uuid.lib"  "imm32.lib"  "winmm.lib"  "wsock32.lib"  "winspool.lib"  "kernel32.lib"  "user32.lib"  "gdi32.lib"  "comdlg32.lib"  "advapi32.lib"  "shell32.lib"  "ole32.lib"  "oleaut32.lib"  "uuid.lib"  "imm32.lib"  "winmm.lib"  "wsock32.lib"  "winspool.lib"  "opengl32.lib"  "glu32.lib"  "delayimp.lib"   /NOLOGO /SUBSYSTEM:windows /LIBPATH:"$(QTDIR)\lib" /pdbtype:sept /DEBUG  /out:"../bin/set_bases.exe


!ENDIF 

# Begin Target

# Name " - Win32 Release"
# Name " - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=main.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\C_Zlib\C_Zlib.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\C_Zlib\adler32.c
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\C_Zlib\compress.c
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\C_Zlib\crc32.c
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\C_Zlib\deflate.c
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\C_Zlib\gzio.c
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\C_Zlib\infback.c
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\C_Zlib\inffast.c
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\C_Zlib\inflate.c
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\C_Zlib\inftrees.c
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\C_Zlib\trees.c
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\C_Zlib\uncompr.c
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\C_Zlib\zutil.c
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CGestIni.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CMedicaBase.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CHtmlTools.cpp
# End Source File
# Begin Source File

SOURCE=..\..\drtux\src\CMoteur_Base.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CPrtQListBoxItem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CPrtQListViewItem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\ThemePopup.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\Theme.cpp
# End Source File
# Begin Source File

SOURCE=CSetupBase.cpp
# End Source File
# Begin Source File

SOURCE=CApp.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CW_EditText.cpp
# End Source File
# Begin Source File

SOURCE=CUpdateThread.cpp
# End Source File
# Begin Source File

SOURCE=CIndexMakeThread.cpp
# End Source File
# Begin Source File

SOURCE=C_DlgMainDialog.cpp
# End Source File

# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\..\MedinTuxTools\C_Zlib\C_Zlib.h

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\C_Zlib\deflate.h

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\C_Zlib\inftrees.h

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\C_Zlib\zconf.h

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\C_Zlib\zconf.in.h

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\C_Zlib\zlib.h

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\C_Zlib\zutil.h

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CGestIni.h

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CMedicaBase.h

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CHtmlTools.h

# End Source File
# Begin Source File

SOURCE=..\..\drtux\src\CMoteur_Base.h

USERDEP_=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing ..\..\drtux\src\CMoteur_Base.h...
InputPath=.\..\..\drtux\src\CMoteur_Base.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\drtux\src\CMoteur_Base.h -o moc\moc_CMoteur_Base.cpp \

"moc\moc_CMoteur_Base.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing ..\..\drtux\src\CMoteur_Base.h...
InputPath=.\..\..\drtux\src\CMoteur_Base.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\drtux\src\CMoteur_Base.h -o moc\moc_CMoteur_Base.cpp \

"moc\moc_CMoteur_Base.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CPrtQListBoxItem.h

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\ThemePopup.h

USERDEP_=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing ..\..\MedinTuxTools\ThemePopup.h...
InputPath=.\..\..\MedinTuxTools\ThemePopup.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\MedinTuxTools\ThemePopup.h -o moc\moc_ThemePopup.cpp \

"moc\moc_ThemePopup.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing ..\..\MedinTuxTools\ThemePopup.h...
InputPath=.\..\..\MedinTuxTools\ThemePopup.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\MedinTuxTools\ThemePopup.h -o moc\moc_ThemePopup.cpp \

"moc\moc_ThemePopup.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\Theme.h

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CPrtQListViewItem.h

USERDEP_=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing ..\..\MedinTuxTools\CPrtQListViewItem.h...
InputPath=.\..\..\MedinTuxTools\CPrtQListViewItem.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\MedinTuxTools\CPrtQListViewItem.h -o moc\moc_CPrtQListViewItem.cpp \

"moc\moc_CPrtQListViewItem.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing ..\..\MedinTuxTools\CPrtQListViewItem.h...
InputPath=.\..\..\MedinTuxTools\CPrtQListViewItem.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\MedinTuxTools\CPrtQListViewItem.h -o moc\moc_CPrtQListViewItem.cpp \

"moc\moc_CPrtQListViewItem.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=CSetupBase.h

# End Source File
# Begin Source File

SOURCE=CApp.h

USERDEP_CApp=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing CApp.h...
InputPath=.\CApp.h


BuildCmds= \
	$(QTDIR)\bin\moc CApp.h -o moc\moc_CApp.cpp \

"moc\moc_CApp.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing CApp.h...
InputPath=.\CApp.h


BuildCmds= \
	$(QTDIR)\bin\moc CApp.h -o moc\moc_CApp.cpp \

"moc\moc_CApp.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CW_EditText.h

USERDEP_=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing ..\..\MedinTuxTools\CW_EditText.h...
InputPath=.\..\..\MedinTuxTools\CW_EditText.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\MedinTuxTools\CW_EditText.h -o moc\moc_CW_EditText.cpp \

"moc\moc_CW_EditText.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing ..\..\MedinTuxTools\CW_EditText.h...
InputPath=.\..\..\MedinTuxTools\CW_EditText.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\MedinTuxTools\CW_EditText.h -o moc\moc_CW_EditText.cpp \

"moc\moc_CW_EditText.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=CUpdateThread.h

# End Source File
# Begin Source File

SOURCE=CIndexMakeThread.h

# End Source File
# Begin Source File

SOURCE=C_DlgMainDialog.h

USERDEP_C_DlgMainDialog=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing C_DlgMainDialog.h...
InputPath=.\C_DlgMainDialog.h


BuildCmds= \
	$(QTDIR)\bin\moc C_DlgMainDialog.h -o moc\moc_C_DlgMainDialog.cpp \

"moc\moc_C_DlgMainDialog.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing C_DlgMainDialog.h...
InputPath=.\C_DlgMainDialog.h


BuildCmds= \
	$(QTDIR)\bin\moc C_DlgMainDialog.h -o moc\moc_C_DlgMainDialog.cpp \

"moc\moc_C_DlgMainDialog.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File

# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group

# Begin Group "Forms"
# Prop Default_Filter "ui"
# Begin Source File

SOURCE=Dlg_MainDialog.ui
USERDEP_Dlg_MainDialog.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing Dlg_MainDialog.ui...
InputPath=.\Dlg_MainDialog.ui

BuildCmds= \
	$(QTDIR)\bin\uic Dlg_MainDialog.ui -o ui\Dlg_MainDialog.h \
	$(QTDIR)\bin\uic Dlg_MainDialog.ui -i Dlg_MainDialog.h -o ui\Dlg_MainDialog.cpp \
	$(QTDIR)\bin\moc  ui\Dlg_MainDialog.h -o moc\moc_Dlg_MainDialog.cpp \

"ui\Dlg_MainDialog.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\Dlg_MainDialog.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_Dlg_MainDialog.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing Dlg_MainDialog.ui...
InputPath=.\Dlg_MainDialog.ui

BuildCmds= \
	$(QTDIR)\bin\uic Dlg_MainDialog.ui -o ui\Dlg_MainDialog.h \
	$(QTDIR)\bin\uic Dlg_MainDialog.ui -i Dlg_MainDialog.h -o ui\Dlg_MainDialog.cpp \
	$(QTDIR)\bin\moc  ui\Dlg_MainDialog.h -o moc\moc_Dlg_MainDialog.cpp \

"ui\Dlg_MainDialog.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\Dlg_MainDialog.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_Dlg_MainDialog.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File

# End Group

# Begin Group "Translations"
# Prop Default_Filter "ts"
# Begin Source File

SOURCE=set_bases_fr.ts

# End Source File

# End Group





# Begin Group "Generated"
# Begin Source File

SOURCE=moc\moc_CMoteur_Base.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_ThemePopup.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CPrtQListViewItem.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CApp.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CW_EditText.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_C_DlgMainDialog.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_Dlg_MainDialog.cpp
# End Source File

# Begin Source File

SOURCE=ui\Dlg_MainDialog.cpp
# End Source File

# Begin Source File

SOURCE=ui\Dlg_MainDialog.h
# End Source File




# Prop Default_Filter "moc"
# End Group
# End Target
# End Project

