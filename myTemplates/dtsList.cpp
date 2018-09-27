#include<iostream>
#include<string>
#include"dtsList.hpp"
using namespace std;

int main(){
	dtsList<string> l;
	l.add2Head("one");
	l.add2End("two");
	l.add2End("three");
	l.add2Head("zero");

	l.print("->");
	l.print_rev();
	cout<<"size:"<<l.size()<<endl;

	cout<<l.deleteFromEnd()<<" 被删除"<<endl;
	l.print("->");
	cout<<"size:"<<l.size()<<endl;

	cout<<l.deleteFromHead()<<" 被删除"<<endl;
	l.print("->");
	cout<<"size:"<<l.size()<<endl;

	cout<<l.deleteFromHead()<<" 被删除"<<endl;
	l.print("->");
	cout<<"size:"<<l.size()<<endl;

	cout<<l.deleteFromHead()<<" 被删除"<<endl;
	l.print("->");
	cout<<"size:"<<l.size()<<endl;
}
