#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
int toArr(int x,int DX);
int toInt(int DX,int num);
int main(){
	int A,DA,B,DB;
	cin>>A>>DA>>B>>DB;

	cout<<toInt(DA,toArr(A,DA))+toInt(DB,toArr(B,DB));

	return 0;
}
int toArr(int x,int DX){
	int count=0;
	while(x!=0){
		if(x%10==DX)
			count++;
		x/=10;
		}
	return count;
}
int toInt(int DX,int num){
	int result=0;
	for(int i=0;i<num;i++)
		result+=DX*pow(10,i);
	return result;
}
