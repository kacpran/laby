// JAApp.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <windows.h>
#include <iostream>
extern "C" int _stdcall FindChar(void);
int _tmain(int argc, _TCHAR* argv[])
{
	bool z;
	z = FindChar(); // wywo³anie procedury asemblerowej z biblioteki
	std::cout << z << std::endl;
	return 0;
}