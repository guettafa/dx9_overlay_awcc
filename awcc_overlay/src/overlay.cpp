#include "overlay.h"

#define ERROR_MSG(message)  std::cout << "ERROR - " << message << std::endl;

bool Overlay::GetWndHandle(std::string_view className, std::string_view windowName)
{
	this->m_handle = FindWindowA(className.data(), windowName.data());

	if (m_handle == NULL)
	{
		ERROR_MSG("Can't get window handle");
		return false;
	}
	return true;
}

bool Overlay::GetDisplayDimensions()
{
	this->m_displayDimensions[0] = GetSystemMetrics(SM_CXSCREEN); // Width
	this->m_displayDimensions[1] = GetSystemMetrics(SM_CYSCREEN); // Height

	if (!m_displayDimensions[0] || !m_displayDimensions[1])
	{
		ERROR_MSG("Can't get display width and height");
		return false;
	}
	return true;
}


bool Overlay::ShowWnd()
{

}

bool Overlay::ChangeWndOpacity()
{
}

bool Overlay::ChangeWndStyle()
{
}

bool Overlay::ChangeWndPosition()
{
}
