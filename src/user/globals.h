#pragma once
#include <windows.h>
#include <stdint.h>
#include <assert.h>
#include <Psapi.h>
#include <stdio.h>
#include "oxorany.h"

typedef uint64_t uintx_t;
static uintx_t* MethodsTable = NULL;

static HWND WindowHwnd = nullptr;
static HMODULE moduleHandle = nullptr;

static void InitializeConsole() {
	FILE* pFile = nullptr;
	AllocConsole();
	freopen_s(&pFile, oxorany("CONOUT$"), oxorany("w"), stdout);
}

static void DestroyConsole()
{
	DestroyWindow(GetConsoleWindow());
	FreeConsole();
}
