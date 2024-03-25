#include "app-functions.h"

SET_CURSOR_POS_FUNCTION SetSysCursorPos = nullptr;
D3D_PRESENT_FUNCTION Present = nullptr;

PICKUP_SAMPLE_FUNCTION PickupSample = nullptr;
IS_STRATAGEM_UNLOCKED_FUNCTION IsStratagemUnlocked = nullptr;
IS_ARMOR_UNLOCKED_FUNCTION IsArmorUnlocked = nullptr;
IS_EQUIPMENT_UNLOCKED_FUNCTION IsEquipmentUnlocked = nullptr;
ROUTINE_DEPLOYMENT_TIME_FUNCTION RoutineDeploymentTime = nullptr;
WEAPON_AMMO_REDUCTION_FUNCTION WeaponAmmoReduction = nullptr;
STRATAGEM_REDUCTION_FUNCTION StratagemReduction = nullptr;
STAMINA_REDUCTION_FUNCTION StaminaReduction = nullptr;
ENEMY_MELEE_DAMAGE_FUNCTION EnemyBasicDamage = nullptr;
