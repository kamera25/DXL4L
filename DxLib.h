#ifndef DXLIB_H
#define DXLIB_H

#define DX_CHANGESCREEN_OK 0
#define DX_CHANGESCREEN_RETURN 1
#define DX_CHANGESCREEN_DEFAULT 2
#define FALSE 0
#define TRUE 1

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

#endif
