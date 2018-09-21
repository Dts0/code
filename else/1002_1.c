#include<stdio.h>

void getNums(long long num,int nums[]);
void printNum(int num);
void exchange(int input[],int length);

//1234567890987654321123456789
//1844674407370955161
//超界了,换方法，这个只能处理在longlong即1844674407370955161以内的
int main()
{
	long long input=0;
	scanf("%lld",&input);
	int nums[100];//小于2^100的数字最多有99位十进制数,所以设置一个100的数组不会越界
	
	getNums(input,nums);
	int sum=0;
	for(int i=0;nums[i]!=-1;i++)
	{
		sum+=nums[i];
		printf("%d ",sum);
	}
	printf("\n");
	int results[100];
	getNums(sum,results);
	for(int i=0;results[i]!=-1;i++)
	{
		printNum(results[i]);
		if(results[i+1]!=-1)
			printf(" ");
	}
}
void getNums(long long num,int nums[])
{
	int i=0;
	while(num>=10)
	{
		nums[i]=num%10;//取最后一位
		printf("nums[%d]=%d ",i,nums[i]);
		num=num/10;//整体右移一位
		printf("num=%lld\n",num);
		++i;
	}
	nums[i]=num%10;
	printf("nums[%d]=%d ",i,nums[i]);
	nums[i+1]=-1;//-1填充
	printf("%d位\n",i+1);
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

