#include<iostream>
#include<stdlib.h>
using namespace std;
typedef void (*fun1)(string);
typedef void (*fun2)(void);
class test{
public:
	string str;
	void print(){
		cout<<str;
	}
	static void print_static(){
		cout<<"static passed"<<endl;
	}
	test(string s){
		str=s;
	}
};
void print(string s){
	cout<<s<<endl;
}
int main(){
	test t("passed\n");
	t.print();
	
	fun1 f1=print;
	f1("pass");
	
	fun2 f2=t.print_static;
	f2();
	
	return 0;
}

