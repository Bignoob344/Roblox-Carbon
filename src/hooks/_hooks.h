#pragma once
#include "app-functions.h"

void DetourInitilization();
void DetourUninitilization();

BOOL APIENTRY dSetSysCursorPos(int X, int Y);
HRESULT APIENTRY dPresent(IDXGISwapChain* __this, UINT SyncInterval, UINT Flags);
LRESULT APIENTRY dWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

void dPickupSample(__int64 a1, int a2, int amount, int sampleType);
bool dIsStratagemUnlocked(__int64 a1, int StratagemId);
bool dIsArmorUnlocked(int* armorObject);
char dIsEquipmentUnlocked(DWORD* a1, int equipmentId);
void dRoutineDeploymentTime(__int64* a1, float timeSteps);
__int64 dWeaponAmmoReduction(__int64 a1, unsigned int weaponId);
__int64 dStratagemReduction(__int64 a1, unsigned int a2, char a3, __int64 a4);
void dStaminaReduction(__int64 a1, int a2, float a3);
void dEnemyBasicDamage(__int64 target, __int64 a2, unsigned int a3, int damage, unsigned int typeMaybe);
