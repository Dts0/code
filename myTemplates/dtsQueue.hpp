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
		return dtsList<T>::pBegin->value;
	}
	T tail(){
		return dtsList<T>::pTail->value;
	}
	~dtsQueue(){
		dtsList<T>::~dtsList();
	}
};

#endif
