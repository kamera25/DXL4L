#Makefile 1

#マクロ定義部
CC	= g++
OBJS	= main.o
LIB = SDL


#生成規則部
libDxLib.so: $(OBJS)
		$(CC) -fPIC -shared  -o $@ $(OBJS) -l$(LIB) 
		
.cpp.o:
		$(CC) -c  $< -l$(LIB)
		
main.o: DxLib.h 

clean:
	rm -f *.o
	rm -f libDxLib.so
