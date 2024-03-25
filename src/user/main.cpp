#include "main.hpp"
#include "_hooks.h"
#include "oxorany.h"
#include "detours.h"
#include <iostream>
#include "SignatureScan.hpp"
#include "globals.h"

void Run(LPVOID lpParam)
{
	do
	{
		ModuleHandle = GetModuleHandle(oxorany("game.dll"));
		Sleep(1000);
	} while (!ModuleHandle);
	Sleep(100);

	InitializeConsole();
	WindowHwnd = GetForegroundWindow();
	DetourInitilization();

	while(true)
	{
		Sleep(1000);
	}
}
