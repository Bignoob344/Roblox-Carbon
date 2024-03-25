#pragma once
#include <windows.h>
#include <stdint.h>
#include <assert.h>
#include <Psapi.h>
#include <stdio.h>
#include "oxorany.h"

extern uint64_t* MethodsTable;
extern HWND WindowHwnd;
extern WNDPROC WindowProc;
extern HMODULE ModuleHandle;

extern bool IsGUIInitialized;
extern bool ShowMenu;

extern bool fManipulateSamplePickup;
extern bool fStratagemUnlock;
extern bool fArmorUnlock;
extern bool fEquipmentUnlock;
extern bool fRoutineDeployment;
extern bool fWeaponAmmoReduction;
extern bool fStratagemReduction;
extern bool fStaminaReduction;
extern bool fEnemyBasicDamage;

void InitializeConsole();
void DestroyConsole();
