// dsharp.cpp
#include "SDL/SDL.h"
#include "DxLib.h"
#include <stdlib.h>

extern SDL_Surface *screen;

int DrawPixel( int x , int y , int Color )
{
	/* 初期化 */
	int ech = 0;
	SDL_Rect sr;
	Uint32 col= (Uint32)Color;
	
	sr.x = x;
	sr.y = y;
	sr.w = 1;
	sr.h = 1;
	
	ech = SDL_FillRect( screen, &sr, col);
	
	
	return 0;
}

int DrawLine( int x1 , int y1 , int x2 , int y2 , int Color ) 
{
	/* 初期化 */
	int ech = 0;
	const Uint32 col= (Uint32)Color;
	double dx = double(abs(y1 - y2)) / double(abs(x1 - x2)) ;
	double y = y1;
	
	for( int i=0; i < abs( x1 - x2); i++)
	{
		
		DrawPixel( x1+i, y, col );
		printf("%f\n", dx);
		y = y + dx;
		
	}
	
	
	return ech;
}
