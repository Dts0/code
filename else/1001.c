#include <stdio.h>
int getCallatzResult(int num);
int main()
{
	int input=0;
	scanf("%d",&input);
	int result=getCallatzResult(input);
	printf("%d",result);
	return 0;
}
int getCallatzResult(int num)
{
	int count=0;
	if(num>1000||num<0)
	{
		return -1;//不符合要求的输入
	}
	while(num!=1)
	{
	if(num%2==0)//偶数
	{
		num/=2;
		count++;
	} else if(num%2==1)//奇数
	{
		num=(3*num+1)/2;
		count++;
	}
	}
	return count;
}
