#include "render.h"
#include "menu.h"

int main()
{
	Render awccOverlay(
		"HwndWrapper[AWCCOverlay;;b9650f5a-3293-4ae5-b2b3-26b99b4cbbb5]", // class name that correspond to disposable Handle from WPF ( AKA, a problem ) 
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