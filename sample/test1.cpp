#include "DxLib.h"

int main(void)
{

	DxLib_init();
	SetMainWindowsText( "こんにちは");
	WaitTimer(10);
	DxLib_End();
	return 0;
}
