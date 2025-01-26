#pragma once

#include <overlay.h>

#include <d3d9.h>
#include <imgui.h>
#include <imgui_impl_dx9.h>
#include <imgui_impl_win32.h>

#include <functional>

class Render
{
	private:
		Overlay				  mOverlay		  = {};
		LPDIRECT3D9			  mD3d9			  = nullptr;
		LPDIRECT3DDEVICE9	  mDeviceD3d9	  = nullptr;
		D3DPRESENT_PARAMETERS mParametersD3d9 = {};

	public:
		Render(
			std::string_view className, 
			std::string_view windowName, 
			UINT64			 styles
		)
		{
			mOverlay = Overlay(className, windowName, styles);
			if (!InitRendering()) return;
		}

		bool CreateDevice();
		void CleanDevice();
		bool InitImGui();
		bool InitRendering();
		void Loop(const std::function<void()>& func);
};