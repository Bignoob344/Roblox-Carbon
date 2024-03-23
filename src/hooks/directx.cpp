#include "_hooks.h"
#include <iostream>

ID3D12CommandQueue* commandQueue = nullptr;

HRESULT dPresent12(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
	std::cout << "Present12 called" << std::endl;

	if (!commandQueue)
		return Present12(pSwapChain, SyncInterval, Flags);

	return Present12(pSwapChain, SyncInterval, Flags);
}

void dExecuteCommandLists(ID3D12CommandQueue* queue, UINT NumCommandLists, ID3D12CommandList* ppCommandLists)
{
	if (!commandQueue)
		commandQueue = queue;

	ExecuteCommandLists(queue, NumCommandLists, ppCommandLists);
}
