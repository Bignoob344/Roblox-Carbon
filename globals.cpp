#include <globals.h>

HWND WindowHwnd = nullptr;
WNDPROC WindowProc = nullptr;
HMODULE ModuleHandle = nullptr;

bool IsGUIInitialized = false;
bool ShowMenu = false;

bool fManipulateSamplePickup = false;
bool fStratagemUnlock = false;
bool fArmorUnlock = false;
bool fEquipmentUnlock = false;
bool fRoutineDeployment = false;
bool fWeaponAmmoReduction = false;
bool fStratagemReduction = false;
bool fStaminaReduction = false;
bool fEnemyBasicDamage = false;

void InitializeConsole() {
	FILE* pFile = nullptr;
	AllocConsole();
	freopen_s(&pFile, oxorany("CONOUT$"), oxorany("w"), stdout);
}

void DestroyConsole()
{
	DestroyWindow(GetConsoleWindow());
	FreeConsole();
}
