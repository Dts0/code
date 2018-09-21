#include<iostream>
#include<stdlib.h>
#include <vector>
#include <string>
using namespace std;
int main(){
	vector<string> vec;
	string in;
	while(cin>>in){
		vec.push_back(in);
	}

	cout<<"the contain of vec:"<<endl;
	for(vector<string>::iterator it=vec.begin();it!=vec.end();++it){
		cout<<(*it)<<endl;
	}
	//this part need c++11; -std=c++11
	for(string out : vec){
		cout<<(out)<<endl;
	}

	return 0;
}
