# Microsoft Developer Studio Project File - Name="test" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=test - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE
!MESSAGE NMAKE /f "test.mak".
!MESSAGE
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE
!MESSAGE NMAKE /f "test.mak" CFG="test - Win32 Debug"
!MESSAGE
!MESSAGE Possible choices for configuration are:
!MESSAGE
!MESSAGE "test - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "test - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
BSC32=bscmake.exe
LINK32=link.exe

!IF  "$(CFG)" == "test - Win32 Release"

# PROP BASE Use_Debug_Libraries 0
# PROP Use_Debug_Libraries 0
# PROP BASE Use_MFC 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release\test"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release\test"
# PROP Target_Dir ""
# PROP Ignore_Export_Lib 0

# ADD BASE CPP /nologo /W3 /GX /GR /O2 /YX /FD /D "WIN32" /D "NDEBUG" /D "_MBCS" /YX /FD /c /MD /D "_CONSOLE" /I "."
# ADD CPP /nologo /W3 /GX /GR /O2 /YX /FD /D "WIN32" /D "NDEBUG" /D "_MBCS" /c /MD /D "_CONSOLE" /I "."
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo 
# ADD BASE LINK32 /nologo kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /subsystem:console /machine:I386
# ADD LINK32 /nologo kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /subsystem:console /incremental:yes /machine:I386

!ELSEIF  "$(CFG)" == "test - Win32 Debug"

# PROP BASE Use_Debug_Libraries 1
# PROP Use_Debug_Libraries 1
# PROP BASE Use_MFC 0
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug\test"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug\test"
# PROP Target_Dir ""
# PROP Ignore_Export_Lib 0

# ADD BASE CPP /nologo /W3 /Gm /GX /GR /Od /YX /FD /D "WIN32" /D "_DEBUG" /D "_MBCS" /MDd /D "_CONSOLE" /c /I "."
# ADD CPP /nologo /W3 /Gm /GX /GR /Od /YX /FD /D "WIN32" /D "_DEBUG" /D "_MBCS" /MDd /D "_CONSOLE" /c /I "."
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
# ADD BASE LINK32 /nologo kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF

# Begin Target

# Name "test - Win32 Release"
# Name "test - Win32 Debug"


# Begin Source File

SOURCE =.\tests\test-main.cpp
# End Source File
# Begin Source File

SOURCE =.\tests\test-base.cpp
# End Source File
# Begin Source File

SOURCE =.\tests\test-base.h
# End Source File
# Begin Source File

SOURCE =.\tests\change-test.cpp
# End Source File
# Begin Source File

SOURCE =.\tests\row-test.cpp
# End Source File
# Begin Source File

SOURCE =.\tests\method-test.cpp
# End Source File
# Begin Source File

SOURCE =.\tests\music-test.cpp
# End Source File
# End Target
# End Project
