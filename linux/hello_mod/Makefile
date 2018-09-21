obj-m := hello_mod.o

KERNEL_DIR := /usr/src/linux-headers-4.4.0-134-generic
PWD := $(shell pwd)

all:
	make -C $(KERNEL_DIR) SUBDIRS=$(PWD) modules
clean:
	rm *.o *.ko
		 
.PHONY:clean

