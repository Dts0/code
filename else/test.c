#include<stdio.h>
#include<stdlib.h>

typedef void (*fun)(void);

void print(){
	printf("passed\n");
}
int main(){
	fun f=print;
	f();
	
	return 0;
}

