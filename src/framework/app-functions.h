#pragma once
#include <d3d11.h>
#pragma comment(lib, "d3d11.lib")

typedef BOOL(WINAPI* SET_CURSOR_POS_FUNCTION)(int X, int Y);
extern SET_CURSOR_POS_FUNCTION SetSysCursorPos;

typedef HRESULT(__fastcall* D3D_PRESENT_FUNCTION)(IDXGISwapChain* __this, UINT SyncInterval, UINT Flags);
extern D3D_PRESENT_FUNCTION Present;

typedef void(__fastcall* PICKUP_SAMPLE_FUNCTION)(__int64 a1, int a2, int a3, int a4);
extern PICKUP_SAMPLE_FUNCTION PickupSample;

typedef bool(__fastcall* IS_STRATAGEM_UNLOCKED_FUNCTION)(__int64 a1, int a2);
extern IS_STRATAGEM_UNLOCKED_FUNCTION IsStratagemUnlocked;

typedef bool(__fastcall* IS_ARMOR_UNLOCKED_FUNCTION)(int* a1);
extern IS_ARMOR_UNLOCKED_FUNCTION IsArmorUnlocked;

typedef char(__fastcall* IS_EQUIPMENT_UNLOCKED_FUNCTION)(DWORD* a1, int a2);
extern IS_EQUIPMENT_UNLOCKED_FUNCTION IsEquipmentUnlocked;

typedef void(__fastcall* ROUTINE_DEPLOYMENT_TIME_FUNCTION)(__int64* a1, float a2);
extern ROUTINE_DEPLOYMENT_TIME_FUNCTION RoutineDeploymentTime;

typedef __int64(__fastcall* WEAPON_AMMO_REDUCTION_FUNCTION)(__int64 a1, unsigned int a2);
extern WEAPON_AMMO_REDUCTION_FUNCTION WeaponAmmoReduction;

typedef __int64(__fastcall* STRATAGEM_REDUCTION_FUNCTION)(__int64 a1, unsigned int a2, char a3, __int64 a4);
extern STRATAGEM_REDUCTION_FUNCTION StratagemReduction;

typedef void(__fastcall* STAMINA_REDUCTION_FUNCTION)(__int64 a1, int a2, float a3);
extern STAMINA_REDUCTION_FUNCTION StaminaReduction;

typedef void(__fastcall* ENEMY_MELEE_DAMAGE_FUNCTION)(__int64 a1, __int64 a2, unsigned int a3, int a4, unsigned int a5);
extern ENEMY_MELEE_DAMAGE_FUNCTION EnemyBasicDamage;
