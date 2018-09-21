#include<iostream>
#include<stdlib.h>
using namespace std;

int main(){
	string s0="something0";
	int i=99;
	auto func=[i,s0](string s) -> int {cout<<"hello lambda\n"<<i<<endl<<s0<<endl;cout<<s<<endl;return 1;};
	
	cout<<func("the spec string")<<endl;
	return 0;
}


