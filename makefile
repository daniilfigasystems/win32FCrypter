all:
	windres src/res.rc -o src/resource.o -I src/include --target=pe-i386
	g++ -I src/include -o FCrypterWIN32.exe src/main.cpp src/getversion.cpp src/resource.o -D_WIN32_WINNT=0x0500 -m32 -lcomdlg32 -luxtheme