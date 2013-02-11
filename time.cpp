// time.cpp
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "SDL/SDL.h"
#include "DxLib.h"


int	GetDateTime( DATEDATA *DateBuf )
{
	
	int ech = 0;
	
	struct tm *s_time;
	time_t ptime;
	
	time( &ptime);
	s_time = gmtime( &ptime);
	
	DateBuf->Year = s_time->tm_year + 1900;
	DateBuf->Mon = s_time->tm_mon+1;
	DateBuf->Day = s_time->tm_mday;
	DateBuf->Hour = s_time->tm_hour; 
	DateBuf->Min = s_time->tm_min;
	DateBuf->Sec = s_time->tm_sec;
	
	return ech;
}

int	GetNowCount( void )
{
	
	return (int)SDL_GetTicks();
}
