#include<stdio.h>
#include<stdlib.h>


int main(){
	int s0=999;
	int s;
	
	s= 3>2?({
		s=10;
		s0+1;
	}):100000;
	printf("%d %d\n",s0,s);
	return 0;
}

