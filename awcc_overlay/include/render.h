#pragma once

#include <d3d9.h>
#include <overlay.h>

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

			if (!CreateDevice()) return;
		}

		bool CreateDevice();
		bool InitD3D9();
		void InitImGui();
};