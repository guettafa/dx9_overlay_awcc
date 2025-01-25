#pragma once

#include <imgui.h>

namespace Menu
{
	inline void DrawMenu()
	{
		ImGui::Begin("On AWCC Overlay", nullptr, ImGuiWindowFlags_None);
			ImGui::Text("FPS: %.1f", ImGui::GetIO().Framerate);
		ImGui::End();
	}
}