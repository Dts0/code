SRCS    = $(wildcard *.cpp)
OBJS    = $(patsubst %.cpp, %.o, $(SRCS))

CC      = g++
CFLAGS  = -g -Wall -O0 

TARGET      = ./bin/test.out
INC_PATH    = -I./include/
LIB_PATH    = -L./lib/

EXT_LIB     = #./lib/libtest.a
EXT_SO		= -L. -ltest -Wl,--rpath=./lib/
EXT_SO_CC	= -fPIC -shared

all:$(TARGET)

$(TARGET):$(OBJS)
	if [ ! -d "bin/" ];then mkdir bin;fi
	$(CC) $(LIB_PATH) $(CFLAGS) -o $@ $^ $(EXT_LIB) $(EXT_SO) 

%.o:%.cpp
	$(CC) $(INC_PATH) $(CFLAGS) -c -o $@ $<
%.o:%.c
	$(CC) $(INC_PATH) $(CFLAGS) -c -o $@ $<

run:$(TARGET)
	$(TARGET)

.PHONY:clean
clean:
	rm -rf $(TARGET) $(OBJS)
