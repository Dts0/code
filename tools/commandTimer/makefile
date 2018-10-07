SRCS    = $(wildcard *.cpp)
OBJS    = $(patsubst %.cpp, %.o, $(SRCS))
HEADS	= $(wildcard *.hpp)

CC      = g++
CFLAGS  = -Wall -O0 $(EXT_SO_CC) -std=c++11

TARGET      = ./bin/commandTimer
INC_PATH    = -I./include/
LIB_PATH    = -L./lib/

EXT_LIB     = #./lib/libreply.a
EXT_SO		= -L. -Wl,--rpath=./lib/
EXT_SO_CC	= -fPIC

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
clear:
	rm -rf $(OBJS)
install:
	make
	cp bin/commandTimer /bin/commandTimer
uninstall:
	rm -rf /bin/commandTimer
test:
	make
	g++ $(CFLAGS) test.c++ -o ./bin/test.out
	bin/commandTimer "bin/test.out 20000"
	
