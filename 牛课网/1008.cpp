#include<iostream>
#include<stdlib.h>
using namespace std;
char findMax(int* nums);
int main(){
	int num=0;
	cin>>num;
	int Awin=0,Bwin=0,tie=0;
	int AwinChar[]={0,0,0},BwinChar[]={0,0,0};
	for(int i=0;i<num;i++){
		char a,b;
		cin>>a>>b;
		if(a==b)
			tie++;
		else if((a=='C'&&b=='J')||(a=='J'&&b=='B')||(a=='B'&&b=='C')){
			switch(a){
				case 'B':AwinChar[0]++;break;
				case 'C':AwinChar[1]++;break;
				case 'J':AwinChar[2]++;break;
			}
			Awin++;
		}
		else {
			switch(b){
				case 'B':BwinChar[0]++;break;
				case 'C':BwinChar[1]++;break;
				case 'J':BwinChar[2]++;break;
			}
			Bwin++;
			}
	}
	cout<<Awin<<" "<<tie<<" "<<Bwin<<endl;
	cout<<Bwin<<" "<<tie<<" "<<Awin<<endl;
	cout<<findMax(AwinChar)<<" "<<findMax(BwinChar)<<endl;
	return 0;
}
char findMax(int* nums){
	int max=-1,maxNum=-1;
	for(int i=0;i<3;i++){
		if(nums[i]>maxNum){
			max=i;
			maxNum=nums[i];
		}
	}
	switch(max){
		case 0:return 'B';
		case 1:return 'C';
		case 2:return 'J';
		default:return '\0';
	}
}
