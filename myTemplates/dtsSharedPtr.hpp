#ifndef SHARE_PTR_HPP
#define SHARE_PTR_HPP

#include<exception>
#include<iostream>

template<typename T>
class dtsSharedPtr;
template<typename T>
class share_ptr_cont{
	friend class dtsSharedPtr<T>;
	T* ptr;
	int count;
public:
	share_ptr_cont(T val):count(1){
		ptr=new T(val);
	}
};

template<typename T>
class dtsSharedPtr{
	share_ptr_cont<T>* cont;
public:
	dtsSharedPtr(){cont=NULL;}
	dtsSharedPtr(T val){
		cont=new share_ptr_cont<T>(val);
	}
	//复制构造函数
	dtsSharedPtr(const dtsSharedPtr& src){
		cont=src.cont;
		if(src.cont!=NULL)//当src为空智能指针时,cont为NULL,无法调整count
			++cont->count;
	}
	dtsSharedPtr<T>& operator=(const dtsSharedPtr& src){
		if(cont!=NULL)
			if(--cont->count==0){
				delete cont;
				std::cout<<"cont released in operator="<<std::endl;
			}
		cont=src.cont;
		if(src.cont!=NULL)
			++cont->count;
	}
	~dtsSharedPtr(){
		if(cont==NULL){//cont为空时未申请空间
			std::cout<<"NULL sharedPtr deleted"<<std::endl;
			return;
		}
		--cont->count;
		if(cont->count==0){
			delete cont;
			std::cout<<"cont released because count=0"<<std::endl;
		}
	}
	int getCount(){
		if(cont==NULL)
			throw std::out_of_range("空的共享指针");
		return cont->count;
	}

	//以下为指针行为,重载*,->
	T& operator *(){
		return *(cont->ptr);
	}
	T* operator ->(){
		return cont->ptr;
	}
};


#endif // SHARE_PTR_HPP
