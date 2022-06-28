// TestGitProj.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//extern "C" const IMAGE_DOS_HEADER __ImageBase;
#include <iostream>
#include <windows.h>
#include <WinError.h>
#include <stdio.h>
#include <wchar.h>
//#include <StdIo.h>
using namespace std;

//int _tmain(int argc, TCHAR* argv[], TCHAR* env[]);

//void DumpModule()
//{
//	HMODULE  hModule = GetModuleHandle(NULL);
//	_tprintf(TEXT("with __ImageBase  = 0x%x\r\n"), (HINSTANCE)&__ImageBase);
//}


//Int WINAPI _tWinMain (HINSTANCE hInstanceExe, HINSTANCE, PTSTR pszCmdLine, int nCmdShow)
int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	cout << " Main entrance here. " << endl;
	return 0;
}

