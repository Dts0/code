#include<iostream>
#include<stdlib.h>
#include<tuple>

using namespace std;
int main(){
	auto tp=make_tuple(12,"name","note");
	cout<<get<0>(tp)<<","<<get<1>(tp)<<","<<get<2>(tp)<<endl;
	cout<<tuple_size<tuple<int,string,string>>::value<<endl;

	return 0;
}
