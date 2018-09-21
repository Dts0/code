//神奇的递归
#include<iostream>
#include<string.h>
using namespace std;

int isPassed(char* s);
int isPassed_A(int A1,int A2,int A3);
int main()
{
	int num=0;
	char str[100];
	cin>>num;
	for(;num>0;num--)
	{
		cin>>str;
		if(isPassed(str)==1)
			cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}

int isPassed(char* s)
{
	int i=0;
	int A1=0,A2=0,A3=0;//分别表示开头,中间,最后的A的数量
	while(s[i]=='A')
	{
		A1++;
		i++;
	}
	//cout<<1<<" "<<A1;
	if(s[i++]!='P')//如果没有P，则不通过
		goto unpassed;
	//cout<<2;
	if(s[i]=='P')//如果P数量大于1，则不通过
		goto unpassed;
	while(s[i]=='A')
	{
		A2++;
		i++;
	}
	//cout<<3;
	if(s[i++]!='T')//如果没有T，则不通过
		goto unpassed;
	//cout<<4;
	if(s[i]=='T')//如果T数量大于1，则不通过
		goto unpassed;
	
	while(s[i]=='A')
	{
		A3++;
		i++;
	}
	//以下是对A的判断
	//cout<<5;
	if(isPassed_A(A1,A2,A3)!=1)
		goto unpassed;
	
passed:
	return 1;
unpassed:
	return 0;
}
int isPassed_A(int A1,int A2,int A3)
{
	if(A2==0)//如果中间没有A，则不通过
		return 0;
	if(A1==A3 && A2==1)//如果xPATx,则通过
		return 1;
	if(isPassed_A(A1,A2-1,A3-A1)==1)//如果 aPbTc 是正确的，那么 aPbATca 也是正确的(a=A1,b+1=A2,c+a=A3)
		return 1;
	return 0;
}
