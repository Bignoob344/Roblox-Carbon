#include "_hooks.h"
#include "imgui.h"
#include "imgui_impl_dx11.h"
#include "imgui_impl_win32.h"
#include "globals.h"

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

LRESULT APIENTRY dWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    if (!IsGUIInitialized)
        return CallWindowProc(WindowProc, hWnd, uMsg, wParam, lParam);

    ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);

    switch (uMsg) {
        case WM_SYSKEYDOWN:
        case WM_SYSKEYUP:
            CallWindowProc(WindowProc, hWnd, uMsg, wParam, lParam);
            break;

        case WM_KEYUP:
            if (wParam == VK_DELETE) {
                ShowMenu = !ShowMenu;
            }
        	break;

		default:
		    break;
    }

    ImGuiIO& io = ImGui::GetIO();
    if (io.WantCaptureMouse || io.WantCaptureKeyboard)
        return DefWindowProc(hWnd, uMsg, wParam, lParam);

    if (ShowMenu)
		return true;

	return CallWindowProc(WindowProc, hWnd, uMsg, wParam, lParam);
}
