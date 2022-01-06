del *.dll *.exp *.lib *.obj

call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x86
:call "C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\Auxiliary\Build\vcvarsall.bat" x86

cl.exe /MT /EHsc /Ox /Ot /Oi /Ob2 /DC86CTL /c /Ilua /Ilua/include X68Sound.cpp lua/X68Sound_lua.cpp
if %errorlevel% neq 0 (
	goto :fail
)
rc.exe x68sound.rc
if %errorlevel% neq 0 (
	goto :fail
)

link.exe /dll /def:x68sound.def x68sound.obj x68sound.res winmm.lib user32.lib X68Sound_lua.obj lua/liblua54.a 
if %errorlevel% neq 0 (
	goto :fail
)

exit /b

:fail
pause
