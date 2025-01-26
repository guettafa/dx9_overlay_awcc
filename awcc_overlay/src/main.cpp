#include "render.h"
#include "menu.h"

int main()
{
	Render awccOverlay(
		"HwndWrapper[AWCCOverlay;;bf9c092f-66f9-4a17-b0ea-934dec865872]", // class name that correspond to disposable Handle from WPF ( AKA, a problem ) 
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