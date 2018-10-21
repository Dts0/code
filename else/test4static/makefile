CC      = g++
CFLAGS  = -g -Wall -O0 

INC_PATH    = -I.
LIB_PATH    = -L.

EXT_LIB     = 
EXT_SO		= -L. -ltestmod -Wl,--rpath=.
EXT_SO_CC	= -fPIC -shared	

all:
	make with_so
	make without_so

with_so:
	make so
	$(CC) $(CFLAGS) -o static_with_so.out static.cpp $(EXT_SO)
so:
	$(CC) $(CFLAGS) $(EXT_SO_CC) -o libtestmod.so testmod.cpp 

without_so:
	g++ static.cpp testmod.cpp -o static_without_so.out

clear:	#只删除中间文件的命令
	rm -rf *.o 

.PHONY:clean
clean:
	rm -rf *.out *.o *.so
