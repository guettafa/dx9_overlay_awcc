#include "render.h"
#include "menu.h"

int main()
{
	Render awccOverlay(
		"HwndWrapper[AWCCOverlay;;a6ca78f7-8648-45d9-95cc-b5b75da0044d]", // class name that correspond to disposable Handle from WPF ( AKA, a problem ) 
		"AWCC Overlay",
		WS_EX_LAYERED | WS_EX_TOOLWINDOW | WS_EX_TOPMOST | WS_EX_TRANSPARENT
	);

	awccOverlay.Loop(
		[&]() 
		{
			Menu::DrawMenu();
		}
	);
	return 0;
}