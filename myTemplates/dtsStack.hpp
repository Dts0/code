#ifndef DTS_STACK_HPP
#define DTS_STACK_HPP
#include"dtsList.hpp"

template <typename T>
class dtsStack:public dtsList<T> {
public:
	dtsStack():dtsList<T>(){}
	dtsStack<T>& push(T val){
		dtsList<T>::add2End(val);
		//cout<<"add"<<val<<endl;
		return *this;
	}
	T pop(){
		return dtsList<T>::deleteFromEnd();
	}
	T top(){
		if(dtsList<T>::pTail)
			return dtsList<T>::pTail->value;
		else return T();
	}
	T bottom(){
		if(dtsList<T>::pBegin)
			return dtsList<T>::pBegin->value;
		else return T();
	}
	~dtsStack(){
		//不需要再手动调用析构函数
		//dtsList<T>::~dtsList();
		//cout<<"stack freed"<<endl;
	}
};

#endif
