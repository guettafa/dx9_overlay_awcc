#pragma once 

#include <iostream>
#include <Windows.h>
#include <dwmapi.h>
#include <string_view>

class Overlay
{
	private:
		HWND mHandle;
		int  mDisplayDimensions[2]; // Width + Height

	public:
		bool GetWndHandle(std::string_view className, std::string_view windowName);
		bool GetDisplayDimensions();
		bool ShowWnd();
		bool ChangeWndStyle(UINT64 styles);
		bool ChangeWndPosition();
};