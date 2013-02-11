// main.c
#include <stdio.h>
#include "SDL/SDL.h"
#include <SDL/SDL_ttf.h>
#include "DxLib.h"

SDL_Surface *screen;
bool SDLInitFlg = false;
int SDLFullScreenState = FALSE;

TTF_Font* font;
SDL_Surface *image;
SDL_Rect rect, scr_rect;

int WindowWidth = 640;
int WindowHeight = 480;
int WindowFixingFlg = FALSE;
Uint32 WindowBGColor = 0;

int DxLib_init()
{

	int ech = 0;

	if( SDLInitFlg != false) return -1;
	SDLInitFlg = true;	//フラグ立て

	SDL_Init(SDL_INIT_EVERYTHING);
	atexit( DxLib_End);
	
	/* フォント関連の処理 */
	ech = TTF_Init();
	if(ech == -1){
		return -1;
	}
	atexit( TTF_Quit);
	
	/* フォントの読み込み */
	font = TTF_OpenFont( "monospace", 24);
	//テスト!!
	//image = TTF_RenderUF8_Blended( font, "こんにちは", white);
	
	SetGraphMode( WindowWidth, WindowHeight, 0);
	
	/* 背景色を黒にする */
	SetBackgroundColor( 0, 0, 0);
	
	/* フルスクリーンモード切り替え */
	if( SDLFullScreenState == FALSE){
		ChangeWindowMode( TRUE );
	}
	
	/* メッセージ */
	printf("Initialize\n");	

	return ech;
}

void DxLib_End(){
	
	if( SDLInitFlg != true) return ;
		
	//テスト	
	//SDL_FreeSurface(image);
	TTF_CloseFont(font);
		
	TTF_Quit();// ttf開放	
	SDL_Quit();// 本体開放
	
	

	
	
	printf("Quit\n");
	
	SDLInitFlg = false;
	
	return;
}



int WaitTimer( int WaitTime)
{
	int ech = 0;
	Uint32 UsWT = (Uint32)WaitTime;
	
	if( WaitTimer < 0)
	{
			return -1;
	}
	
	SDL_Delay(UsWT);
	
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

int DrawLine( int x1 , int y1 , int x2 , int y2 , int Color )
{
	int ech = 0; // エラーチェック変数
	
	
	return 0;
}

int ChangeWindowMode( int Flag )
{
	int ech = 0;
	
	/* 初期化前に呼び出したら */
	if( SDLInitFlg == false){
		
		SDLFullScreenState = Flag;
		return ech;
	}
	
	if( Flag != SDLFullScreenState)
	{
		SDL_WM_ToggleFullScreen( screen);
	}

	return ech;
}

int	SetMousePoint( int PointX , int PointY )
{
	int ech = 0;

	SDL_WarpMouse( PointX, PointY);

	return ech;
}


int	SetGraphMode( int SizeX , int SizeY , int ColorBitNum )
{
	int ech = DX_CHANGESCREEN_OK;
	
	/* 初期化前に呼び出したら */
	if( SDLInitFlg == false){
		WindowWidth = SizeX;
		WindowHeight = SizeY;
		return DX_CHANGESCREEN_OK;
	}
	
	screen = SDL_SetVideoMode( SizeX, SizeY, 8, SDL_SWSURFACE);
	WindowWidth = SizeX;
	WindowHeight = SizeY;
	
	return ech;
	
} 

int SetWindowSizeChangeEnableFlag( int Flag )
{
	
	int ech = 0;
	
	/* 初期化前に呼び出したら */
	if( SDLInitFlg == false){
		
		return -1;
	}
	
	
	if( Flag != WindowFixingFlg)
	{	
		if( Flag == TRUE)// サイズ変更できるようにする
		{
			screen = SDL_SetVideoMode( WindowWidth, WindowHeight, 8, SDL_SWSURFACE | SDL_RESIZABLE);
			WindowFixingFlg = TRUE;
		}
		else{ // サイズ変更不可にする
			screen = SDL_SetVideoMode( WindowWidth, WindowHeight, 8, SDL_SWSURFACE);
			WindowFixingFlg = FALSE;
		}
	}
	
	
	return ech;
}

int ClearDrawScreen(void)
{
	int ech = 0;
	
	DrawBox( 0, 0, WindowWidth, WindowHeight, WindowBGColor, TRUE);
	
	return ech;
}

int SetBackgroundColor( int Red, int Green, int Blue ) 
{
	int ech = 0;
	
	WindowBGColor = GetColor( Red, Green, Blue);
	
	return ech;
}
