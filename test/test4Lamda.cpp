#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
	void (*testPrint)(void)=[](){std::cout<<"passed";};
	testPrint();
	return 0;
}

