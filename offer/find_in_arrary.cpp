#include<iostream>
#include<stdlib.h>
using namespace std;
bool isFound(int* array,int row,int col,int num);
int main(){
	int row,col;
	cin>>row>>col;
	int array[row][col];
	for(int i=0;i<row;++i)
		for(int j=0;j<col;++j)
			cin>>array[i][j];
	cout<<"which number would you like to find?"<<endl;
	int num;
	cin>>num;
	cout<<string(isFound((int*)array,row,col,num)?"find it":"don't find it")<<endl;
}

bool isFound(int* array,int row,int col,int num){
	bool ret=false;
	if(array!=NULL&&row>0&&col>0){
		int r=0;
		int c=col-1;
		while(r<row&&c>=0){
			if(num==array[r*col+c]){
				ret=true;
				goto func_end;
			}
			else if(num<array[r*col+c]){
				--c;//如果要找的数比当前小，往左找
			}
			else {
				++r;//如果要找的数比当前大，往右找
			}
		}
	}
	func_end:
	return ret;
}
