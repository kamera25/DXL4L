#ifndef DXLIB_H
#define DXLIB_H

#define DX_CHANGESCREEN_OK 0
#define DX_CHANGESCREEN_RETURN 1
#define DX_CHANGESCREEN_DEFAULT 2
#define FALSE 0
#define TRUE 1



struct DATEDATA{
	int Year;
	int Mon;
	int Day;
	int Hour;
	int Min;
	int Sec;
};


int DxLib_init();
void DxLib_End();
int WaitTimer( int WaitTime);
int SetMainWindowsText( const char *WindowText);
int GetColor( int Red, int Green, int Blue);
int DrawBox( int x1 , int y1 , int x2 , int y2 , int Color , int FillFlag ) ;
int ChangeWindowMode( int Flag );
int	SetMousePoint( int PointX , int PointY );
int	SetGraphMode( int SizeX , int SizeY , int ColorBitNum );
int SetWindowSizeChangeEnableFlag( int Flag );
int ClearDrawScreen(void);
int SetBackgroundColor( int Red, int Green, int Blue ) ;

int ScreenFlip( void );

int DrawLine( int x1 , int y1 , int x2 , int y2 , int Color ) ;

/* 図形関係 */
int DrawPixel( int x , int y , int Color );

/* 時間(Time)関連 */
int	GetNowCount( void );
int	GetDateTime( DATEDATA *DateBuf );

#endif
