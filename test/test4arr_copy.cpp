#include<iostream>
#include<typeinfo>
using namespace std;

void func(int arr[]){
	arr[0]=1;
	
	cout<<"type of arr in func : "<<typeid(arr).name()<<endl;
	cout<<"address of arr in func : "<<arr<<endl;
}

int main(){
	int arr[10];
	arr[0]=0;
	
	func(arr);
	
	cout<<arr[0]<<endl;
	cout<<"type of arr outside : "<<typeid(arr).name()<<endl;
	cout<<"address of arr outside : "<<arr<<endl;
	return 0;
}

