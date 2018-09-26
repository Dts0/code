#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

string replace_space(const char* in,int length){//时间复杂度O(n)
	if(!in || length<=0) return "";
	int cnt=0;
	for(int i=0;in[i]!='\0';++i){//数有多少空格，以分配空间
		if(in[i]==' ')
			++cnt;
	}
	//cout<<cnt<<"spaces"<<endl;
	char out[length+cnt*2+1];//输出数组，注：如果为clang，则为length+cnt*2+2
	int Cnt=0;//计数值，当前已经过了几个空格
	for(int i=0;i<length+cnt*2+1;++i){//i为当前在out数组中的位置，此时，在in数组中的位置为i-2*Cnt，即去除当前已过空格
		if(in[i-2*Cnt]!=' '){//不是空格，则原样输出
			out[i]=in[i-2*Cnt];
		}
		else {//是空格，将其替换为%20
			out[i++]='%';out[i++]='2';out[i]='0';
			++Cnt;
		}
	}
	out[length+cnt*2]='\0';
	return string(out);
}

int main(){
	cout<<replace_space("We are happy!",13)<<endl;
	cout<<replace_space("We  are  happy!",15)<<endl;
	cout<<replace_space("Wearehappy!",11)<<endl;
	cout<<replace_space(NULL,0)<<endl;
	cout<<replace_space("Wearehappy!",-1)<<endl;
	return 0;
}
