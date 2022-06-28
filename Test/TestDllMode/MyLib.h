#pragma once
/*******************************************************************************
Module : MyLib.h 
*******************************************************************************/

#ifdef MYLIBAPI

// MYLIBAPI  should be defined in all of the DLL's source
// code modules before this header file is included.

// All functions/variables are being exported.
#else

// This header file is inclueded by an EXE source code module.
// Indicate that all functions/variables are being imported.
#define MYLIBAPI  extern "C" __declspec(dllexport)

#endif

/////////////////////////////////////////////////////////////////////////////////

// Define any data structures and symbols here.

/////////////////////////////////////////////////////////////////////////////////

// Define exported variables here. (NOTE: Avoid exporteing variables.)
MYLIBAPI int g_nResult;

/////////////////////////////////////////////////////////////////////////////////

// Define exported function prototypes here.
MYLIBAPI int Add(int nLeft, int nRight);

/////////////////////////////// End of File /////////////////////////////////////