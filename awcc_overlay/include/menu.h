#pragma once

#include <imgui.h>

namespace Menu
{
	inline void DrawMenu()
	{
		if ((ImGui::IsWindowFocused() || !ImGui::IsWindowFocused(ImGuiFocusedFlags_AnyWindow)) && !ImGui::IsAnyItemActive())
			ImGui::SetKeyboardFocusHere(-1);

		ImGuiWindowFlags flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;

		ImGui::SetNextWindowSize(ImVec2(330, 400));

		ImGui::Begin("On AWCC Overlay", nullptr, flags);
			ImGui::Text("FPS: %.1f", ImGui::GetIO().Framerate);
		ImGui::End();
	}
}