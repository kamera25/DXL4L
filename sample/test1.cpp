#include "DxLib.h"
#include <stdio.h>

int main(void)
{

	SetGraphMode( 800 , 600, 8);
	ChangeWindowMode(TRUE);
	DxLib_init();
	SetWindowSizeChangeEnableFlag( TRUE);
	SetMainWindowsText( "こんにちは");
	//SetGraphMode( 640 , 480, 8);
	DrawBox( 10, 10, 440, 440, GetColor( 100,255,255),0);

	
	SetMousePoint(10, 10);
	DATEDATA tm;
	GetDateTime( &tm );
	printf("%d年%d月%d日\n", tm.Year, tm.Mon, tm.Day);
	
	
	WaitTimer(1000);
	DxLib_End();
	return 0;
}
