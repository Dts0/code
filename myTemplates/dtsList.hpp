#ifndef DTS_LIST_HPP
#define DTS_LIST_HPP
#include<iostream>
using namespace std;

template<typename T>
class dtsListNode{
public:
	T value;
	dtsListNode* next;
	dtsListNode* pre;
	dtsListNode(T v,dtsListNode* nextPointer=NULL,dtsListNode* prePointer=NULL)
		:value(v),next(nextPointer),pre(prePointer){}
	dtsListNode():next(NULL),pre(NULL){}
};

template<typename T>
class dtsList{
protected:
	dtsListNode<T>* pHead;//空的头结点
	dtsListNode<T>* pBegin;//链表第一个数据结点
	dtsListNode<T>* pTail;//链表最后一个数据结点
	dtsListNode<T>* pEnd;//空的尾结点
	inline dtsListNode<T>* insertAfter(dtsListNode<T>* first,T val){
		dtsListNode<T>* second = new dtsListNode<T>(val);
		dtsListNode<T>* third = first->next;

		if(first==pHead)
			pBegin=second;
		if(first==pTail)
			pTail=second;

		first->next=second;
		second->pre=first;
		second->next=third;
		third->pre=second;

		return second;
	}
	inline T deleteAfter(dtsListNode<T>* first){
		T ret;
		if(!first || !first->next || !first->next->next)
			return ret;
		dtsListNode<T>* second=first->next;
		dtsListNode<T>* third=second->next;
		ret=second->value;

		if(first==pHead){//删除结点为pBegin时
			pBegin=third;
		}
		if(second==pTail){//删除结点为pTail时
			if(first!=pHead){
			pTail=first;
			}
			else {//删除最后一个结点时
			pBegin=NULL;
			pTail=NULL;
			}
		}


		delete second;
		first->next=third;
		third->pre=first;

		return ret;
	}

public:
	dtsList(){
		pHead = new dtsListNode<T>();
		pEnd = new dtsListNode<T>();
		pBegin = NULL;
		pTail = NULL;

		pHead->next=pEnd;
		pEnd->pre=pHead;
	}
	inline bool empty(){
		return pBegin==NULL;
	}
	int size(){
		if(empty())
			return 0;
		int ret=0;
		for(dtsListNode<T>* it=pBegin;it!=pEnd;it=it->next){
			++ret;
		}
		return ret;
	}
	dtsListNode<T>* begin(){
		return pBegin;
	}
	dtsListNode<T>* end(){
		return pEnd();
	}
	dtsList<T>& add2End(T val){
		if(!pTail || !pBegin){//当前无数据时
			pBegin=insertAfter(pHead,val);
			pTail=pBegin;
			//print();
		} else {//已有至少一个数据结点，将它加在最后
			insertAfter(pTail,val);
			//print();
		}
		//cout<<"node "<<val<<" added"<<endl;
		return *this;
	}
	dtsList<T>& add2Head(T val){
		if(!pBegin || !pTail){//当前无数据时
			pBegin=insertAfter(pHead,val);
			pTail=pBegin;
			//print();
		} else {//已有至少一个数据结点，将它加在最前面
			insertAfter(pHead,val);//新的第一个数据结点
			//print();
		}
		//cout<<"node "<<val<<" added"<<endl;
		return *this;
	}
	T deleteFromEnd(){
		if(pTail){
			return deleteAfter(pTail->pre);
		}
		T ret;
		return ret;
	}
	T deleteFromHead(){
		return deleteAfter(pHead);
	}
	void print(const char* separator="->",const char* null_str="空链表"){
		if(pHead->next==pEnd){
			cout<<null_str<<endl;
			return;
		}
		for( dtsListNode<T>* it=pBegin;it!=pEnd;it=it->next ){
				cout<<it->value;
				if(it!=pEnd->pre)
					cout<<separator;

		}
		cout<<endl;
	}
	void print_rev(const char* separator="<-",const char* null_str="空链表"){
		if(pHead->next==pEnd){
			cout<<null_str<<endl;
			return;
		}
		for( dtsListNode<T>* it=pTail;it!=pHead;it=it->pre ){
				cout<<it->value;
				if(it!=pHead->next)
					cout<<separator;
		}
		cout<<endl;
	}
	virtual ~dtsList(){
		dtsListNode<T>* node2Delete=pHead;
		dtsListNode<T>* nextNode2Delete;
		while(node2Delete){
			nextNode2Delete=node2Delete->next;
			//cout<<"node "<<node2Delete->value<<" deleted."<<endl;
			delete node2Delete;

			node2Delete=nextNode2Delete;
		}
		//cout<<"list freed"<<endl;
	}
};


#endif // !DTS_LIST_HPP
