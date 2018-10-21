CC      = g++
CFLAGS  = -g -Wall -O0 

EXT_LIB     = 
EXT_SO		= -L. -ltestmod
EXT_SO_CC	= -fPIC -shared	#编译动态库时需要额外添加的参数

all:
	make with_so
	make without_so

with_so:
	make so
#	$(CC) $(CFLAGS) $(EXT_SO) $(EXT_SO_CC) -o static_with_so.out static.cpp
so:
	$(CC) $(CFLAGS) $(EXT_SO_CC) -o libtestmod.so testmod.cpp

without_so:
	g++ static.cpp testmod.cpp -o static_without_so.out

clear:	#只删除中间文件的命令
	rm -rf *.o 

.PHONY:clean
clean:
	rm -rf *.out *.o *.so
