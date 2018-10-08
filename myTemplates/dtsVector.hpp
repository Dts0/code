#ifndef DTS_VECOTR_HPP
#define DTS_VECOTR_HPP

#include<iostream>

template<typename T>
class dtsVector{
protected:
	T* vals;
	int maxSize;//当前的vector的容量
	int _size;//当前已存储元素个数
	void extend(int addedSize){//扩展addedSize个元素的空间
		int newMaxSize=maxSize+addedSize;
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
	static int defaultSize;//=10,defined at line 117
	dtsVector(int size=defaultSize):maxSize(size),_size(0){
		vals=new T[maxSize]();
	}
	//复制构造函数
	dtsVector(const dtsVector<T>& vec):maxSize(vec.maxSize),_size(vec._size){
		vals=new T[maxSize]();
		for(int i=0;i<_size;++i){
			vals[i]=vec.vals[i];
		}
		//std::cout<<"copyed "<<_size<<std::endl;
		//print();
	}
	bool empty(){
		return _size==0;
	}
	int size(){
		return _size;
	}

	dtsVector<T>& push_back(T val){
		if(++_size>maxSize){
			extend(maxSize+1);//选用2*maxSize+1,+1是为了防止原来为空时出问题
		}
		vals[_size-1]=val;
		return *this;
	}
	dtsVector<T>& append(T val){
		return push_back(val);
	}
	dtsVector<T>& append(dtsVector<T>& vec){
		if(_size+vec._size>maxSize){
			extend(vec._size);
		}
		for(int i=_size;i<_size+vec._size;++i){
			vals[i]=vec.vals[i-_size];
		}
		_size=_size+vec._size;
		return *this;
	}
	T pop_back(){
		if(_size==0){
			throw std::out_of_range("空数组");
		}
		return vals[--_size];
	}

	T& at(int index){
		if(index>=_size || index<0){
			throw std::out_of_range("数组超界");
		}
		return vals[index];
	}

	void print(char sp=',',std::ostream& os=std::cout){
		for(int i=0;i<_size-1;++i){
			os<<vals[i]<<sp;
		}
		os<<vals[_size-1]<<std::endl;
	}

	//重载运算符
	T& operator[](int index){
		return at(index);
	}
	dtsVector<T> operator+(T val){
		return dtsVector(*this).append(val);
	}
	dtsVector<T> operator+(dtsVector<T>& vec){
		return dtsVector(*this).append(vec);
	}
	void operator+=(T val){
		append(val);
	}
	void operator+=(dtsVector<T>& vec){
		append(vec);
	}

	//重载=
	void operator=(const dtsVector<T>& vec){//不希望出现连等用法
		maxSize=vec.maxSize;
		_size=vec._size;
		vals=new T[maxSize]();
		for(int i=0;i<_size;++i){
			vals[i]=vec.vals[i];
		}
	}

	virtual ~dtsVector(){
		delete[] vals;
	}
};

template<typename T>
int dtsVector<T>::defaultSize=10;

#endif
