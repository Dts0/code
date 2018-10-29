#include"dtsSharedPtr.hpp"
#include<iostream>

using namespace std;

int main(){
	dtsSharedPtr<int> sharedPtr(99);
	cout<<sharedPtr.getCount()<<endl;//计数为1

	dtsSharedPtr<int> p1=sharedPtr;//计数为2,分别为sharedPtr和p1
	cout<<sharedPtr.getCount()<<endl;
	{
		dtsSharedPtr<int> p2(3);//p2计数1
		p2=sharedPtr;//左侧计数为0,故被销毁;右侧计数为3,分别为sharedPtr,p1,p2
		cout<<sharedPtr.getCount()<<endl;
	}//p2超出作用域,销毁后count变为2,分别为sharedPtr,p1
	cout<<sharedPtr.getCount()<<endl;

	dtsSharedPtr<int> p3;//空共享指针
	cout<<sharedPtr.getCount()<<endl;
	{
		dtsSharedPtr<int> p4(0);
		p4=p3;//左侧内容因为计数为0被销毁,p3,p4都是空共享指针了
		sharedPtr=p4;//现在sharedPtr也为空共享指针,原sharedPtr的计数值变为1,只有p1
		cout<<p1.getCount()<<endl;
	}

	//像普通指针一样使用
	cout<<"p1:"<<*p1<<endl;//*运算符
	string s="abc";
	dtsSharedPtr<string> strPtr(s);
	cout<<strPtr->length()<<endl;//->运算符

	//此时有三个空共享指针,sharedPtr,p3和p4
	//返回时因为所有共享指针都超出作用域,自动销毁所有共享指针
	return 0;
}
