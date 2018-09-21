#include<iostream>
using namespace std;
void callatz(int num,int* buf);
bool hasAppeared(int num,int* buf,int length);

void resort(int* nums,int length);
int bufCount=0;
int main()
{
	int num;
	cin>>num;
	int nums[num];
	for(int i=0;i<num;i++)
		cin>>nums[i];
	//cout<<hasAppeared(10,nums,num);
	
	int buf[100];//用来存储出现过的数
	int keys[num];//用来存储关键数
	int count=0;//用来存储关键数的个数
	for(int i=0;i<num;i++)
		callatz(nums[i],buf);
	for(int i=0;i<num;i++)
		if(!hasAppeared(nums[i],buf,bufCount))
		{
			keys[count]=nums[i];
			count++;
		}
	resort(keys,count);
	for(int i=0;i<count;i++)
		cout<<keys[i]<<" ";
	cout<<endl;
	for(int i=0;i<bufCount;i++)
		cout<<buf[i]<<" ";
	
	return 0;
}
void callatz(int num,int *buf)
{
	while(num!=1)
	{
	if(num%2==0)//偶数
	{
		num/=2;
	} else//奇数
	{
		num=(3*num+1)/2;
	}
	if(!hasAppeared(num,buf,bufCount))
			buf[bufCount++]=num;
	//cout<<num<<" ";
	
	}
	//cout<<endl;
	
	
}
bool hasAppeared(int num,int* buf,int length)
{
	for(int i=0;i<length;i++)
		if(num==buf[i])
			return true;
	return false;
}
void resort(int* nums,int length)
{
	int buf;
	for(int i=0;i<length;i++)
		for(int j=0;j<i;j++)
		{
			if(nums[i]>nums[j])
			{
				buf=nums[i];
				nums[i]=nums[j];
				nums[j]=buf;
			}
		}
}
