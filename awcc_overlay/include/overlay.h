#pragma once 

#include <Windows.h>
#include <iostream>
#include <string_view>

class Overlay
{
	private:
		HWND m_handle;
		INT  m_displayDimensions[2]; // Width + Height

	public:
		bool GetWndHandle(std::string_view className, std::string_view windowName);
		bool GetDisplayDimensions();
		bool ShowWnd();
		bool ChangeWndOpacity();
		bool ChangeWndStyle();
		bool ChangeWndPosition();
};