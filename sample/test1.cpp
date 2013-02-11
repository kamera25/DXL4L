#include "DxLib.h"

int main(void)
{

	ChangeWindowMode(TRUE);
	DxLib_init();
	SetMainWindowsText( "こんにちは");
	
	DrawBox( 10, 10, 440, 440, GetColor( 100,255,255),0);

SetMousePoint(10, 10);
	
	WaitTimer(10);
	DxLib_End();
	return 0;
}
