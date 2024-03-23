#include "_hooks.h"
#include <iostream>
#include <iomanip>

ID3D12CommandQueue* commandQueue = nullptr;

HRESULT dPresent12(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
	std::cout << "Present12" << std::endl;
	if (!commandQueue)
		return Present12(pSwapChain, SyncInterval, Flags);

	return Present12(pSwapChain, SyncInterval, Flags);
}

void dExecuteCommandLists(ID3D12CommandQueue* queue, UINT NumCommandLists, ID3D12CommandList* ppCommandLists)
{
	if (!commandQueue) {
		commandQueue = queue;
		std::cout << "commandQueue initialized [" << std::hex << std::setw(16) << queue << "]" << std::endl;
	}
		
	
	ExecuteCommandLists(queue, NumCommandLists, ppCommandLists);
}
