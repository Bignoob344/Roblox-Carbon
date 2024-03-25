#include "_hooks.h"
#include "globals.h"

void dPickupSample(__int64 a1, int a2, int amount, int sampleType) {
	PickupSample(a1, a2, 20, 1);
	PickupSample(a1, a2, 10, 2);
	PickupSample(a1, a2, 2, 3);
}

bool dIsStratagemUnlocked(__int64 a1, int StratagemId) {
	if (fStratagemUnlock)
		return true;

	return IsStratagemUnlocked(a1, StratagemId);
}

bool dIsArmorUnlocked(int* armorObject) {
	if (fArmorUnlock)
		return true;

	IsArmorUnlocked(armorObject);
}

char dIsEquipmentUnlocked(DWORD* a1, int equipmentId) {
	if (fEquipmentUnlock)
		return true;

	IsEquipmentUnlocked(a1, equipmentId);
}

void dRoutineDeploymentTime(__int64* a1, float timeSteps) {
	if (fRoutineDeployment)
		return RoutineDeploymentTime(a1, 100.f);
	
	RoutineDeploymentTime(a1, timeSteps);
}

__int64 dWeaponAmmoReduction(__int64 a1, unsigned int weaponId) {
	if (fWeaponAmmoReduction)
		return NULL;

	WeaponAmmoReduction(a1, weaponId);
}

__int64 dStratagemReduction(__int64 a1, unsigned int a2, char a3, __int64 a4) {
	if (fStratagemReduction)
		return NULL;

	StratagemReduction(a1, a2, a3, a4);
}

void dStaminaReduction(__int64 a1, int a2, float a3) {
	if (fStaminaReduction)
		return;

	StaminaReduction(a1, a2, a3);
}

void dEnemyBasicDamage(__int64 target, __int64 a2, unsigned int a3, int damage, unsigned int typeMaybe) {
	if (fEnemyBasicDamage)
		EnemyBasicDamage(target, a2, a3, 0, typeMaybe);

	EnemyBasicDamage(target, a2, a3, damage, typeMaybe);
}
