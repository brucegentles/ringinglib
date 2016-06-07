# Microsoft Developer Studio Project File - Name="gsiril" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=gsiril - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE
!MESSAGE NMAKE /f "gsiril.mak".
!MESSAGE
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE
!MESSAGE NMAKE /f "gsiril.mak" CFG="gsiril - Win32 Debug"
!MESSAGE
!MESSAGE Possible choices for configuration are:
!MESSAGE
!MESSAGE "gsiril - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "gsiril - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
BSC32=bscmake.exe
LINK32=link.exe

!IF  "$(CFG)" == "gsiril - Win32 Release"

# PROP BASE Use_Debug_Libraries 0
# PROP Use_Debug_Libraries 0
# PROP BASE Use_MFC 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release\gsiril"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release\gsiril"
# PROP Target_Dir ""
# PROP Ignore_Export_Lib 0

# ADD BASE CPP /nologo /W3 /GX /GR /O2 /YX /FD /D "WIN32" /D "NDEBUG" /D "_MBCS" /YX /FD /c /MD /D "_CONSOLE" /I "." /I "./apps/utils"
# ADD CPP /nologo /W3 /GX /GR /O2 /YX /FD /D "WIN32" /D "NDEBUG" /D "_MBCS" /c /MD /D "_CONSOLE" /I "." /I "./apps/utils"
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo 
# ADD BASE LINK32 /nologo kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /subsystem:console /machine:I386
# ADD LINK32 /nologo kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /subsystem:console /incremental:yes /machine:I386

!ELSEIF  "$(CFG)" == "gsiril - Win32 Debug"

# PROP BASE Use_Debug_Libraries 1
# PROP Use_Debug_Libraries 1
# PROP BASE Use_MFC 0
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug\gsiril"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug\gsiril"
# PROP Target_Dir ""
# PROP Ignore_Export_Lib 0

# ADD BASE CPP /nologo /W3 /Gm /GX /GR /Od /YX /FD /D "WIN32" /D "_DEBUG" /D "_MBCS" /MDd /D "_CONSOLE" /c /I "." /I "./apps/utils"
# ADD CPP /nologo /W3 /Gm /GX /GR /Od /YX /FD /D "WIN32" /D "_DEBUG" /D "_MBCS" /MDd /D "_CONSOLE" /c /I "." /I "./apps/utils"
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
# ADD BASE LINK32 /nologo kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF

# Begin Target

# Name "gsiril - Win32 Release"
# Name "gsiril - Win32 Debug"


# Begin Source File

SOURCE =.\apps\gsiril\main.cpp
# End Source File
# Begin Source File

SOURCE =.\apps\gsiril\console_stream.cpp
# End Source File
# Begin Source File

SOURCE =.\apps\gsiril\console_stream.h
# End Source File
# Begin Source File

SOURCE =.\apps\gsiril\execution_context.cpp
# End Source File
# Begin Source File

SOURCE =.\apps\gsiril\execution_context.h
# End Source File
# Begin Source File

SOURCE =.\apps\gsiril\expr_base.cpp
# End Source File
# Begin Source File

SOURCE =.\apps\gsiril\expr_base.h
# End Source File
# Begin Source File

SOURCE =.\apps\gsiril\proof_context.cpp
# End Source File
# Begin Source File

SOURCE =.\apps\gsiril\proof_context.h
# End Source File
# Begin Source File

SOURCE =.\apps\gsiril\symbol_table.cpp
# End Source File
# Begin Source File

SOURCE =.\apps\gsiril\symbol_table.h
# End Source File
# Begin Source File

SOURCE =.\apps\gsiril\expression.h
# End Source File
# Begin Source File

SOURCE =.\apps\gsiril\expression.cpp
# End Source File
# Begin Source File

SOURCE =.\apps\gsiril\statement.h
# End Source File
# Begin Source File

SOURCE =.\apps\gsiril\statement.cpp
# End Source File
# Begin Source File

SOURCE =.\apps\gsiril\parser.cpp
# End Source File
# Begin Source File

SOURCE =.\apps\gsiril\parser.h
# End Source File
# Begin Source File

SOURCE =.\apps\gsiril\util.cpp
# End Source File
# Begin Source File

SOURCE =.\apps\gsiril\util.h
# End Source File
# Begin Source File

SOURCE =.\apps\gsiril\prog_args.h
# End Source File
# End Target
# End Project
