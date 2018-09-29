#include"dtsStack.hpp"

int main(){
	cout<<"main"<<endl;
	dtsList<int> list;
	list.add2End(0).add2End(1).add2Head(2).print();
	cout<<list.deleteFromEnd()<<endl;
	dtsStack<int> stack;
	stack.push(0).push(1).push(2).push(3);
	cout<<"top:"<<stack.top()<<endl<<"content:\n";
	stack.print("\n","空栈");
	cout<<endl;

	cout<<stack.pop()<<endl;
	cout<<stack.pop()<<endl;
	cout<<stack.pop()<<endl;
	cout<<stack.pop()<<endl;
	stack.print("\n","空栈");
	return 0;
}
