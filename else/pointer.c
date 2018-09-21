#include<stdio.h>
#include<stdlib.h>

void swap(int* x,int* y){
	int tmp;
	tmp=*y;
	*y=*x;
	*x=tmp;
}

int main(){
	int x=100,y=999;
	printf("%d %d\n",x,y);
	swap(&x,&y);
	printf("%d %d",x,y);
	return 0;
}
/*
	int tmp;
	tmp=y;
	y=x;
	x=tmp;
*/
/*
	int* tmp_ptr=(int *)malloc(sizeof(int));
	*tmp_ptr=y;
	y=x;
	x=*tmp_ptr;
	free(tmp_ptr);
*/
