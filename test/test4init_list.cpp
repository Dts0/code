#include<iostream>
#include<stdlib.h>
#include <string>
#include <initializer_list>
#include <vector>
using namespace std;

template <class T>
class S{
private:
	vector<T> v;
public:
	S(initializer_list<T> il):v(il){
		cout<<"inited"<<endl;
	}
	void append(initializer_list<T> il){
		v.insert(v.end(),il.begin(),il.end());
	}
	void print(){
		for(auto n:v){
			cout<<n<<"\t";
		}
		cout<<endl;
	}
};

int main(){
	string word;
	S<string> str_list{};
	while(cin>>word){
		str_list.append({word});
		cout<<"append "<<word<<endl;
	}
	cout<<"finished,the content of str_list:"<<endl;
	str_list.print();
	return 0;
}
