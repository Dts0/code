#include<iostream>
using namespace std;


class value{
private:

public:
	int val;
	value(const value& v):val(v.val){}
	value(int v):val(v){}
	void operator=(const value& v){
		val=v.val;
	}
};

template<typename T >
void swap_dts(T&& a,T&& b){//需要类型T有复制构造函数，可以是默认的
	auto tmp=a;
	a=b;
	b=tmp;
}

int main(){
	value va(1),vb(2);
	swap_dts(va,vb);//正常的使用方法
	cout<<va.val<<vb.val<<endl;

	int&& right_ref_a=3;
	int&& right_ref_b=4;
	swap_dts(right_ref_a,right_ref_b);//因为某个面试官问到的，所以使用了右值引用，我可区特么的吧，会有人这么用？
	cout<<right_ref_a<<right_ref_b<<endl;
	return 0;
}
