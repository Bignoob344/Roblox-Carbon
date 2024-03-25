#include "_hooks.h"
#include <iostream>
#include <iomanip>
#include "oxorany.h"
#include "imgui.h"
#include "imgui_impl_dx11.h"
#include "imgui_impl_win32.h"
#include "globals.h"
#include <vector>
#include "menu.h"

ID3D11DeviceContext* pContext = nullptr;
ID3D11RenderTargetView* pRenderTargetView = nullptr;

HRESULT dPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags) {
    if (!IsGUIInitialized)
    {
        DXGI_SWAP_CHAIN_DESC desc;
        pSwapChain->GetDesc(&desc);

        ID3D11Device* pDevice = nullptr;
		if (FAILED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&pDevice)
			|| !pDevice))
			return Present(pSwapChain, SyncInterval, Flags);

        pDevice->GetImmediateContext(&pContext);

		if (!pContext)
			return Present(pSwapChain, SyncInterval, Flags);

        ID3D11Texture2D* pBackBuffer = nullptr;
        if (FAILED(pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer))
            || !pBackBuffer)
            return Present(pSwapChain, SyncInterval, Flags);

        if (FAILED(pDevice->CreateRenderTargetView(pBackBuffer, NULL, &pRenderTargetView)
			|| !pRenderTargetView))
			return Present(pSwapChain, SyncInterval, Flags);

		WindowProc = (WNDPROC)::SetWindowLongPtr((HWND)desc.OutputWindow, GWLP_WNDPROC, (LONG_PTR)dWndProc);

        ImGui::CreateContext();
        ImGui::GetIO().ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
        ImGui_ImplWin32_Init(desc.OutputWindow);
        ImGui_ImplDX11_Init(pDevice, pContext);

        IsGUIInitialized = true;
    }

    ImGui::GetIO().MouseDrawCursor = ShowMenu;

    ImGui_ImplDX11_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();

    if (ShowMenu)
        Menu::Render();

    ImGui::EndFrame();
    ImGui::Render();

    pContext->OMSetRenderTargets(1, &pRenderTargetView, NULL);
    ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

    return Present(pSwapChain, SyncInterval, Flags);
}
