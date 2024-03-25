#include "menu.h"
#include "imgui.h"
#include "globals.h"

void Menu::Render() {
	ImGui::Begin("Helldivers2Menu", &ShowMenu, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar);
	ImGui::SetWindowSize(ImVec2(300, 300));

	ImGui::Checkbox("Modify Sample Pickup Amount", &fManipulateSamplePickup);
	ImGui::DragInt("##sampleamount", &SampleAmount, 1.0f, 1, 50);

	ImGui::Separator();

	ImGui::Checkbox("Unlock All Stratagems", &fStratagemUnlock);
	ImGui::Checkbox("Unlock All Armor", &fArmorUnlock);
	ImGui::Checkbox("Unlock All Equipments/Warbonds", &fEquipmentUnlock);

	ImGui::Separator();

	ImGui::Checkbox("No Stratagem/Shuttle Timer", &fRoutineDeployment);
	ImGui::Checkbox("Unlimited Ammo", &fWeaponAmmoReduction);
	ImGui::Checkbox("Unlimited Stratagems", &fStratagemReduction);
	ImGui::Checkbox("Unlimited Stamina", &fStaminaReduction);
	ImGui::Checkbox("GodMode", &fEnemyBasicDamage);

	ImGui::End();
}
