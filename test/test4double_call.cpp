#include<iostream>
#include<stdlib.h>
#define test_msg (msg+"1")
using namespace std;

void func(string msg){
	cout<<msg<<endl;
}

int main(){
	string msg="hello";
	func((msg+"0"));
	func(test_msg);
	func(msg+"2");
	return 0;
}

