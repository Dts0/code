#include<iostream>
using namespace std;

class Base0{
public:
	Base0(){
		cout<<"base0 built"<<endl;
	}
	virtual ~Base0(){
		cout<<"base0 destroyed"<<endl;
	}
	virtual void doSomething(){
		cout<<"exec doSomething in Base0"<<endl;
	}
};
class Child0:public Base0{
public:
	Child0(){
		cout<<"child0 built"<<endl;
	}
	~Child0(){
		cout<<"child0 distroyed"<<endl;
	}
	void doSomething(){
		cout<<"exec doSomething in child0"<<endl;
	}
};
class Base1{
public:
	Base1(){
		cout<<"base1 built"<<endl;
	}
	virtual ~Base1(){
		cout<<"base1 destroyed"<<endl;
	}
	void doSomething(){
		cout<<"exec doSomething in Base1"<<endl;
	}
};
class Child1:public Base1{
public:
	Child1(){
		cout<<"child1 built"<<endl;
	}
	~Child1(){
		cout<<"child1 distroyed"<<endl;
	}
	void doSomething(){
		cout<<"exec doSomething in child1"<<endl;
	}
};
int main(){
	Base0 *base0=new Base0();
	Child0 *child0=new Child0();

	Base0* child2base_0 = (Base0*)child0;

	base0->doSomething();
	child0->doSomething();
	child2base_0->doSomething();

	delete base0;
	delete child0;

	cout<<"*****************************************"<<endl;
	Base1 *base1=new Base1();
	Child1 *child1=new Child1();

	Base1 *child2base_1 = (Base1*)child1;

	base1->doSomething();
	child1->doSomething();
	child2base_1->doSomething();

	delete base1;
	delete child1;
	return 0;
}
