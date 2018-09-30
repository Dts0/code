#ifndef DTS_QUEUE_HPP
#define DTS_QUEUE_HPP

#include"dtsList.hpp"

template <typename T>
class dtsQueue:public dtsList<T> {
public:
	dtsQueue():dtsList<T>(){}
	dtsQueue<T>& push(T val){
		dtsList<T>::add2End(val);
		return *this;
	}
	T pop(){
		return dtsList<T>::deleteFromHead();
	}
	T head(){
		if(dtsList<T>::pBegin)
			return dtsList<T>::pBegin->value;
		else return T();
	}
	T tail(){
		if(dtsList<T>::pTail)
			return dtsList<T>::pTail->value;
		else return T();
	}
	~dtsQueue(){
		dtsList<T>::~dtsList();
	}
};

#endif
