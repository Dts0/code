#include<iostream>
#include<stdlib.h>
using namespace std;
int main(int argc,char* argv[]){
	cout<<argc<<" args."<<endl;
	for(int i=0;i<argc;++i){
		cout<<argv[i]<<" ";
	}
	cout<<endl;
	cout<<"options:"<<endl;
	for(int i=0;i<argc;++i){
		if(argv[i][0]=='-'){
		cout<<argv[i]<<endl;
		cout<<"the value is :"<<argv[i+1]<<" "<<endl;
		}
	}
	return 0;
}

