#include"dtsStack.hpp"
#include"dtsQueue.hpp"

int main(){
	//栈
	dtsStack<int> stack;
	stack.push(0).push(1).push(2).push(3);
	cout<<"top:"<<stack.top()<<endl
		<<"bottom:"<<stack.bottom()<<endl
		<<"content:";
	stack.print(" ","空栈");

	cout<<stack.pop()<<" ";
	cout<<stack.pop()<<" ";
	cout<<stack.pop()<<" ";
	cout<<stack.pop()<<" ";
	stack.print(" ","空栈");

	cout<<endl;


	//队列
	dtsQueue<int> queue;
	queue.push(0).push(1).push(2).push(3);
	cout<<"front:"<<queue.front()<<endl
		<<"tail:"<<queue.tail()<<endl
		<<"content:";
	queue.print(" ","空队列");

	cout<<queue.pop()<<" ";
	cout<<queue.pop()<<" ";
	cout<<queue.pop()<<" ";
	cout<<queue.pop()<<" ";
	queue.print(" ","空队列");

	return 0;
}
