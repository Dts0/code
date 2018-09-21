#include<iostream>
#include<list>
#include<stdlib.h>
using namespace std;
typedef struct skill_t{
	bool (*judgeFunc)(std::string cmd);//判定函数,判断是否符合执行条件,当然,您也可以在这里面顺便填充pList
	std::string (*execFunc)(int numP,list<long> pList);//执行函数,返回值是返回的回复
	int numP;
	list<long> pList;//执行函数的输入参数列表,您只能输入整数,并且应当处理所有情况的输入
	std::string name;
	std::string introduce;
} skill_t;

string printList(int num,list<long> l){
	for(list<long>::iterator iter=l.begin();iter!=l.end();iter++)
		cout<<*iter<<"\t";
	return "\n";
}
int main(){
	list<long> pList(10);
	
	pList.push_front(100);
	pList.push_front(200);
	
	
	skill_t s;
	s.pList=pList;
	s.execFunc=printList;
	cout<< s.execFunc(0,s.pList);
	return 0;
}

