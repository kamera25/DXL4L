// main.c
#include <stdio.h>
#include "SDL/SDL.h"
#include "DxLib.h"

SDL_Surface *screen;

int DxLib_init()
{

	int ech = 0;

	SDL_Init(SDL_INIT_EVERYTHING);
	printf("Initialize\n");
	
	atexit( DxLib_End);
	
	screen = SDL_SetVideoMode( 640, 480, 8, SDL_SWSURFACE);

	return ech;
}

void DxLib_End(){
	
	
	SDL_Quit();
	printf("Quit\n");
	
	return;
}

int WaitTimer( int WaitTime)
{
	int ech = 0;
	Uint32 UsWT = (Uint32)WaitTimer;
	
	if( WaitTimer < 0)
	{
			return -1;
	}
	
	printf("%d\n", UsWT);
	SDL_Delay(3000);
	
	return ech;
}

int SetMainWindowsText( const char *WindowText)
{
	
	SDL_WM_SetCaption( WindowText, NULL);
	
	
	return 0;
}
