#ifndef DXLIB_H
#define DXLIB_H

int DxLib_init();
void DxLib_End();
int WaitTimer( int WaitTime);
int SetMainWindowsText( const char *WindowText);
int GetColor( int Red, int Green, int Blue);
int DrawBox( int x1 , int y1 , int x2 , int y2 , int Color , int FillFlag ) ;

#endif
