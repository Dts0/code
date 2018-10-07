#ifndef DTS_STRING_H
#define DTS_STRING_H

#include"dtsVector.hpp"
#include"string.h"
class dtsString :public dtsVector<char>{
public:
	using dtsVector<char>::dtsVector;//使用父类的构造函数
	using dtsVector<char>::operator+=;
	dtsString(const char* str=""){
		int cnt=strlen(str);
		maxSize=cnt;
		_size=cnt;

		vals=new char[cnt]();
		for(int i=0;i<cnt;++i){
			vals[i]=str[i];
		}
	}

	void print(std::ostream& os=std::cout){//隐藏了父类的print
		for(int i=0;i<_size-1;++i){
			os<<vals[i];
		}
		os<<vals[_size-1]<<std::endl;
	}

	const char* c_str(){
		return vals;
	}

	dtsString& append(char val){
		dtsVector<char>::append(val);
		return *this;
	}
	dtsString& append(dtsVector<char>& vec){
		dtsVector<char>::append(vec);
		return *this;
	}
	dtsString& append(dtsString& s){
		dtsVector<char>::append(s);
		return *this;
	}
	dtsString& append(const char* str){
		int cnt=strlen(str);

		extend(cnt);//扩展空间到_size+cnt

		for(int i=_size;i<_size+cnt;++i){
			vals[i]=str[i-_size];
		}
		_size+=cnt;
		return *this;
	}
	dtsString operator+(char val){
		return dtsString(*this).append(val);
	}
	dtsString operator+(dtsVector<char>& vec){
		return dtsString(*this).append(vec);
	}
	dtsString operator+(dtsString& s){
		return dtsString(*this).append(s);
	}
	dtsString operator+(const char* str){
		return dtsString(*this).append(str);
	}
	void operator+=(dtsString& s){
		append(s);
	}
	void operator+=(const char* str){
		append(str);
	}
};

std::ostream& operator<<(std::ostream& os,dtsString& s){//重载运算符<<以使dtsString能直接输出到流
	s.print(os);
	return os;
}

#endif
