#pragma once
#include <d3d12.h>
#pragma comment(lib, "d3d12.lib")
#include <dxgi1_4.h>
#pragma comment(lib, "dxgi.lib")
#include "app-functions.h"

void DetourInitilization();
void DetourUninitilization();

HRESULT dPresent12(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
void dExecuteCommandLists(ID3D12CommandQueue* queue, UINT NumCommandLists, ID3D12CommandList* ppCommandLists);
