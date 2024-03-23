#include "_hooks.h"
#include <windows.h>
#include "detours.h"
#include <iostream>
#include "oxorany.h"
#include "DirectX12.h"
#include "globals.h"
#include <iomanip>

bool HookFunction(PVOID* ppPointer, PVOID pDetour, const char* functionName) {
	if (const auto error = DetourAttach(ppPointer, pDetour); error != NO_ERROR) {
		std::cout << oxorany("Failed to hook ") << functionName << oxorany(", error ") << error << std::endl;
		return false;
	}
	std::cout << oxorany("Hooked ") << functionName << " [" << std::hex << std::setw(16) << *ppPointer << "] -> [" << std::hex << std::setw(16) << pDetour << "]" << std::endl;
	return true;
}

#define HOOKFUNC(n) if (!HookFunction(&(PVOID&)n, d ## n, #n)) return;

bool UnhookFunction(PVOID* ppPointer, PVOID pDetour, const char* functionName) {
	if (const auto error = DetourDetach(ppPointer, pDetour); error != NO_ERROR) {
		std::cout << oxorany("Failed to unhook ") << functionName << oxorany(", error ") << error << std::endl;
		return false;
	}
	std::cout << oxorany("Unhooked ") << functionName << std::endl;
	return true;
}

#define UNHOOKFUNC(n) if (!UnhookFunction(&(PVOID&)n, d ## n, #n)) return;

void DetourInitilization() {
	// initialize dx12
	DirectX12::Init();

	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());

	// get the address of the dx12 functions
	Present12 = (PRESENT_12_FUNCTION)MethodsTable[140];
	ExecuteCommandLists = (EXECUTE_COMMAND_LISTS_FUNCTION)MethodsTable[54];

	// hook dx12 functions
	HOOKFUNC(Present12);
	HOOKFUNC(ExecuteCommandLists);

	DetourTransactionCommit();
}

void DetourUninitilization()
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());

	//unhook here

	DetourTransactionCommit();
}