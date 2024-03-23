#include <globals.h>

uintx_t* MethodsTable = nullptr;
HWND WindowHwnd = nullptr;
HMODULE moduleHandle = nullptr;

void InitializeConsole() {
	FILE* pFile = nullptr;
	AllocConsole();
	freopen_s(&pFile, oxorany("CONOUT$"), oxorany("w"), stdout);
}

void DestroyConsole()
{
	DestroyWindow(GetConsoleWindow());
	FreeConsole();
}
