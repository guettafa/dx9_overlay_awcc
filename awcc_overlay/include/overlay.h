#pragma once 

#include <iostream>
#include <Windows.h>
#include <dwmapi.h>
#include <string_view>

class Overlay
{
	private:
		HWND mHandle;
		UINT32  mDisplayDimension[2]; // Width & Height

	public:
		Overlay(
			std::string_view className, 
			std::string_view windowName,
			UINT64 styles
		)
		{
			if (!GetWndHandle(className, windowName)) return;
			if (!GetDisplayDimensions())			  return;
			if (!ShowWnd())							  return;
			if (!ChangeWndStyle(styles))			  return;
			if (!ChangeWndPosition())				  return;
		}

		bool GetWndHandle(std::string_view className, std::string_view windowName);
		bool GetDisplayDimensions();
		bool ShowWnd();
		bool ChangeWndStyle(UINT64 styles);
		bool ChangeWndPosition();
};