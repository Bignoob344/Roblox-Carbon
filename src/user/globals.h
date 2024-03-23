#pragma once
#include <windows.h>
#include <stdint.h>
#include <assert.h>
#include <Psapi.h>
#include <stdio.h>
#include "oxorany.h"

typedef uint64_t uintx_t;

extern uintx_t* MethodsTable;
extern HWND WindowHwnd;
extern HMODULE moduleHandle;

void InitializeConsole();
void DestroyConsole();
