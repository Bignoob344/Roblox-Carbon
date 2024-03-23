#pragma once
#include <d3d12.h>
#pragma comment(lib, "d3d12.lib")
#include <dxgi1_4.h>
#pragma comment(lib, "dxgi.lib")

void DetourInitilization();
void DetourUninitilization();

typedef HRESULT(APIENTRY* PRESENT_12_FUNCTION)(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
static PRESENT_12_FUNCTION Present12 = nullptr;

typedef void(APIENTRY* EXECUTE_COMMAND_LISTS_FUNCTION)(ID3D12CommandQueue* queue, UINT NumCommandLists, ID3D12CommandList* ppCommandLists);
static EXECUTE_COMMAND_LISTS_FUNCTION ExecuteCommandLists = nullptr;

HRESULT dPresent12(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
void dExecuteCommandLists(ID3D12CommandQueue* queue, UINT NumCommandLists, ID3D12CommandList* ppCommandLists);
