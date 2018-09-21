#include<iostream>
using namespace std;

template<typename T,typename Ts=ostream>
void print(T input,Ts& os=cout){
	os<<input<<endl;
}
template<typename T,typename Ts>
class printDao{
public:
	printDao(){}
	
	static void print(T input,Ts& os=cout){
		os<<input<<endl;
	}
};

int main(){
	print("hello template");
	
	printDao<string,ostream> p;
	p.print("hello template in class");
	return 0;
}

