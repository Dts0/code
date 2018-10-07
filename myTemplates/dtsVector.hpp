#ifndef DTS_VECOTR_HPP
#define DTS_VECOTR_HPP

#include<iostream>

template<typename T>
class dtsVector{
protected:
	T* vals;
	int maxSize;//当前的vector的容量
	int _size;//当前已存储元素个数
	void extend(){//扩展,默认为扩展到原来最大的两倍
		int newMaxSize=maxSize*2;
		T* tmp_vals=new T[newMaxSize]();
		for(int i=0;i<maxSize;++i){
			tmp_vals[i]=vals[i];
		}
		delete[] vals;
		vals=tmp_vals;
		//std::cout<<"extend from "<<maxSize<<" to "<<newMaxSize<<std::endl;
		maxSize=newMaxSize;
	}
public:
	static int defaultSize;//=10,defined at line 64
	dtsVector(int size=defaultSize):maxSize(size),_size(0){
		vals=new T[maxSize]();
	}

	dtsVector<T>& push_back(T val){
		if(++_size>maxSize){
			extend();
		}
		vals[_size-1]=val;
		return *this;
	}
	T pop_back(){
		if(_size==0){
			throw std::out_of_range("空数组");
		}
		return vals[_size-1];
	}

	T& at(int index){
		if(index>=_size || index<0){
			throw std::out_of_range("数组超界");
		}
		return vals[index];
	}
	T& operator[](int index){
		return at(index);
	}
	void print(char sp=',',std::ostream& os=std::cout){
		for(int i=0;i<_size-1;++i){
			os<<vals[i]<<sp;
		}
		os<<vals[_size-1]<<std::endl;
	}

	virtual ~dtsVector(){
		delete[] vals;
	}
};

template<typename T>
int dtsVector<T>::defaultSize=10;

#endif
