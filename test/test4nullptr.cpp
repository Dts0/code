#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
	int val=99;
	int* ptr=(int*)(&val+100);
	cout<<&val<<endl;
	val=*ptr;
	cout<<ptr<<endl;
	cout<<val<<endl;
	
	cout<<endl;
	ptr=0;
	cout<<ptr<<endl;
	cout<<*ptr<<endl;//无法访问该地址,引发段错误
	return 0;
}

