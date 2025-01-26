#pragma once 

#include <iostream>
#include <Windows.h>
#include <dwmapi.h>
#include <string_view>

#define LOG(message) std::cout << "INFO - " << message << std::endl;

class Overlay
{
	public:
		HWND	mHandle;
		UINT32  mDisplayDimension[2]; // Width and Height

		Overlay() {};
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