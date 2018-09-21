#include<iostream>
#include<stdlib.h>
using namespace std;
template<typename T>
void print(ostream &os,T arg){
	os<<arg<<endl;
}
template<typename T,typename... args>
void print(ostream &os,T arg,args... as){
	os<<arg<<",";
	print(os,as...);
}

int main(){
	print(cout,12);
	print(cout,12,4.8);
	print(cout,12,"hello",string("test"),3.6);
	return 0;
}

