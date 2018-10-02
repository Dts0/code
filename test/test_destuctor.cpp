#include<iostream>

using namespace std;

class Base{
public:
	int* val;
	Base(int v){
		val=new int(v);
	}
	virtual ~Base(){
		delete val;
		cout<<"distroyed in base"<<endl;
	}
};
class child:public Base{
public:
	child(int v):Base(v){}
	~child(){
		this->~Base();
		cout<<"distroyed"<<endl;
	}
};

int main(){
	child c0(0);
	//child c1(0);
	return 0;
}
