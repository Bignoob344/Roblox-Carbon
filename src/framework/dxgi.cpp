#include "dxgi.h"
#include "main.hpp"
#include <filesystem>
#include "oxorany.h"
#include <iostream>

HMODULE dxgi_dll;

#define WRAPPER_FUNC(name) o##name = GetProcAddress(dxgi_dll, ###name)

#pragma warning (disable: 4081)
#define STRINGIFY(name) #name
#define EXPORT_FUNCTION comment(linker, oxorany("/EXPORT:" __FUNCTION__ "=" __FUNCDNAME__))
#define WRAPPER_GENFUNC(name) \
    FARPROC o##name; \
    __declspec(dllexport) void WINAPI _##name() \
    { \
        __pragma(STRINGIFY(EXPORT_FUNCTION)); \
        o##name(); \
    }

WRAPPER_GENFUNC(ApplyCompatResolutionQuirking);
WRAPPER_GENFUNC(CompatString);
WRAPPER_GENFUNC(CompatValue);
WRAPPER_GENFUNC(CreateDXGIFactory);
WRAPPER_GENFUNC(CreateDXGIFactory1);
WRAPPER_GENFUNC(CreateDXGIFactory2);
WRAPPER_GENFUNC(DXGID3D10CreateDevice);
WRAPPER_GENFUNC(DXGID3D10CreateLayeredDevice);
WRAPPER_GENFUNC(DXGID3D10GetLayeredDeviceSize);
WRAPPER_GENFUNC(DXGID3D10RegisterLayers);
WRAPPER_GENFUNC(DXGIDeclareAdapterRemovalSupport);
WRAPPER_GENFUNC(DXGIDisableVBlankVirtualization);
WRAPPER_GENFUNC(DXGIDumpJournal);
WRAPPER_GENFUNC(DXGIGetDebugInterface1);
WRAPPER_GENFUNC(DXGIReportAdapterConfiguration);
WRAPPER_GENFUNC(PIXBeginCapture);
WRAPPER_GENFUNC(PIXEndCapture);
WRAPPER_GENFUNC(PIXGetCaptureState);
WRAPPER_GENFUNC(SetAppCompatStringPointer);
WRAPPER_GENFUNC(UpdateHMDEmulationStatus);

void load_dxgi() {
	char systemPath[MAX_PATH];
	GetSystemDirectoryA(systemPath, MAX_PATH);
	strcat_s(systemPath, oxorany("\\dxgi.dll"));
	dxgi_dll = LoadLibraryA(systemPath);	

	if (!dxgi_dll) return;
	
	WRAPPER_FUNC(ApplyCompatResolutionQuirking);
	WRAPPER_FUNC(CompatString);
	WRAPPER_FUNC(CompatValue);
	WRAPPER_FUNC(CreateDXGIFactory);
	WRAPPER_FUNC(CreateDXGIFactory1);
	WRAPPER_FUNC(CreateDXGIFactory2);
	WRAPPER_FUNC(DXGID3D10CreateDevice);
	WRAPPER_FUNC(DXGID3D10CreateLayeredDevice);
	WRAPPER_FUNC(DXGID3D10GetLayeredDeviceSize);
	WRAPPER_FUNC(DXGID3D10RegisterLayers);
	WRAPPER_FUNC(DXGIDeclareAdapterRemovalSupport);
	WRAPPER_FUNC(DXGIDisableVBlankVirtualization);
	WRAPPER_FUNC(DXGIDumpJournal);
	WRAPPER_FUNC(DXGIGetDebugInterface1);
	WRAPPER_FUNC(DXGIReportAdapterConfiguration);
	WRAPPER_FUNC(PIXBeginCapture);
	WRAPPER_FUNC(PIXEndCapture);
	WRAPPER_FUNC(PIXGetCaptureState);
	WRAPPER_FUNC(SetAppCompatStringPointer);
	WRAPPER_FUNC(UpdateHMDEmulationStatus);
}

DWORD WINAPI Load(LPVOID lpParam) {
	load_dxgi();
	if (!dxgi_dll) {
		MessageBoxEx(0, oxorany(L"Failed to load dxgi.dll"), oxorany(L"Error"), MB_ICONERROR, 0);
		return 0;
	}
	CloseHandle(dxgi_dll);

	Init();

	return 0;
}
