#include "_hooks.h"
#include <windows.h>
#include "detours.h"
#include <iostream>
#include "oxorany.h"
#include "globals.h"
#include <iomanip>
#include "SignatureScan.hpp"

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
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());

	SetSysCursorPos = (SET_CURSOR_POS_FUNCTION)GetProcAddress(GetModuleHandle(oxorany("user32.dll")), oxorany("SetCursorPos"));
	Present = SignatureScan<D3D_PRESENT_FUNCTION>(oxorany("48 89 6C 24 ? 48 89 74 24 ? 41 56 48 83 EC 20 41 8B E8"), GetModuleHandle(oxorany("gameoverlayrenderer64.dll")));
	PickupSample = SignatureScan<PICKUP_SAMPLE_FUNCTION>(oxorany("45 85 C9 0F 84 ? ? ? ? 48 89 6C 24 ? 41 56"), ModuleHandle);
	IsStratagemUnlocked = SignatureScan<IS_STRATAGEM_UNLOCKED_FUNCTION>(oxorany("48 89 5C 24 ? 48 8B D9 85 D2 75 09"), ModuleHandle);
	IsArmorUnlocked = SignatureScan<IS_ARMOR_UNLOCKED_FUNCTION>(oxorany("48 83 EC ?? 44 8B 49 ?? 45 33 C0"), ModuleHandle);
	IsEquipmentUnlocked = SignatureScan<IS_EQUIPMENT_UNLOCKED_FUNCTION>(oxorany("E8 ? ? ? ? EB 12 8B 48 08"), ModuleHandle).ResolveCall();
	RoutineDeploymentTime = SignatureScan<ROUTINE_DEPLOYMENT_TIME_FUNCTION>(oxorany("4C 8B DC 49 89 5B 18 55 56 57 41 54 41 55 41 56"), 0, ModuleHandle);
	WeaponAmmoReduction = SignatureScan<WEAPON_AMMO_REDUCTION_FUNCTION>(oxorany("48 89 4C 24 ? 53 55 56 57 41 57 48 83 EC 40"), 0, ModuleHandle);
	StratagemReduction = SignatureScan<STRATAGEM_REDUCTION_FUNCTION>(oxorany("48 8B C4 44 88 40 18 53 55 41 54 41 55"), 0, ModuleHandle);
	StaminaReduction = SignatureScan<STAMINA_REDUCTION_FUNCTION>(oxorany("E8 ? ? ? ? 48 8B 44 24 ? 0F 28 C6"), 0, ModuleHandle).ResolveCall();
	EnemyBasicDamage = SignatureScan<ENEMY_MELEE_DAMAGE_FUNCTION>(oxorany("44 89 4C 24 ? 48 89 54 24 ? 53 41 54"), ModuleHandle);

	HOOKFUNC(SetSysCursorPos);
	HOOKFUNC(Present);
	HOOKFUNC(PickupSample);
	HOOKFUNC(IsStratagemUnlocked);
	HOOKFUNC(IsArmorUnlocked);
	HOOKFUNC(IsEquipmentUnlocked);
	HOOKFUNC(RoutineDeploymentTime);
	HOOKFUNC(WeaponAmmoReduction);
	HOOKFUNC(StratagemReduction);
	HOOKFUNC(StaminaReduction);
	HOOKFUNC(EnemyBasicDamage);

	DetourTransactionCommit();
}

void DetourUninitilization()
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());

	UNHOOKFUNC(SetSysCursorPos);
	UNHOOKFUNC(Present);
	UNHOOKFUNC(PickupSample);
	UNHOOKFUNC(IsStratagemUnlocked);
	UNHOOKFUNC(IsArmorUnlocked);
	UNHOOKFUNC(IsEquipmentUnlocked);
	UNHOOKFUNC(RoutineDeploymentTime);
	UNHOOKFUNC(WeaponAmmoReduction);
	UNHOOKFUNC(StratagemReduction);
	UNHOOKFUNC(StaminaReduction);
	UNHOOKFUNC(EnemyBasicDamage);

	DetourTransactionCommit();
}
