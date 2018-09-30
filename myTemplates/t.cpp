#include"dtsQueue.hpp"
#include<queue>
using namespace std;

int main(){
	dtsList<int> l;
	l.add2Head(0).add2Head(1).add2Head(2).add2Head(3);
	cout<<l.deleteFromHead()<<l.deleteFromHead()<<l.deleteFromHead()<<endl;
	dtsQueue<int> q;
	q.push(0).push(1).push(2).push(3);
	cout<<q.pop()<<q.pop()<<q.pop()<<endl;
	q.push(4).push(5);
	cout<<q.pop()<<q.pop()<<endl;

	queue<int> q0;
	q0.push(0);q0.push(1);q0.push(2);q0.push(3);
	cout<<q0.front();q0.pop();
	//cout<<q0.front();q0.pop();
	cout<<q0.front();q0.pop();
	cout<<q0.front();q0.pop();
}
