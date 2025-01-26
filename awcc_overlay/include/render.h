#pragma once

#include <d3d9.h>
#include <Windows.h>

class Render
{
	private:
	
	public:
		bool CreateDevice(HWND windowHandle);
		void CreateSwapChain();
		void InitImGui();
};