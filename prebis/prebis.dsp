# Microsoft Developer Studio Project File - Name="prebis" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) External Target" 0x0106

CFG=prebis - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "prebis.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "prebis.mak" CFG="prebis - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "prebis - Win32 Release" (based on "Win32 (x86) External Target")
!MESSAGE "prebis - Win32 Debug" (based on "Win32 (x86) External Target")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""

!IF  "$(CFG)" == "prebis - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Cmd_Line "NMAKE /f prebis.mak"
# PROP BASE Rebuild_Opt "/a"
# PROP BASE Target_File "prebis.exe"
# PROP BASE Bsc_Name "prebis.bsc"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Cmd_Line "nmake /f "nt86.mak""
# PROP Rebuild_Opt "/a"
# PROP Target_File "out\prebis.exe"
# PROP Bsc_Name ""
# PROP Target_Dir ""

!ELSEIF  "$(CFG)" == "prebis - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Cmd_Line "NMAKE /f prebis.mak"
# PROP BASE Rebuild_Opt "/a"
# PROP BASE Target_File "prebis.exe"
# PROP BASE Bsc_Name "prebis.bsc"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Cmd_Line "nmake /f "nt86.mak" debug=1"
# PROP Rebuild_Opt "/a"
# PROP Target_File "out\prebis.exe"
# PROP Bsc_Name "out\prebis.bsc"
# PROP Target_Dir ""

!ENDIF 

# Begin Target

# Name "prebis - Win32 Release"
# Name "prebis - Win32 Debug"

!IF  "$(CFG)" == "prebis - Win32 Release"

!ELSEIF  "$(CFG)" == "prebis - Win32 Debug"

!ENDIF 

# Begin Group "main"

# PROP Default_Filter ""
# Begin Group "generated"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\main\lex.yy.c
# End Source File
# Begin Source File

SOURCE=.\main\pre.output
# End Source File
# Begin Source File

SOURCE=.\main\pre.tab.c
# End Source File
# Begin Source File

SOURCE=.\main\pre.tab.h
# End Source File
# Begin Source File

SOURCE=.\main\pre.tab.inc
# End Source File
# Begin Source File

SOURCE=.\main\pre.y
# End Source File
# Begin Source File

SOURCE=.\main\pre1.act
# End Source File
# Begin Source File

SOURCE=.\main\pre1.tab.c
# End Source File
# Begin Source File

SOURCE=.\main\pre1.y
# End Source File
# End Group
# Begin Source File

SOURCE=.\main\bison.simple.c
# End Source File
# Begin Source File

SOURCE=.\main\gen.c
# End Source File
# Begin Source File

SOURCE=.\main\idtab.c
# End Source File
# Begin Source File

SOURCE=.\main\idtab.h
# End Source File
# Begin Source File

SOURCE=.\main\pre.yp
# End Source File
# Begin Source File

SOURCE=.\main\prebis.c
# End Source File
# Begin Source File

SOURCE=.\main\prebis.h
# End Source File
# Begin Source File

SOURCE=.\main\prebis_1.inc
# End Source File
# Begin Source File

SOURCE=.\main\scan.l
# End Source File
# End Group
# Begin Source File

SOURCE=.\nt86.mak
# End Source File
# Begin Source File

SOURCE=.\precomp.h
# End Source File
# Begin Source File

SOURCE=.\scratch.txt
# End Source File
# End Target
# End Project
