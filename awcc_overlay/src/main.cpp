#include "overlay.h"

int main()
{
	Overlay awccOverlay(
		"HwndWrapper[AWCCOverlay;;a6ca78f7-8648-45d9-95cc-b5b75da0044d]", // 
		"AWCC Overlay",
		WS_EX_LAYERED | WS_EX_TOOLWINDOW | WS_EX_TOPMOST | WS_EX_TRANSPARENT
	);
	return 0;
}