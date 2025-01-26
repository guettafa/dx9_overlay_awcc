#pragma once

#include <d3d9.h>
#include <Windows.h>

class Render
{
	private:
		LPDIRECT3D9			  mD3d9			= nullptr;
		LPDIRECT3DDEVICE9	  mDeviceD3d9	= nullptr;
		D3DPRESENT_PARAMETERS mParametersD3d9;

	public:
		bool CreateDevice(HWND windowHandle);
		void CreateSwapChain();
		bool InitD3D9;
		void InitImGui();
};