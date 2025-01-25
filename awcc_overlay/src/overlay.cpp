#include "overlay.h"

#define ERROR_MSG(message) std::cout << "ERROR - " << message << std::endl;

bool Overlay::GetWndHandle(std::string_view className, std::string_view windowName)
{
	mHandle = FindWindowA(className.data(), windowName.data());

	if (mHandle == NULL)
	{
		ERROR_MSG("Can't get window handle");
		return false;
	}
	std::printf("Handle : 0x%11x \n", mHandle);

	return true;
}

bool Overlay::GetDisplayDimensions()
{
	int displayW = GetSystemMetrics(SM_CXSCREEN); // Width
	int displayH = GetSystemMetrics(SM_CYSCREEN); // Height

	if (!displayW || !displayH)
	{
		ERROR_MSG("Can't get display width and height");
		return false;
	}

	mDisplayDimension[0] = displayW;
	mDisplayDimension[1] = displayH;

	std::printf("Width : %i - Height : %i\n", mDisplayDimension[0], mDisplayDimension[1]);

	return true;
}

bool Overlay::ShowWnd()
{
	ShowWindow(mHandle, SW_SHOW);
	
	MARGINS margins{ -1 }; // -1 for Sheet of glass effect AKA no borders
	HRESULT hr = S_OK;

	hr = DwmExtendFrameIntoClientArea(mHandle, &margins);
	if (FAILED(hr))
	{
		ERROR_MSG("Can't extend frame into client area");
		return false;
	}
	return true;
}

bool Overlay::ChangeWndStyle(UINT64 styles)
{
	// Change Window Extended Styles
	if (!SetWindowLongA(mHandle, GWL_EXSTYLE, styles)) // 0 if failed
	{
		ERROR_MSG("Can't set styles to window");
		return false;
	}

	// Change Window Opacity AKA Alpha value
	if (!SetLayeredWindowAttributes(mHandle, 0, 255, LWA_ALPHA))
	{
		ERROR_MSG("Can't change Window Opacity");
		return false;
	}
	std::printf("Window Styles has been changed ! \n");

	return true;
}

bool Overlay::ChangeWndPosition()
{
	if (!SetWindowPos(mHandle, NULL, 0, 0, mDisplayDimension[0], mDisplayDimension[1], SWP_NOREDRAW))
	{
		ERROR_MSG("Can't change Scale and Position");
		return false;
	}
	std::printf("Window Position has been changed ! \n");

	return true;
}
