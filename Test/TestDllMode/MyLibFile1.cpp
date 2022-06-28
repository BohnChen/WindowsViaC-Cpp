/***************************************************************************
Module: MyLibFile1.cpp
****************************************************************************/


// Include the standard Windows and C-Runtime header files here.
#include <windows.h>


// This DLL source code file exports functinos and variables.
#define MYLIBAPI extern "C" __declspec(dllexport)

// Include the exported data structures, symbols, functions, and variables.
#include "MyLib.h"

/////////////////////////////////////////////////////////////////////////////

// Plcae the code for this DLL source code file here.
MYLIBAPI int g_nResult;

MYLIBAPI int Add(int nLeft, int nRight)
{
	g_nResult = nLeft + nRight;
	//int _nRet = nLeft + nRight;
	//return _nRet;
	return(g_nResult);
}