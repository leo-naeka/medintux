# Microsoft Developer Studio Project File - Name=" - Win32 Release" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG= - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "qmedicabase.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "qmedicabase.mak" CFG=" - Win32 Release"
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
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD CPP /nologo /MD /W3 /GX /O1 /I "..\..\Commercial" /I "$(QTDIR)\include" /I "..\..\MedinTuxTools" /I "../../MedinTuxTools" /I "..\..\MedinTuxTools\medicabase" /I "../../MedinTuxTools/medicabase" /I "." /I "moc" /I "C:\Qt\3.3.4\mkspecs\win32-msvc" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "UNICODE" /D "SIMPLE_VERSION" /D "COMMERCIAL_VERSION" /D "QT_DLL" /D "QT_THREAD_SUPPORT" /D "QT_NO_DEBUG" /FD -Zm200 /c
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x40c
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /machine:IX86
# ADD LINK32 "qt-mt334.lib" "qtmain.lib" "kernel32.lib" "user32.lib" "gdi32.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "imm32.lib" "winmm.lib" "wsock32.lib" "winspool.lib" "kernel32.lib" "user32.lib" "gdi32.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "imm32.lib" "winmm.lib" "wsock32.lib" "winspool.lib" "opengl32.lib" "glu32.lib" "delayimp.lib" delayimp.lib /nologo /subsystem:windows /machine:IX86 /out:"../bin/qmedicabase.exe" /libpath:"$(QTDIR)\lib" /DELAYLOAD:comdlg32.dll /DELAYLOAD:oleaut32.dll /DELAYLOAD:winmm.dll /DELAYLOAD:wsock32.dll /DELAYLOAD:winspool.dll

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "obj"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "obj"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD CPP /nologo /MDd /W3 /GX /Zi /Od /I "..\..\Commercial" /I "$(QTDIR)\include" /I "..\..\MedinTuxTools" /I "../../MedinTuxTools" /I "..\..\MedinTuxTools\medicabase" /I "../../MedinTuxTools/medicabase" /I "." /I "moc" /I "C:\Qt\3.3.4\mkspecs\win32-msvc" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "UNICODE" /D "SIMPLE_VERSION" /D "COMMERCIAL_VERSION" /D "QT_DLL" /D "QT_THREAD_SUPPORT" /FD /GZ -Zm200 /c
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x40c
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /machine:IX86
# ADD LINK32 "qt-mt334.lib" "qtmain.lib" "kernel32.lib" "user32.lib" "gdi32.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "imm32.lib" "winmm.lib" "wsock32.lib" "winspool.lib" "kernel32.lib" "user32.lib" "gdi32.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "imm32.lib" "winmm.lib" "wsock32.lib" "winspool.lib" "opengl32.lib" "glu32.lib" "delayimp.lib" /nologo /subsystem:windows /debug /machine:IX86 /out:"../bin/qmedicabase.exe" /pdbtype:sept /libpath:"$(QTDIR)\lib"

!ENDIF 

# Begin Target

# Name " - Win32 Release"
# Name " - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\..\Commercial\C_Cps.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Commercial\C_MUI_App.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Commercial\C_Vitale.cpp
# End Source File
# Begin Source File

SOURCE=CApp.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\cdlg_passwordget.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CGenTools.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CGestIni.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CHtmlTools.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CMaskedLineEdit.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CMedicaBase.cpp
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

SOURCE=..\..\Commercial\CSesam_API_InfoGroupe.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\medicabase\Dlg_AdvancedTerrain.ui.h
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\medicabase\Dlg_HtmlView.ui.h
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\medicabase\Dlg_MedicaAdjustPoso.ui.h
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\medicabase\Dlg_MedicaTux.ui.h
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\medicabase\Dlg_PosoManager.ui.h
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\DlgGetString.ui.h
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\DlgMyMessageBox.ui.h
# End Source File
# Begin Source File

SOURCE=main.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Commercial\qtsingleapplication.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Commercial\qtsingleapplication_win.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\Theme.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\ThemePopup.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\..\Commercial\C_Cps.h
# End Source File
# Begin Source File

SOURCE=..\..\Commercial\C_MUI_App.h

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__C_MUI=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing ..\..\Commercial\C_MUI_App.h...
InputPath=..\..\Commercial\C_MUI_App.h

"moc\moc_C_MUI_App.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc ..\..\Commercial\C_MUI_App.h -o moc\moc_C_MUI_App.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__C_MUI=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing ..\..\Commercial\C_MUI_App.h...
InputPath=..\..\Commercial\C_MUI_App.h

"moc\moc_C_MUI_App.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc ..\..\Commercial\C_MUI_App.h -o moc\moc_C_MUI_App.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\Commercial\C_Vitale.h
# End Source File
# Begin Source File

SOURCE=CApp.h
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\cdlg_passwordget.h

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__CDLG_=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing ..\..\MedinTuxTools\cdlg_passwordget.h...
InputPath=..\..\MedinTuxTools\cdlg_passwordget.h

"moc\moc_cdlg_passwordget.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc ..\..\MedinTuxTools\cdlg_passwordget.h -o moc\moc_cdlg_passwordget.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__CDLG_=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing ..\..\MedinTuxTools\cdlg_passwordget.h...
InputPath=..\..\MedinTuxTools\cdlg_passwordget.h

"moc\moc_cdlg_passwordget.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc ..\..\MedinTuxTools\cdlg_passwordget.h -o moc\moc_cdlg_passwordget.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CGenTools.h
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CGestIni.h
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CHtmlTools.h
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CMaskedLineEdit.h

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__CMASK=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing ..\..\MedinTuxTools\CMaskedLineEdit.h...
InputPath=..\..\MedinTuxTools\CMaskedLineEdit.h

"moc\moc_CMaskedLineEdit.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc ..\..\MedinTuxTools\CMaskedLineEdit.h -o moc\moc_CMaskedLineEdit.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__CMASK=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing ..\..\MedinTuxTools\CMaskedLineEdit.h...
InputPath=..\..\MedinTuxTools\CMaskedLineEdit.h

"moc\moc_CMaskedLineEdit.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc ..\..\MedinTuxTools\CMaskedLineEdit.h -o moc\moc_CMaskedLineEdit.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CMedicaBase.h
# End Source File
# Begin Source File

SOURCE=..\..\drtux\src\CMoteur_Base.h
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CPrtQListBoxItem.h
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CPrtQListViewItem.h
# End Source File
# Begin Source File

SOURCE=..\..\Commercial\CSesam_API_InfoGroupe.h
# End Source File
# Begin Source File

SOURCE=..\..\Commercial\qtsingleapplication.h

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__QTSIN=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing ..\..\Commercial\qtsingleapplication.h...
InputPath=..\..\Commercial\qtsingleapplication.h

"moc\moc_qtsingleapplication.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc ..\..\Commercial\qtsingleapplication.h -o moc\moc_qtsingleapplication.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__QTSIN=""$(QTDIR)\bin\moc.exe""	
# Begin Custom Build - Moc'ing ..\..\Commercial\qtsingleapplication.h...
InputPath=..\..\Commercial\qtsingleapplication.h

"moc\moc_qtsingleapplication.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc ..\..\Commercial\qtsingleapplication.h -o moc\moc_qtsingleapplication.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\Theme.h
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\ThemePopup.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# Begin Group "Forms"

# PROP Default_Filter "ui"
# Begin Source File

SOURCE=..\..\MedinTuxTools\medicabase\Dlg_AdvancedTerrain.ui

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__DLG_A="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing ..\..\MedinTuxTools\medicabase\Dlg_AdvancedTerrain.ui...
InputPath=..\..\MedinTuxTools\medicabase\Dlg_AdvancedTerrain.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\medicabase\Dlg_AdvancedTerrain.ui -o ..\..\MedinTuxTools\medicabase\Dlg_AdvancedTerrain.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\medicabase\Dlg_AdvancedTerrain.ui -i Dlg_AdvancedTerrain.h -o ..\..\MedinTuxTools\medicabase\Dlg_AdvancedTerrain.cpp \
	$(QTDIR)\bin\moc  ..\..\MedinTuxTools\medicabase\Dlg_AdvancedTerrain.h -o moc\moc_Dlg_AdvancedTerrain.cpp \
	

"..\..\MedinTuxTools\medicabase\Dlg_AdvancedTerrain.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"..\..\MedinTuxTools\medicabase\Dlg_AdvancedTerrain.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_Dlg_AdvancedTerrain.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__DLG_A="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing ..\..\MedinTuxTools\medicabase\Dlg_AdvancedTerrain.ui...
InputPath=..\..\MedinTuxTools\medicabase\Dlg_AdvancedTerrain.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\medicabase\Dlg_AdvancedTerrain.ui -o ..\..\MedinTuxTools\medicabase\Dlg_AdvancedTerrain.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\medicabase\Dlg_AdvancedTerrain.ui -i Dlg_AdvancedTerrain.h -o ..\..\MedinTuxTools\medicabase\Dlg_AdvancedTerrain.cpp \
	$(QTDIR)\bin\moc  ..\..\MedinTuxTools\medicabase\Dlg_AdvancedTerrain.h -o moc\moc_Dlg_AdvancedTerrain.cpp \
	

"..\..\MedinTuxTools\medicabase\Dlg_AdvancedTerrain.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"..\..\MedinTuxTools\medicabase\Dlg_AdvancedTerrain.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_Dlg_AdvancedTerrain.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\medicabase\Dlg_HtmlView.ui

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__DLG_H="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing ..\..\MedinTuxTools\medicabase\Dlg_HtmlView.ui...
InputPath=..\..\MedinTuxTools\medicabase\Dlg_HtmlView.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\medicabase\Dlg_HtmlView.ui -o ..\..\MedinTuxTools\medicabase\Dlg_HtmlView.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\medicabase\Dlg_HtmlView.ui -i Dlg_HtmlView.h -o ..\..\MedinTuxTools\medicabase\Dlg_HtmlView.cpp \
	$(QTDIR)\bin\moc  ..\..\MedinTuxTools\medicabase\Dlg_HtmlView.h -o moc\moc_Dlg_HtmlView.cpp \
	

"..\..\MedinTuxTools\medicabase\Dlg_HtmlView.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"..\..\MedinTuxTools\medicabase\Dlg_HtmlView.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_Dlg_HtmlView.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__DLG_H="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing ..\..\MedinTuxTools\medicabase\Dlg_HtmlView.ui...
InputPath=..\..\MedinTuxTools\medicabase\Dlg_HtmlView.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\medicabase\Dlg_HtmlView.ui -o ..\..\MedinTuxTools\medicabase\Dlg_HtmlView.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\medicabase\Dlg_HtmlView.ui -i Dlg_HtmlView.h -o ..\..\MedinTuxTools\medicabase\Dlg_HtmlView.cpp \
	$(QTDIR)\bin\moc  ..\..\MedinTuxTools\medicabase\Dlg_HtmlView.h -o moc\moc_Dlg_HtmlView.cpp \
	

"..\..\MedinTuxTools\medicabase\Dlg_HtmlView.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"..\..\MedinTuxTools\medicabase\Dlg_HtmlView.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_Dlg_HtmlView.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\medicabase\Dlg_MedicaAdjustPoso.ui

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__DLG_M="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing ..\..\MedinTuxTools\medicabase\Dlg_MedicaAdjustPoso.ui...
InputPath=..\..\MedinTuxTools\medicabase\Dlg_MedicaAdjustPoso.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\medicabase\Dlg_MedicaAdjustPoso.ui -o ..\..\MedinTuxTools\medicabase\Dlg_MedicaAdjustPoso.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\medicabase\Dlg_MedicaAdjustPoso.ui -i Dlg_MedicaAdjustPoso.h -o ..\..\MedinTuxTools\medicabase\Dlg_MedicaAdjustPoso.cpp \
	$(QTDIR)\bin\moc  ..\..\MedinTuxTools\medicabase\Dlg_MedicaAdjustPoso.h -o moc\moc_Dlg_MedicaAdjustPoso.cpp \
	

"..\..\MedinTuxTools\medicabase\Dlg_MedicaAdjustPoso.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"..\..\MedinTuxTools\medicabase\Dlg_MedicaAdjustPoso.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_Dlg_MedicaAdjustPoso.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__DLG_M="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing ..\..\MedinTuxTools\medicabase\Dlg_MedicaAdjustPoso.ui...
InputPath=..\..\MedinTuxTools\medicabase\Dlg_MedicaAdjustPoso.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\medicabase\Dlg_MedicaAdjustPoso.ui -o ..\..\MedinTuxTools\medicabase\Dlg_MedicaAdjustPoso.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\medicabase\Dlg_MedicaAdjustPoso.ui -i Dlg_MedicaAdjustPoso.h -o ..\..\MedinTuxTools\medicabase\Dlg_MedicaAdjustPoso.cpp \
	$(QTDIR)\bin\moc  ..\..\MedinTuxTools\medicabase\Dlg_MedicaAdjustPoso.h -o moc\moc_Dlg_MedicaAdjustPoso.cpp \
	

"..\..\MedinTuxTools\medicabase\Dlg_MedicaAdjustPoso.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"..\..\MedinTuxTools\medicabase\Dlg_MedicaAdjustPoso.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_Dlg_MedicaAdjustPoso.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\medicabase\Dlg_MedicaTux.ui

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__DLG_ME="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing ..\..\MedinTuxTools\medicabase\Dlg_MedicaTux.ui...
InputPath=..\..\MedinTuxTools\medicabase\Dlg_MedicaTux.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\medicabase\Dlg_MedicaTux.ui -o ..\..\MedinTuxTools\medicabase\Dlg_MedicaTux.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\medicabase\Dlg_MedicaTux.ui -i Dlg_MedicaTux.h -o ..\..\MedinTuxTools\medicabase\Dlg_MedicaTux.cpp \
	$(QTDIR)\bin\moc  ..\..\MedinTuxTools\medicabase\Dlg_MedicaTux.h -o moc\moc_Dlg_MedicaTux.cpp \
	

"..\..\MedinTuxTools\medicabase\Dlg_MedicaTux.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"..\..\MedinTuxTools\medicabase\Dlg_MedicaTux.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_Dlg_MedicaTux.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__DLG_ME="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing ..\..\MedinTuxTools\medicabase\Dlg_MedicaTux.ui...
InputPath=..\..\MedinTuxTools\medicabase\Dlg_MedicaTux.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\medicabase\Dlg_MedicaTux.ui -o ..\..\MedinTuxTools\medicabase\Dlg_MedicaTux.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\medicabase\Dlg_MedicaTux.ui -i Dlg_MedicaTux.h -o ..\..\MedinTuxTools\medicabase\Dlg_MedicaTux.cpp \
	$(QTDIR)\bin\moc  ..\..\MedinTuxTools\medicabase\Dlg_MedicaTux.h -o moc\moc_Dlg_MedicaTux.cpp \
	

"..\..\MedinTuxTools\medicabase\Dlg_MedicaTux.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"..\..\MedinTuxTools\medicabase\Dlg_MedicaTux.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_Dlg_MedicaTux.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\Dlg_PasswordGet.ui

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__DLG_P="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing ..\..\MedinTuxTools\Dlg_PasswordGet.ui...
InputPath=..\..\MedinTuxTools\Dlg_PasswordGet.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\Dlg_PasswordGet.ui -o ..\..\MedinTuxTools\Dlg_PasswordGet.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\Dlg_PasswordGet.ui -i Dlg_PasswordGet.h -o ..\..\MedinTuxTools\Dlg_PasswordGet.cpp \
	$(QTDIR)\bin\moc  ..\..\MedinTuxTools\Dlg_PasswordGet.h -o moc\moc_Dlg_PasswordGet.cpp \
	

"..\..\MedinTuxTools\Dlg_PasswordGet.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"..\..\MedinTuxTools\Dlg_PasswordGet.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_Dlg_PasswordGet.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__DLG_P="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing ..\..\MedinTuxTools\Dlg_PasswordGet.ui...
InputPath=..\..\MedinTuxTools\Dlg_PasswordGet.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\Dlg_PasswordGet.ui -o ..\..\MedinTuxTools\Dlg_PasswordGet.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\Dlg_PasswordGet.ui -i Dlg_PasswordGet.h -o ..\..\MedinTuxTools\Dlg_PasswordGet.cpp \
	$(QTDIR)\bin\moc  ..\..\MedinTuxTools\Dlg_PasswordGet.h -o moc\moc_Dlg_PasswordGet.cpp \
	

"..\..\MedinTuxTools\Dlg_PasswordGet.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"..\..\MedinTuxTools\Dlg_PasswordGet.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_Dlg_PasswordGet.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\medicabase\Dlg_PosoManager.ui

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__DLG_PO="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing ..\..\MedinTuxTools\medicabase\Dlg_PosoManager.ui...
InputPath=..\..\MedinTuxTools\medicabase\Dlg_PosoManager.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\medicabase\Dlg_PosoManager.ui -o ..\..\MedinTuxTools\medicabase\Dlg_PosoManager.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\medicabase\Dlg_PosoManager.ui -i Dlg_PosoManager.h -o ..\..\MedinTuxTools\medicabase\Dlg_PosoManager.cpp \
	$(QTDIR)\bin\moc  ..\..\MedinTuxTools\medicabase\Dlg_PosoManager.h -o moc\moc_Dlg_PosoManager.cpp \
	

"..\..\MedinTuxTools\medicabase\Dlg_PosoManager.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"..\..\MedinTuxTools\medicabase\Dlg_PosoManager.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_Dlg_PosoManager.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__DLG_PO="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing ..\..\MedinTuxTools\medicabase\Dlg_PosoManager.ui...
InputPath=..\..\MedinTuxTools\medicabase\Dlg_PosoManager.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\medicabase\Dlg_PosoManager.ui -o ..\..\MedinTuxTools\medicabase\Dlg_PosoManager.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\medicabase\Dlg_PosoManager.ui -i Dlg_PosoManager.h -o ..\..\MedinTuxTools\medicabase\Dlg_PosoManager.cpp \
	$(QTDIR)\bin\moc  ..\..\MedinTuxTools\medicabase\Dlg_PosoManager.h -o moc\moc_Dlg_PosoManager.cpp \
	

"..\..\MedinTuxTools\medicabase\Dlg_PosoManager.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"..\..\MedinTuxTools\medicabase\Dlg_PosoManager.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_Dlg_PosoManager.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\DlgGetString.ui

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__DLGGE="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing ..\..\MedinTuxTools\DlgGetString.ui...
InputPath=..\..\MedinTuxTools\DlgGetString.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DlgGetString.ui -o ..\..\MedinTuxTools\DlgGetString.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DlgGetString.ui -i DlgGetString.h -o ..\..\MedinTuxTools\DlgGetString.cpp \
	$(QTDIR)\bin\moc  ..\..\MedinTuxTools\DlgGetString.h -o moc\moc_DlgGetString.cpp \
	

"..\..\MedinTuxTools\DlgGetString.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"..\..\MedinTuxTools\DlgGetString.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_DlgGetString.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__DLGGE="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing ..\..\MedinTuxTools\DlgGetString.ui...
InputPath=..\..\MedinTuxTools\DlgGetString.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DlgGetString.ui -o ..\..\MedinTuxTools\DlgGetString.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DlgGetString.ui -i DlgGetString.h -o ..\..\MedinTuxTools\DlgGetString.cpp \
	$(QTDIR)\bin\moc  ..\..\MedinTuxTools\DlgGetString.h -o moc\moc_DlgGetString.cpp \
	

"..\..\MedinTuxTools\DlgGetString.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"..\..\MedinTuxTools\DlgGetString.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_DlgGetString.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\DlgMyMessageBox.ui

!IF  "$(CFG)" == " - Win32 Release"

USERDEP__DLGMY="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing ..\..\MedinTuxTools\DlgMyMessageBox.ui...
InputPath=..\..\MedinTuxTools\DlgMyMessageBox.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DlgMyMessageBox.ui -o ..\..\MedinTuxTools\DlgMyMessageBox.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DlgMyMessageBox.ui -i DlgMyMessageBox.h -o ..\..\MedinTuxTools\DlgMyMessageBox.cpp \
	$(QTDIR)\bin\moc  ..\..\MedinTuxTools\DlgMyMessageBox.h -o moc\moc_DlgMyMessageBox.cpp \
	

"..\..\MedinTuxTools\DlgMyMessageBox.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"..\..\MedinTuxTools\DlgMyMessageBox.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_DlgMyMessageBox.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

USERDEP__DLGMY="$(QTDIR)\bin\moc.exe"	"$(QTDIR)\bin\uic.exe"	
# Begin Custom Build - Uic'ing ..\..\MedinTuxTools\DlgMyMessageBox.ui...
InputPath=..\..\MedinTuxTools\DlgMyMessageBox.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DlgMyMessageBox.ui -o ..\..\MedinTuxTools\DlgMyMessageBox.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DlgMyMessageBox.ui -i DlgMyMessageBox.h -o ..\..\MedinTuxTools\DlgMyMessageBox.cpp \
	$(QTDIR)\bin\moc  ..\..\MedinTuxTools\DlgMyMessageBox.h -o moc\moc_DlgMyMessageBox.cpp \
	

"..\..\MedinTuxTools\DlgMyMessageBox.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"..\..\MedinTuxTools\DlgMyMessageBox.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"moc\moc_DlgMyMessageBox.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "Generated"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\MedinTuxTools\medicabase\Dlg_AdvancedTerrain.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\medicabase\Dlg_AdvancedTerrain.h
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\medicabase\Dlg_HtmlView.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\medicabase\Dlg_HtmlView.h
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\medicabase\Dlg_MedicaAdjustPoso.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\medicabase\Dlg_MedicaAdjustPoso.h
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\medicabase\Dlg_MedicaTux.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\medicabase\Dlg_MedicaTux.h
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\Dlg_PasswordGet.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\Dlg_PasswordGet.h
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\medicabase\Dlg_PosoManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\medicabase\Dlg_PosoManager.h
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\DlgGetString.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\DlgGetString.h
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\DlgMyMessageBox.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\DlgMyMessageBox.h
# End Source File
# Begin Source File

SOURCE=moc\moc_C_MUI_App.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_cdlg_passwordget.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CMaskedLineEdit.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_Dlg_AdvancedTerrain.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_Dlg_HtmlView.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_Dlg_MedicaAdjustPoso.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_Dlg_MedicaTux.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_Dlg_PasswordGet.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_Dlg_PosoManager.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_DlgGetString.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_DlgMyMessageBox.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_qtsingleapplication.cpp
# End Source File
# End Group
# End Target
# End Project
