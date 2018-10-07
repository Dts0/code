#include"dtsVector.hpp"

using namespace std;

int main(){
	dtsVector<char> st;
	//添加到最后
	st.push_back('a').push_back('b').push_back('c').push_back('d');
	//可以用print函数遍历输出所有元素
	st.print(' ',cout);
	//重载了运算符[]
	st[0]='t';
	cout<<st[0]<<endl<<st[1]<<endl;
	//索引超界时抛出异常
	try{
		cout<<st[-1]<<endl;
	}
	catch(out_of_range e){
		cout<<e.what()<<endl;
	}
	return 0;
}
