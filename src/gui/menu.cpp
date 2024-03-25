#include "menu.h"
#include "imgui.h"
#include "globals.h"

void Menu::Render() {
	ImGui::Begin("HellDivers2Menu", &ShowMenu, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar);
	ImGui::SetWindowSize(ImVec2(300, 300));

	ImGui::Checkbox("Manipulate Sample Pickup", &fManipulateSamplePickup);
	ImGui::Checkbox("Stratagem Unlock", &fStratagemUnlock);
	ImGui::Checkbox("Armor Unlock", &fArmorUnlock);
	ImGui::Checkbox("Equipment Unlock", &fEquipmentUnlock);
	ImGui::Checkbox("Routine Deployment", &fRoutineDeployment);
	ImGui::Checkbox("Weapon Ammo Reduction", &fWeaponAmmoReduction);
	ImGui::Checkbox("Stratagem Reduction", &fStratagemReduction);
	ImGui::Checkbox("Stamina Reduction", &fStaminaReduction);
	ImGui::Checkbox("Enemy Basic Damage", &fEnemyBasicDamage);

	ImGui::End();
}
