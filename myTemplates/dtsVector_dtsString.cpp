#include"dtsVector.hpp"
#include"dtsString.hpp"

using namespace std;

int main(){
	dtsVector<char> st;//=dtsVector<char>();
	cout<<st.size()<<" "<<st.empty()<<endl;
	//添加到最后
	st.push_back('a').push_back('b').push_back('c').push_back('d');
	cout<<st.size()<<" "<<st.empty()<<endl;
	dtsVector<char> st_copy=st;
	dtsVector<char> _st_copy;
	_st_copy=st;
	//可以用print函数遍历输出所有元素
	st.print(' ',cout);
	//重载了运算符[]
	st[0]='t';
	cout<<st[0]<<endl<<st[1]<<endl;
		//test for +
	st_copy=st_copy+'s';
	cout<<st_copy.size()<<endl;
	_st_copy=_st_copy+st_copy;
	cout<<_st_copy.size()<<endl;
	//test for copy
	st.print();
	st_copy.print();
	_st_copy.print();

	//索引超界和pop空数组时抛出异常
	try{
		while(1)
		cout<<st.pop_back();
	}
	catch(out_of_range e){
		cout<<e.what()<<endl;
	}
	try{
		cout<<st[-1]<<endl;
	}
	catch(out_of_range e){
		cout<<e.what()<<endl;
	}

	dtsString str="dtsString ";
	cout<<str.size()<<" "<<str.empty()<<endl;
	str.append("by");
	str.append(' ');
	str+='d';
	str=str+"ts";
	str+='\n';
	str+="test:";

	str.print();
	cout<<str.c_str()<<endl;
	cout<<str;
	return 0;
}
