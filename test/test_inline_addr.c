#include<stdio.h>
#include<stdlib.h>

int add(int x,int y);//inline 函数必须要有前置声明

int inline add(int x,int y){
	return x+y;
}
int add2(int x,int y){
	return x+y;
}

int main(){
	int r=add(2,55);
	printf("%d\n%x\n%x\n",r,(unsigned int)&add,(unsigned int)&add2);
	return 0;
}

