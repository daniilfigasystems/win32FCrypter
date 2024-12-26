all:
	rc  /fo resource.o /i src\include src/res.rc
	cl /I src\include src\getversion.cpp src\main.cpp src\resource.o /FeFCrypterWIN32.exe gdi32.lib wsock32.lib kernel32.lib user32.lib comdlg32.lib uxtheme.lib 
	del *.obj
	del *.o