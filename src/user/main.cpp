#include "main.hpp"
#include "_hooks.h"
#include "oxorany.h"
#include "detours.h"
#include <iostream>
#include "SignatureScan.hpp"
#include "globals.h"

//typedef void(__fastcall* PICKUP_SAMPLE_FUNCTION)(__int64 a1, int a2, int a3, int a4);
//PICKUP_SAMPLE_FUNCTION PickupSample = nullptr;
//
//typedef bool(__fastcall* IS_STRATAGEM_UNLOCKED_FUNCTION)(__int64 a1, int a2);
//IS_STRATAGEM_UNLOCKED_FUNCTION IsStratagemUnlocked = nullptr;
//
//typedef bool(__fastcall* IS_ARMOR_UNLOCKED_FUNCTION)(int* a1);
//IS_ARMOR_UNLOCKED_FUNCTION IsArmorUnlocked = nullptr;
//
//typedef char(__fastcall* IS_EQUIPMENT_UNLOCKED_FUNCTION)(DWORD* a1, int a2);
//IS_EQUIPMENT_UNLOCKED_FUNCTION IsEquipmentUnlocked = nullptr;
//
//typedef void(__fastcall* ROUTINE_DEPLOYMENT_TIME_FUNCTION)(__int64* a1, float a2);
//ROUTINE_DEPLOYMENT_TIME_FUNCTION RoutineDeploymentTime = nullptr;
//
//typedef __int64(__fastcall* WEAPON_AMMO_REDUCTION_FUNCTION)(__int64 a1, unsigned int a2);
//WEAPON_AMMO_REDUCTION_FUNCTION WeaponAmmoReduction = nullptr;
//
//typedef __int64(__fastcall* STRATAGEM_REDUCTION_FUNCTION)(__int64 a1, unsigned int a2, char a3, __int64 a4);
//STRATAGEM_REDUCTION_FUNCTION StratagemReduction = nullptr;
//
//typedef void(__fastcall* STAMINA_REDUCTION_FUNCTION)(__int64 a1, int a2, float a3);
//STAMINA_REDUCTION_FUNCTION StaminaReduction = nullptr;
//
//typedef void(__fastcall* ENEMY_MELEE_DAMAGE_FUNCTION)(__int64 a1, __int64 a2, unsigned int a3, int a4, unsigned int a5);
//ENEMY_MELEE_DAMAGE_FUNCTION EnemyBasicDamage = nullptr;
//
//void __fastcall dPickupSample(__int64 a1, int a2, int amount, int sampleType) {
//	PickupSample(a1, a2, 20, 1);
//	PickupSample(a1, a2, 10, 2);
//	PickupSample(a1, a2,  2, 3);
//}
//
//bool __fastcall dIsStratagemUnlocked(__int64 a1, int StratagemId) {
//	return true;
//}
//
//bool __fastcall dIsArmorUnlocked(int* armorObject) {
//	return true;
//}
//
//char __fastcall dIsEquipmentUnlocked(DWORD* a1, int equipmentId) {
//	return true;
//}
//
//void __fastcall dRoutineDeploymentTime(__int64* a1, float timeSteps) {
//	RoutineDeploymentTime(a1, 100.f);
//}
//
//__int64 __fastcall dWeaponAmmoReduction(__int64 a1, unsigned int weaponId) {
//	return NULL;
//}
//
//__int64 dStratagemReduction(__int64 a1, unsigned int a2, char a3, __int64 a4) {
//	return NULL;
//}
//
//void dStaminaReduction(__int64 a1, int a2, float a3) {
//	return;
//}
//
//void dEnemyBasicDamage(__int64 target, __int64 a2, unsigned int a3, int damage, unsigned int typeMaybe) {
//	EnemyBasicDamage(target, a2, a3, 0, typeMaybe);
//}

void Run(LPVOID lpParam)
{
	// wait for game.dll to load
	do
	{
		moduleHandle = GetModuleHandle(oxorany("game.dll"));
		Sleep(1000);
	} while (!moduleHandle);
	Sleep(100);

	InitializeConsole();

	// grab the window handle
	WindowHwnd =  (HWND)FindWindow(0, "Renderer: [DirectX12], Input: [Raw input], 64 bits");

	// initialize the detours
	DetourInitilization();

	/*DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());

	PickupSample = SignatureScan<PICKUP_SAMPLE_FUNCTION>(oxorany("45 85 C9 0F 84 ? ? ? ? 48 89 6C 24 ? 41 56"), moduleHandle);
	IsStratagemUnlocked = SignatureScan<IS_STRATAGEM_UNLOCKED_FUNCTION>(oxorany("48 89 5C 24 ? 48 8B D9 85 D2 75 09"), moduleHandle);
	IsArmorUnlocked = SignatureScan<IS_ARMOR_UNLOCKED_FUNCTION>(oxorany("48 83 EC ?? 44 8B 49 ?? 45 33 C0"), moduleHandle);
	IsEquipmentUnlocked = SignatureScan<IS_EQUIPMENT_UNLOCKED_FUNCTION>(oxorany("E8 ? ? ? ? EB 12 8B 48 08"), moduleHandle).ResolveCall();
	RoutineDeploymentTime = SignatureScan<ROUTINE_DEPLOYMENT_TIME_FUNCTION>(oxorany("4C 8B DC 49 89 5B 18 55 56 57 41 54 41 55 41 56"), 0, moduleHandle);
	WeaponAmmoReduction = SignatureScan<WEAPON_AMMO_REDUCTION_FUNCTION>(oxorany("48 89 4C 24 ? 53 55 56 57 41 57 48 83 EC 40"), 0, moduleHandle);
	StratagemReduction = SignatureScan<STRATAGEM_REDUCTION_FUNCTION>(oxorany("48 8B C4 44 88 40 18 53 55 41 54 41 55"), 0, moduleHandle);
	StaminaReduction = SignatureScan<STAMINA_REDUCTION_FUNCTION>(oxorany("E8 ? ? ? ? 48 8B 44 24 ? 0F 28 C6"), 0, moduleHandle).ResolveCall();
	EnemyBasicDamage = SignatureScan<ENEMY_MELEE_DAMAGE_FUNCTION>(oxorany("44 89 4C 24 ? 48 89 54 24 ? 53 41 54"), moduleHandle);

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
	*/

	// wait for the game to close
	while(true)
	{
		Sleep(1000);
	}
}
