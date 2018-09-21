#include<stdio.h>

void getNums(char num[],int nums[]);
void getNums_2(int num,int nums[]);
void printNum(int num);
void exchange(int input[],int length);
int atoi(char c);

int main()
{
	char input[100];
	scanf("%s",input);
	int nums[100];
	getNums(input,nums);
	
	int sum=0;
	for(int i=0;nums[i]!=-1;i++)
	{
		sum+=nums[i];
	}
	int results[100];
	getNums_2(sum,results);
	for(int i=0;results[i]!=-1;i++)
	{
		printNum(results[i]);
		if(results[i+1]!=-1)
			printf(" ");
	}
	
	return 0;
}
void getNums(char num[],int nums[])//因为10^100超出C语言表达范围,只能用数组来代替
{
	int i;
	for(i=0;num[i]!='\0';++i)
	{
		nums[i]=atoi(num[i]);
		if(nums[i]==-1)
			printf("an err occured while getting nums.");
	}
	nums[i]=-1;
}
void getNums_2(int num,int nums[])
{
	int i=0;
	while(num>=10)
	{
		nums[i]=num%10;//取最后一位
		num=num/10;//整体右移一位
		++i;
	}
	nums[i]=num%10;
	nums[i+1]=-1;//-1填充
	//接下来的部分用于调整顺序
	exchange(nums,i+1);
}
void printNum(int num)//打印一个数字0~9的拼音
{
	switch(num)
	{
		case 0:printf("ling");break;
		case 1:printf("yi");break;
		case 2:printf("er");break;
		case 3:printf("san");break;
		case 4:printf("si");break;
		case 5:printf("wu");break;
		case 6:printf("liu");break;
		case 7:printf("qi");break;
		case 8:printf("ba");break;
		case 9:printf("jiu");break;
		default:
			break;
	}
}
void exchange(int input[],int length)
{
	int buf[length/2];
	for(int i=0;i<length/2;++i)
	{
		buf[i]=input[i];
		input[i]=input[length-i-1];
		input[length-i-1]=buf[i];
	}
}
int atoi(char c)
{
	switch(c)
	{
		case '0':return 0;
		case '1':return 1;
		case '2':return 2;
		case '3':return 3;
		case '4':return 4;
		case '5':return 5;
		case '6':return 6;
		case '7':return 7;
		case '8':return 8;
		case '9':return 9;
		default:
			return -1;
	}
}

