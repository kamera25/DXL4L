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

/*int GetColor( int Red, int Green, int Blue)
{
	int ColorCode = 0;
	
	Red = abs(Red % 255);
	Green = abs(Green % 255);
	Blue = abs(Blue % 255);
	
	ColorCode = Red<<16+Green<<8+Blue;
	
	return ColorCode;
}*/

int DrawBox( int x1 , int y1 , int x2 , int y2 , 
				int Color , int FillFlag )
{
	int ech = 0;
	SDL_Rect sr;
	SDL_Color scol;
	Uint32 col= (Uint32)Color;
	
	sr.x = x1;
	sr.y = y1;
	sr.w = x2 - x1;
	sr.h = y2 - y1;
	
	scol.r = 255;
	scol.g = 255;
	scol.b = 255;

	//SDL_FillRect( screen, &sr, SDL_MapRGB( screen->format, 255,255,255));
	SDL_FillRect( screen, &sr, col);
	SDL_Flip( screen);

	return ech;
}

int GetColor( int Red , int Green , int Blue )
{
	
	return (int)(SDL_MapRGB( screen->format, Red,Green,Blue));
}
