#include<iostream>
#include"../myTemplates/dtsStack.hpp"

using namespace std;
template<typename T>
class CQueue{
public:
	CQueue(){}
	~CQueue(){}
	void appendTail(const T& node){
		stack1.push(node);
	}
	T deleteHead(){
		if(stack2.empty()){
			while(!stack1.empty()){
				stack2.push(stack1.pop());
			}
		}
		if(stack2.empty())
			throw std::out_of_range("空队列");
		return stack2.pop();
	}
private:
	dtsStack<T> stack1;
	dtsStack<T> stack2;
};


int main(){
	CQueue<int> q;
	q.appendTail(0);
	q.appendTail(1);
	q.appendTail(2);
	q.appendTail(3);
	cout<<q.deleteHead()<<endl;
	q.appendTail(4);
	cout<<q.deleteHead()<<endl;
	cout<<q.deleteHead()<<endl;
	cout<<q.deleteHead()<<endl;
	cout<<q.deleteHead()<<endl;
	return 0;
}
