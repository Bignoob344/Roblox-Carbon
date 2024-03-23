#pragma once
#include <d3d12.h>
#pragma comment(lib, "d3d12.lib")
#include <dxgi1_4.h>
#pragma comment(lib, "dxgi.lib")

typedef HRESULT(__fastcall* PRESENT_12_FUNCTION)(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
typedef void(*EXECUTE_COMMAND_LISTS_FUNCTION)(ID3D12CommandQueue* queue, UINT NumCommandLists, ID3D12CommandList* ppCommandLists);

extern PRESENT_12_FUNCTION Present12;
extern EXECUTE_COMMAND_LISTS_FUNCTION ExecuteCommandLists;