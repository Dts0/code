#include<stdio.h>
#include<stdlib.h>

#define clear_block(addr) \
__asm__ __volatile__("cld\n\t" \
	"rep\n\t"	\
	"stosl"	\
	::"a" (0),"c" (BLOCK_SIZE/4),"D" ((long) (addr)))

#define clear_block(addr) \
__asm__ __volatile__("cld\n\t"	\	//清方向位
	"rep\n\t"                    \     // 重复执行存储数据(0).
	"stosl" 
	::"a" (0),"c" (BLOCK_SIZE/4),"D" ((long) (addr)))


#define do_it() 	\
		__asm__ __volatile__("movl %1,%0\n\t" \
		"add $50,%0" \
		:"=r" (dst) \
		:"r" (src));
	

int main(){
	unsigned int src=100,dst;
	do_it()
	printf("%u\n",dst);
	return 0;
}

