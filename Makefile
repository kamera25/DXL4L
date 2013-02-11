#Makefile 1

#マクロ定義部
CC	= g++
OBJS	= main.o font.o time.o
LIB = -lSDL -lSDL_ttf


#生成規則部
libDxLib.so: $(OBJS)
		$(CC) -fPIC -shared  -o $@ $(OBJS) $(LIB) 
		
.cpp.o:
		$(CC) -c  $< $(LIB)
		
main.o: DxLib.h 

font.o: DxLib.h

time.o: DxLib.h

clean:
	rm -f *.o
	rm -f libDxLib.so


