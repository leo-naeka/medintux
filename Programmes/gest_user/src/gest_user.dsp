# Microsoft Developer Studio Project File - Name="" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86)  Application" 0x0101

CFG= - Win32 Debug
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
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD CPP -MD /W3 /I "..\..\SesamVitale-QT3" /I "..\src" /I "$(QTDIR)\include" /I "ui" /I "." /I "..\..\MedinTuxTools" /I "." /I "moc" /I "C:\Qt3\3.3.4\mkspecs\win32-msvc" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D _GEST_USER /D SESAMVITALE_VERSION /D QT_DLL /D QT_THREAD_SUPPORT /D "QT_NO_DEBUG" /FD /c -nologo -Zm200 -GX -O1 
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BSC32 /nologo
LINK32=link.exe
# ADD LINK32  "qt-mt334.lib"  "qtmain.lib"  "kernel32.lib"  "user32.lib"  "gdi32.lib"  "comdlg32.lib"  "advapi32.lib"  "shell32.lib"  "ole32.lib"  "oleaut32.lib"  "uuid.lib"  "imm32.lib"  "winmm.lib"  "wsock32.lib"  "winspool.lib"  "kernel32.lib"  "user32.lib"  "gdi32.lib"  "comdlg32.lib"  "advapi32.lib"  "shell32.lib"  "ole32.lib"  "oleaut32.lib"  "uuid.lib"  "imm32.lib"  "winmm.lib"  "wsock32.lib"  "winspool.lib"  "opengl32.lib"  "glu32.lib"  "delayimp.lib"   /NOLOGO /SUBSYSTEM:windows /LIBPATH:"$(QTDIR)\lib" delayimp.lib /DELAYLOAD:comdlg32.dll /DELAYLOAD:oleaut32.dll /DELAYLOAD:winmm.dll /DELAYLOAD:wsock32.dll /DELAYLOAD:winspool.dll  /out:"../bin/gest_user.exe


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
# PROP Target_Dir ""
# ADD CPP -MDd /W3 /GZ /ZI /Od /I "..\..\SesamVitale-QT3" /I "..\src" /I "$(QTDIR)\include" /I "ui" /I "." /I "..\..\MedinTuxTools" /I "." /I "moc" /I "C:\Qt3\3.3.4\mkspecs\win32-msvc" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D _GEST_USER /D SESAMVITALE_VERSION /D QT_DLL /D QT_THREAD_SUPPORT /FD /c -nologo -Zm200 -GX -Zi  
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BSC32 /nologo
LINK32=link.exe
# ADD LINK32  "qt-mt334.lib"  "qtmain.lib"  "kernel32.lib"  "user32.lib"  "gdi32.lib"  "comdlg32.lib"  "advapi32.lib"  "shell32.lib"  "ole32.lib"  "oleaut32.lib"  "uuid.lib"  "imm32.lib"  "winmm.lib"  "wsock32.lib"  "winspool.lib"  "kernel32.lib"  "user32.lib"  "gdi32.lib"  "comdlg32.lib"  "advapi32.lib"  "shell32.lib"  "ole32.lib"  "oleaut32.lib"  "uuid.lib"  "imm32.lib"  "winmm.lib"  "wsock32.lib"  "winspool.lib"  "opengl32.lib"  "glu32.lib"  "delayimp.lib"   /NOLOGO /SUBSYSTEM:windows /LIBPATH:"$(QTDIR)\lib" /pdbtype:sept /DEBUG  /out:"../bin/gest_user.exe


!ENDIF 

# Begin Target

# Name " - Win32 Release"
# Name " - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\..\SesamVitale-QT3\qtsingleapplication.cpp
# End Source File
# Begin Source File

SOURCE=..\..\SesamVitale-QT3\qtsingleapplication_win.cpp
# End Source File
# Begin Source File

SOURCE=..\..\SesamVitale-QT3\C_Cps.cpp
# End Source File
# Begin Source File

SOURCE=..\..\SesamVitale-QT3\CSesam_API_InfoGroupe.cpp
# End Source File
# Begin Source File

SOURCE=..\..\SesamVitale-QT3\C_Vitale.cpp
# End Source File
# Begin Source File

SOURCE=gest_user.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CMaskedLineEdit.cpp
# End Source File
# Begin Source File

SOURCE=main.cpp
# End Source File
# Begin Source File

SOURCE=FormOngletRubrique.cpp
# End Source File
# Begin Source File

SOURCE=MyEditText.cpp
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

SOURCE=..\..\drtux\src\CMoteur_Base.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CHtmlTools.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CGenTools.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CGestIni.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CSetupBase.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CMedinTuxApp.cpp
# End Source File
# Begin Source File

SOURCE=CApp.cpp
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\cdlg_passwordget.cpp
# End Source File
# Begin Source File

SOURCE=CDlg_IntervList.cpp
# End Source File
# Begin Source File

SOURCE=DockFormUserList.ui.h
# End Source File
# Begin Source File

SOURCE=DockFormUserListDoc.ui.h
# End Source File
# Begin Source File

SOURCE=RubIdentite.ui.h
# End Source File
# Begin Source File

SOURCE=DlgPassChange.ui.h
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\DlgGetString.ui.h
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\DlgMyMessageBox.ui.h
# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\DLG_InsertList.ui.h
# End Source File
# Begin Source File

SOURCE=Dlg_PermsUserChoice.ui.h
# End Source File
# Begin Source File

SOURCE=Dlg_PermsDefine.ui.h
# End Source File
# Begin Source File

SOURCE=Dlg_Appartenance.ui.h
# End Source File

# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\..\SesamVitale-QT3\qtsingleapplication.h

USERDEP_=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing ..\..\SesamVitale-QT3\qtsingleapplication.h...
InputPath=.\..\..\SesamVitale-QT3\qtsingleapplication.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\SesamVitale-QT3\qtsingleapplication.h -o moc\moc_qtsingleapplication.cpp \

"moc\moc_qtsingleapplication.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing ..\..\SesamVitale-QT3\qtsingleapplication.h...
InputPath=.\..\..\SesamVitale-QT3\qtsingleapplication.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\SesamVitale-QT3\qtsingleapplication.h -o moc\moc_qtsingleapplication.cpp \

"moc\moc_qtsingleapplication.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\SesamVitale-QT3\C_Cps.h

# End Source File
# Begin Source File

SOURCE=..\..\SesamVitale-QT3\CSesam_API_InfoGroupe.h

# End Source File
# Begin Source File

SOURCE=..\..\SesamVitale-QT3\C_Vitale.h

# End Source File
# Begin Source File

SOURCE=gest_user.h

USERDEP_gest_user=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing gest_user.h...
InputPath=.\gest_user.h


BuildCmds= \
	$(QTDIR)\bin\moc gest_user.h -o moc\moc_gest_user.cpp \

"moc\moc_gest_user.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing gest_user.h...
InputPath=.\gest_user.h


BuildCmds= \
	$(QTDIR)\bin\moc gest_user.h -o moc\moc_gest_user.cpp \

"moc\moc_gest_user.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CMaskedLineEdit.h

USERDEP_=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing ..\..\MedinTuxTools\CMaskedLineEdit.h...
InputPath=.\..\..\MedinTuxTools\CMaskedLineEdit.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\MedinTuxTools\CMaskedLineEdit.h -o moc\moc_CMaskedLineEdit.cpp \

"moc\moc_CMaskedLineEdit.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing ..\..\MedinTuxTools\CMaskedLineEdit.h...
InputPath=.\..\..\MedinTuxTools\CMaskedLineEdit.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\MedinTuxTools\CMaskedLineEdit.h -o moc\moc_CMaskedLineEdit.cpp \

"moc\moc_CMaskedLineEdit.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=FormOngletRubrique.h

USERDEP_FormOngletRubrique=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing FormOngletRubrique.h...
InputPath=.\FormOngletRubrique.h


BuildCmds= \
	$(QTDIR)\bin\moc FormOngletRubrique.h -o moc\moc_FormOngletRubrique.cpp \

"moc\moc_FormOngletRubrique.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing FormOngletRubrique.h...
InputPath=.\FormOngletRubrique.h


BuildCmds= \
	$(QTDIR)\bin\moc FormOngletRubrique.h -o moc\moc_FormOngletRubrique.cpp \

"moc\moc_FormOngletRubrique.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=MyEditText.h

USERDEP_MyEditText=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing MyEditText.h...
InputPath=.\MyEditText.h


BuildCmds= \
	$(QTDIR)\bin\moc MyEditText.h -o moc\moc_MyEditText.cpp \

"moc\moc_MyEditText.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing MyEditText.h...
InputPath=.\MyEditText.h


BuildCmds= \
	$(QTDIR)\bin\moc MyEditText.h -o moc\moc_MyEditText.cpp \

"moc\moc_MyEditText.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=Rubriques.h

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CPrtQListBoxItem.h

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

SOURCE=..\..\MedinTuxTools\CHtmlTools.h

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CGenTools.h

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CGestIni.h

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CSetupBase.h

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CMedinTuxApp.h

USERDEP_=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing ..\..\MedinTuxTools\CMedinTuxApp.h...
InputPath=.\..\..\MedinTuxTools\CMedinTuxApp.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\MedinTuxTools\CMedinTuxApp.h -o moc\moc_CMedinTuxApp.cpp \

"moc\moc_CMedinTuxApp.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing ..\..\MedinTuxTools\CMedinTuxApp.h...
InputPath=.\..\..\MedinTuxTools\CMedinTuxApp.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\MedinTuxTools\CMedinTuxApp.h -o moc\moc_CMedinTuxApp.cpp \

"moc\moc_CMedinTuxApp.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\CPreview.h

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

SOURCE=DlgPassChangeDefine.h

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\cdlg_passwordget.h

USERDEP_=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing ..\..\MedinTuxTools\cdlg_passwordget.h...
InputPath=.\..\..\MedinTuxTools\cdlg_passwordget.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\MedinTuxTools\cdlg_passwordget.h -o moc\moc_cdlg_passwordget.cpp \

"moc\moc_cdlg_passwordget.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing ..\..\MedinTuxTools\cdlg_passwordget.h...
InputPath=.\..\..\MedinTuxTools\cdlg_passwordget.h


BuildCmds= \
	$(QTDIR)\bin\moc ..\..\MedinTuxTools\cdlg_passwordget.h -o moc\moc_cdlg_passwordget.cpp \

"moc\moc_cdlg_passwordget.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=CDlg_IntervList.h

USERDEP_CDlg_IntervList=""$(QTDIR)\bin\moc.exe""

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Moc'ing CDlg_IntervList.h...
InputPath=.\CDlg_IntervList.h


BuildCmds= \
	$(QTDIR)\bin\moc CDlg_IntervList.h -o moc\moc_CDlg_IntervList.cpp \

"moc\moc_CDlg_IntervList.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Moc'ing CDlg_IntervList.h...
InputPath=.\CDlg_IntervList.h


BuildCmds= \
	$(QTDIR)\bin\moc CDlg_IntervList.h -o moc\moc_CDlg_IntervList.cpp \

"moc\moc_CDlg_IntervList.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
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

SOURCE=DockFormUserList.ui
USERDEP_DockFormUserList.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing DockFormUserList.ui...
InputPath=.\DockFormUserList.ui

BuildCmds= \
	$(QTDIR)\bin\uic DockFormUserList.ui -o ui\DockFormUserList.h \
	$(QTDIR)\bin\uic DockFormUserList.ui -i DockFormUserList.h -o ui\DockFormUserList.cpp \
	$(QTDIR)\bin\moc  ui\DockFormUserList.h -o moc\moc_DockFormUserList.cpp \

"ui\DockFormUserList.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\DockFormUserList.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DockFormUserList.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing DockFormUserList.ui...
InputPath=.\DockFormUserList.ui

BuildCmds= \
	$(QTDIR)\bin\uic DockFormUserList.ui -o ui\DockFormUserList.h \
	$(QTDIR)\bin\uic DockFormUserList.ui -i DockFormUserList.h -o ui\DockFormUserList.cpp \
	$(QTDIR)\bin\moc  ui\DockFormUserList.h -o moc\moc_DockFormUserList.cpp \

"ui\DockFormUserList.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\DockFormUserList.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DockFormUserList.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=DockFormUserListDoc.ui
USERDEP_DockFormUserListDoc.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing DockFormUserListDoc.ui...
InputPath=.\DockFormUserListDoc.ui

BuildCmds= \
	$(QTDIR)\bin\uic DockFormUserListDoc.ui -o ui\DockFormUserListDoc.h \
	$(QTDIR)\bin\uic DockFormUserListDoc.ui -i DockFormUserListDoc.h -o ui\DockFormUserListDoc.cpp \
	$(QTDIR)\bin\moc  ui\DockFormUserListDoc.h -o moc\moc_DockFormUserListDoc.cpp \

"ui\DockFormUserListDoc.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\DockFormUserListDoc.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DockFormUserListDoc.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing DockFormUserListDoc.ui...
InputPath=.\DockFormUserListDoc.ui

BuildCmds= \
	$(QTDIR)\bin\uic DockFormUserListDoc.ui -o ui\DockFormUserListDoc.h \
	$(QTDIR)\bin\uic DockFormUserListDoc.ui -i DockFormUserListDoc.h -o ui\DockFormUserListDoc.cpp \
	$(QTDIR)\bin\moc  ui\DockFormUserListDoc.h -o moc\moc_DockFormUserListDoc.cpp \

"ui\DockFormUserListDoc.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\DockFormUserListDoc.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DockFormUserListDoc.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=RubIdentite.ui
USERDEP_RubIdentite.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing RubIdentite.ui...
InputPath=.\RubIdentite.ui

BuildCmds= \
	$(QTDIR)\bin\uic RubIdentite.ui -o ui\RubIdentite.h \
	$(QTDIR)\bin\uic RubIdentite.ui -i RubIdentite.h -o ui\RubIdentite.cpp \
	$(QTDIR)\bin\moc  ui\RubIdentite.h -o moc\moc_RubIdentite.cpp \

"ui\RubIdentite.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\RubIdentite.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_RubIdentite.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing RubIdentite.ui...
InputPath=.\RubIdentite.ui

BuildCmds= \
	$(QTDIR)\bin\uic RubIdentite.ui -o ui\RubIdentite.h \
	$(QTDIR)\bin\uic RubIdentite.ui -i RubIdentite.h -o ui\RubIdentite.cpp \
	$(QTDIR)\bin\moc  ui\RubIdentite.h -o moc\moc_RubIdentite.cpp \

"ui\RubIdentite.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\RubIdentite.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_RubIdentite.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=FormRubOrdo.ui
USERDEP_FormRubOrdo.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing FormRubOrdo.ui...
InputPath=.\FormRubOrdo.ui

BuildCmds= \
	$(QTDIR)\bin\uic FormRubOrdo.ui -o ui\FormRubOrdo.h \
	$(QTDIR)\bin\uic FormRubOrdo.ui -i FormRubOrdo.h -o ui\FormRubOrdo.cpp \
	$(QTDIR)\bin\moc  ui\FormRubOrdo.h -o moc\moc_FormRubOrdo.cpp \

"ui\FormRubOrdo.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\FormRubOrdo.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_FormRubOrdo.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing FormRubOrdo.ui...
InputPath=.\FormRubOrdo.ui

BuildCmds= \
	$(QTDIR)\bin\uic FormRubOrdo.ui -o ui\FormRubOrdo.h \
	$(QTDIR)\bin\uic FormRubOrdo.ui -i FormRubOrdo.h -o ui\FormRubOrdo.cpp \
	$(QTDIR)\bin\moc  ui\FormRubOrdo.h -o moc\moc_FormRubOrdo.cpp \

"ui\FormRubOrdo.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\FormRubOrdo.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_FormRubOrdo.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=FormRubCertificat.ui
USERDEP_FormRubCertificat.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing FormRubCertificat.ui...
InputPath=.\FormRubCertificat.ui

BuildCmds= \
	$(QTDIR)\bin\uic FormRubCertificat.ui -o ui\FormRubCertificat.h \
	$(QTDIR)\bin\uic FormRubCertificat.ui -i FormRubCertificat.h -o ui\FormRubCertificat.cpp \
	$(QTDIR)\bin\moc  ui\FormRubCertificat.h -o moc\moc_FormRubCertificat.cpp \

"ui\FormRubCertificat.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\FormRubCertificat.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_FormRubCertificat.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing FormRubCertificat.ui...
InputPath=.\FormRubCertificat.ui

BuildCmds= \
	$(QTDIR)\bin\uic FormRubCertificat.ui -o ui\FormRubCertificat.h \
	$(QTDIR)\bin\uic FormRubCertificat.ui -i FormRubCertificat.h -o ui\FormRubCertificat.cpp \
	$(QTDIR)\bin\moc  ui\FormRubCertificat.h -o moc\moc_FormRubCertificat.cpp \

"ui\FormRubCertificat.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\FormRubCertificat.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_FormRubCertificat.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=FormRubObservation.ui
USERDEP_FormRubObservation.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing FormRubObservation.ui...
InputPath=.\FormRubObservation.ui

BuildCmds= \
	$(QTDIR)\bin\uic FormRubObservation.ui -o ui\FormRubObservation.h \
	$(QTDIR)\bin\uic FormRubObservation.ui -i FormRubObservation.h -o ui\FormRubObservation.cpp \
	$(QTDIR)\bin\moc  ui\FormRubObservation.h -o moc\moc_FormRubObservation.cpp \

"ui\FormRubObservation.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\FormRubObservation.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_FormRubObservation.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing FormRubObservation.ui...
InputPath=.\FormRubObservation.ui

BuildCmds= \
	$(QTDIR)\bin\uic FormRubObservation.ui -o ui\FormRubObservation.h \
	$(QTDIR)\bin\uic FormRubObservation.ui -i FormRubObservation.h -o ui\FormRubObservation.cpp \
	$(QTDIR)\bin\moc  ui\FormRubObservation.h -o moc\moc_FormRubObservation.cpp \

"ui\FormRubObservation.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\FormRubObservation.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_FormRubObservation.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=FormRubParam.ui
USERDEP_FormRubParam.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing FormRubParam.ui...
InputPath=.\FormRubParam.ui

BuildCmds= \
	$(QTDIR)\bin\uic FormRubParam.ui -o ui\FormRubParam.h \
	$(QTDIR)\bin\uic FormRubParam.ui -i FormRubParam.h -o ui\FormRubParam.cpp \
	$(QTDIR)\bin\moc  ui\FormRubParam.h -o moc\moc_FormRubParam.cpp \

"ui\FormRubParam.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\FormRubParam.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_FormRubParam.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing FormRubParam.ui...
InputPath=.\FormRubParam.ui

BuildCmds= \
	$(QTDIR)\bin\uic FormRubParam.ui -o ui\FormRubParam.h \
	$(QTDIR)\bin\uic FormRubParam.ui -i FormRubParam.h -o ui\FormRubParam.cpp \
	$(QTDIR)\bin\moc  ui\FormRubParam.h -o moc\moc_FormRubParam.cpp \

"ui\FormRubParam.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\FormRubParam.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_FormRubParam.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=DlgPassChange.ui
USERDEP_DlgPassChange.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing DlgPassChange.ui...
InputPath=.\DlgPassChange.ui

BuildCmds= \
	$(QTDIR)\bin\uic DlgPassChange.ui -o ui\DlgPassChange.h \
	$(QTDIR)\bin\uic DlgPassChange.ui -i DlgPassChange.h -o ui\DlgPassChange.cpp \
	$(QTDIR)\bin\moc  ui\DlgPassChange.h -o moc\moc_DlgPassChange.cpp \

"ui\DlgPassChange.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\DlgPassChange.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DlgPassChange.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing DlgPassChange.ui...
InputPath=.\DlgPassChange.ui

BuildCmds= \
	$(QTDIR)\bin\uic DlgPassChange.ui -o ui\DlgPassChange.h \
	$(QTDIR)\bin\uic DlgPassChange.ui -i DlgPassChange.h -o ui\DlgPassChange.cpp \
	$(QTDIR)\bin\moc  ui\DlgPassChange.h -o moc\moc_DlgPassChange.cpp \

"ui\DlgPassChange.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\DlgPassChange.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DlgPassChange.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\DlgGetString.ui
USERDEP_..\..\MedinTuxTools\DlgGetString.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing ..\..\MedinTuxTools\DlgGetString.ui...
InputPath=.\..\..\MedinTuxTools\DlgGetString.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DlgGetString.ui -o ui\DlgGetString.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DlgGetString.ui -i DlgGetString.h -o ui\DlgGetString.cpp \
	$(QTDIR)\bin\moc  ui\DlgGetString.h -o moc\moc_DlgGetString.cpp \

"ui\DlgGetString.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\DlgGetString.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DlgGetString.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing ..\..\MedinTuxTools\DlgGetString.ui...
InputPath=.\..\..\MedinTuxTools\DlgGetString.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DlgGetString.ui -o ui\DlgGetString.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DlgGetString.ui -i DlgGetString.h -o ui\DlgGetString.cpp \
	$(QTDIR)\bin\moc  ui\DlgGetString.h -o moc\moc_DlgGetString.cpp \

"ui\DlgGetString.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\DlgGetString.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DlgGetString.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\DlgMyMessageBox.ui
USERDEP_..\..\MedinTuxTools\DlgMyMessageBox.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing ..\..\MedinTuxTools\DlgMyMessageBox.ui...
InputPath=.\..\..\MedinTuxTools\DlgMyMessageBox.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DlgMyMessageBox.ui -o ui\DlgMyMessageBox.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DlgMyMessageBox.ui -i DlgMyMessageBox.h -o ui\DlgMyMessageBox.cpp \
	$(QTDIR)\bin\moc  ui\DlgMyMessageBox.h -o moc\moc_DlgMyMessageBox.cpp \

"ui\DlgMyMessageBox.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\DlgMyMessageBox.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DlgMyMessageBox.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing ..\..\MedinTuxTools\DlgMyMessageBox.ui...
InputPath=.\..\..\MedinTuxTools\DlgMyMessageBox.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DlgMyMessageBox.ui -o ui\DlgMyMessageBox.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DlgMyMessageBox.ui -i DlgMyMessageBox.h -o ui\DlgMyMessageBox.cpp \
	$(QTDIR)\bin\moc  ui\DlgMyMessageBox.h -o moc\moc_DlgMyMessageBox.cpp \

"ui\DlgMyMessageBox.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\DlgMyMessageBox.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DlgMyMessageBox.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\DLG_InsertList.ui
USERDEP_..\..\MedinTuxTools\DLG_InsertList.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing ..\..\MedinTuxTools\DLG_InsertList.ui...
InputPath=.\..\..\MedinTuxTools\DLG_InsertList.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DLG_InsertList.ui -o ui\DLG_InsertList.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DLG_InsertList.ui -i DLG_InsertList.h -o ui\DLG_InsertList.cpp \
	$(QTDIR)\bin\moc  ui\DLG_InsertList.h -o moc\moc_DLG_InsertList.cpp \

"ui\DLG_InsertList.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\DLG_InsertList.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DLG_InsertList.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing ..\..\MedinTuxTools\DLG_InsertList.ui...
InputPath=.\..\..\MedinTuxTools\DLG_InsertList.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DLG_InsertList.ui -o ui\DLG_InsertList.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\DLG_InsertList.ui -i DLG_InsertList.h -o ui\DLG_InsertList.cpp \
	$(QTDIR)\bin\moc  ui\DLG_InsertList.h -o moc\moc_DLG_InsertList.cpp \

"ui\DLG_InsertList.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\DLG_InsertList.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_DLG_InsertList.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=Dlg_PermsUserChoice.ui
USERDEP_Dlg_PermsUserChoice.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing Dlg_PermsUserChoice.ui...
InputPath=.\Dlg_PermsUserChoice.ui

BuildCmds= \
	$(QTDIR)\bin\uic Dlg_PermsUserChoice.ui -o ui\Dlg_PermsUserChoice.h \
	$(QTDIR)\bin\uic Dlg_PermsUserChoice.ui -i Dlg_PermsUserChoice.h -o ui\Dlg_PermsUserChoice.cpp \
	$(QTDIR)\bin\moc  ui\Dlg_PermsUserChoice.h -o moc\moc_Dlg_PermsUserChoice.cpp \

"ui\Dlg_PermsUserChoice.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\Dlg_PermsUserChoice.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_Dlg_PermsUserChoice.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing Dlg_PermsUserChoice.ui...
InputPath=.\Dlg_PermsUserChoice.ui

BuildCmds= \
	$(QTDIR)\bin\uic Dlg_PermsUserChoice.ui -o ui\Dlg_PermsUserChoice.h \
	$(QTDIR)\bin\uic Dlg_PermsUserChoice.ui -i Dlg_PermsUserChoice.h -o ui\Dlg_PermsUserChoice.cpp \
	$(QTDIR)\bin\moc  ui\Dlg_PermsUserChoice.h -o moc\moc_Dlg_PermsUserChoice.cpp \

"ui\Dlg_PermsUserChoice.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\Dlg_PermsUserChoice.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_Dlg_PermsUserChoice.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\MedinTuxTools\Dlg_PasswordGet.ui
USERDEP_..\..\MedinTuxTools\Dlg_PasswordGet.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing ..\..\MedinTuxTools\Dlg_PasswordGet.ui...
InputPath=.\..\..\MedinTuxTools\Dlg_PasswordGet.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\Dlg_PasswordGet.ui -o ui\Dlg_PasswordGet.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\Dlg_PasswordGet.ui -i Dlg_PasswordGet.h -o ui\Dlg_PasswordGet.cpp \
	$(QTDIR)\bin\moc  ui\Dlg_PasswordGet.h -o moc\moc_Dlg_PasswordGet.cpp \

"ui\Dlg_PasswordGet.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\Dlg_PasswordGet.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_Dlg_PasswordGet.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing ..\..\MedinTuxTools\Dlg_PasswordGet.ui...
InputPath=.\..\..\MedinTuxTools\Dlg_PasswordGet.ui

BuildCmds= \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\Dlg_PasswordGet.ui -o ui\Dlg_PasswordGet.h \
	$(QTDIR)\bin\uic ..\..\MedinTuxTools\Dlg_PasswordGet.ui -i Dlg_PasswordGet.h -o ui\Dlg_PasswordGet.cpp \
	$(QTDIR)\bin\moc  ui\Dlg_PasswordGet.h -o moc\moc_Dlg_PasswordGet.cpp \

"ui\Dlg_PasswordGet.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\Dlg_PasswordGet.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_Dlg_PasswordGet.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=Dlg_PermsDefine.ui
USERDEP_Dlg_PermsDefine.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing Dlg_PermsDefine.ui...
InputPath=.\Dlg_PermsDefine.ui

BuildCmds= \
	$(QTDIR)\bin\uic Dlg_PermsDefine.ui -o ui\Dlg_PermsDefine.h \
	$(QTDIR)\bin\uic Dlg_PermsDefine.ui -i Dlg_PermsDefine.h -o ui\Dlg_PermsDefine.cpp \
	$(QTDIR)\bin\moc  ui\Dlg_PermsDefine.h -o moc\moc_Dlg_PermsDefine.cpp \

"ui\Dlg_PermsDefine.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\Dlg_PermsDefine.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_Dlg_PermsDefine.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing Dlg_PermsDefine.ui...
InputPath=.\Dlg_PermsDefine.ui

BuildCmds= \
	$(QTDIR)\bin\uic Dlg_PermsDefine.ui -o ui\Dlg_PermsDefine.h \
	$(QTDIR)\bin\uic Dlg_PermsDefine.ui -i Dlg_PermsDefine.h -o ui\Dlg_PermsDefine.cpp \
	$(QTDIR)\bin\moc  ui\Dlg_PermsDefine.h -o moc\moc_Dlg_PermsDefine.cpp \

"ui\Dlg_PermsDefine.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\Dlg_PermsDefine.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_Dlg_PermsDefine.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=Dlg_Appartenance.ui
USERDEP_Dlg_Appartenance.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing Dlg_Appartenance.ui...
InputPath=.\Dlg_Appartenance.ui

BuildCmds= \
	$(QTDIR)\bin\uic Dlg_Appartenance.ui -o ui\Dlg_Appartenance.h \
	$(QTDIR)\bin\uic Dlg_Appartenance.ui -i Dlg_Appartenance.h -o ui\Dlg_Appartenance.cpp \
	$(QTDIR)\bin\moc  ui\Dlg_Appartenance.h -o moc\moc_Dlg_Appartenance.cpp \

"ui\Dlg_Appartenance.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\Dlg_Appartenance.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_Dlg_Appartenance.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing Dlg_Appartenance.ui...
InputPath=.\Dlg_Appartenance.ui

BuildCmds= \
	$(QTDIR)\bin\uic Dlg_Appartenance.ui -o ui\Dlg_Appartenance.h \
	$(QTDIR)\bin\uic Dlg_Appartenance.ui -i Dlg_Appartenance.h -o ui\Dlg_Appartenance.cpp \
	$(QTDIR)\bin\moc  ui\Dlg_Appartenance.h -o moc\moc_Dlg_Appartenance.cpp \

"ui\Dlg_Appartenance.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\Dlg_Appartenance.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_Dlg_Appartenance.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=Dlg_IntervList.ui
USERDEP_Dlg_IntervList.ui="$(QTDIR)\bin\moc.exe" "$(QTDIR)\bin\uic.exe"

!IF  "$(CFG)" == " - Win32 Release"

# Begin Custom Build - Uic'ing Dlg_IntervList.ui...
InputPath=.\Dlg_IntervList.ui

BuildCmds= \
	$(QTDIR)\bin\uic Dlg_IntervList.ui -o ui\Dlg_IntervList.h \
	$(QTDIR)\bin\uic Dlg_IntervList.ui -i Dlg_IntervList.h -o ui\Dlg_IntervList.cpp \
	$(QTDIR)\bin\moc  ui\Dlg_IntervList.h -o moc\moc_Dlg_IntervList.cpp \

"ui\Dlg_IntervList.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\Dlg_IntervList.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_Dlg_IntervList.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ELSEIF  "$(CFG)" == " - Win32 Debug"

# Begin Custom Build - Uic'ing Dlg_IntervList.ui...
InputPath=.\Dlg_IntervList.ui

BuildCmds= \
	$(QTDIR)\bin\uic Dlg_IntervList.ui -o ui\Dlg_IntervList.h \
	$(QTDIR)\bin\uic Dlg_IntervList.ui -i Dlg_IntervList.h -o ui\Dlg_IntervList.cpp \
	$(QTDIR)\bin\moc  ui\Dlg_IntervList.h -o moc\moc_Dlg_IntervList.cpp \

"ui\Dlg_IntervList.h" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"ui\Dlg_IntervList.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

"moc\moc_Dlg_IntervList.cpp" : "$(SOURCE)" "$(INTDIR)" "$(OUTDIR)"
	$(BuildCmds)

# End Custom Build

!ENDIF 

# End Source File

# End Group

# Begin Group "Translations"
# Prop Default_Filter "ts"
# Begin Source File

SOURCE=gest_user_fr.ts

# End Source File

# End Group





# Begin Group "Generated"
# Begin Source File

SOURCE=moc\moc_qtsingleapplication.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_gest_user.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CMaskedLineEdit.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_FormOngletRubrique.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_MyEditText.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CPrtQListViewItem.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_ThemePopup.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CMoteur_Base.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CMedinTuxApp.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CApp.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_cdlg_passwordget.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_CDlg_IntervList.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_DockFormUserList.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_DockFormUserListDoc.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_RubIdentite.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_FormRubOrdo.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_FormRubCertificat.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_FormRubObservation.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_FormRubParam.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_DlgPassChange.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_DlgGetString.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_DlgMyMessageBox.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_DLG_InsertList.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_Dlg_PermsUserChoice.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_Dlg_PasswordGet.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_Dlg_PermsDefine.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_Dlg_Appartenance.cpp
# End Source File
# Begin Source File

SOURCE=moc\moc_Dlg_IntervList.cpp
# End Source File

# Begin Source File

SOURCE=ui\DockFormUserList.cpp
# End Source File
# Begin Source File

SOURCE=ui\DockFormUserListDoc.cpp
# End Source File
# Begin Source File

SOURCE=ui\RubIdentite.cpp
# End Source File
# Begin Source File

SOURCE=ui\FormRubOrdo.cpp
# End Source File
# Begin Source File

SOURCE=ui\FormRubCertificat.cpp
# End Source File
# Begin Source File

SOURCE=ui\FormRubObservation.cpp
# End Source File
# Begin Source File

SOURCE=ui\FormRubParam.cpp
# End Source File
# Begin Source File

SOURCE=ui\DlgPassChange.cpp
# End Source File
# Begin Source File

SOURCE=ui\DlgGetString.cpp
# End Source File
# Begin Source File

SOURCE=ui\DlgMyMessageBox.cpp
# End Source File
# Begin Source File

SOURCE=ui\DLG_InsertList.cpp
# End Source File
# Begin Source File

SOURCE=ui\Dlg_PermsUserChoice.cpp
# End Source File
# Begin Source File

SOURCE=ui\Dlg_PasswordGet.cpp
# End Source File
# Begin Source File

SOURCE=ui\Dlg_PermsDefine.cpp
# End Source File
# Begin Source File

SOURCE=ui\Dlg_Appartenance.cpp
# End Source File
# Begin Source File

SOURCE=ui\Dlg_IntervList.cpp
# End Source File

# Begin Source File

SOURCE=ui\DockFormUserList.h
# End Source File
# Begin Source File

SOURCE=ui\DockFormUserListDoc.h
# End Source File
# Begin Source File

SOURCE=ui\RubIdentite.h
# End Source File
# Begin Source File

SOURCE=ui\FormRubOrdo.h
# End Source File
# Begin Source File

SOURCE=ui\FormRubCertificat.h
# End Source File
# Begin Source File

SOURCE=ui\FormRubObservation.h
# End Source File
# Begin Source File

SOURCE=ui\FormRubParam.h
# End Source File
# Begin Source File

SOURCE=ui\DlgPassChange.h
# End Source File
# Begin Source File

SOURCE=ui\DlgGetString.h
# End Source File
# Begin Source File

SOURCE=ui\DlgMyMessageBox.h
# End Source File
# Begin Source File

SOURCE=ui\DLG_InsertList.h
# End Source File
# Begin Source File

SOURCE=ui\Dlg_PermsUserChoice.h
# End Source File
# Begin Source File

SOURCE=ui\Dlg_PasswordGet.h
# End Source File
# Begin Source File

SOURCE=ui\Dlg_PermsDefine.h
# End Source File
# Begin Source File

SOURCE=ui\Dlg_Appartenance.h
# End Source File
# Begin Source File

SOURCE=ui\Dlg_IntervList.h
# End Source File




# Prop Default_Filter "moc"
# End Group
# End Target
# End Project

