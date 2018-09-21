 #include<iostream>
 #include<stdio.h>
 #include<math.h>
using namespace std;
int getEvenSum(int* nums,int length);
int getCrossSum(int* nums,int length);
int getLeft2Num(int* nums,int length);
float getLeft3Avr(int* nums,int length);
int getLeft4MaxNum(int* nums,int length);

int main(){
	int num=0;
	cin>>num;
	int nums[num];
	for(int i=0;i<num;i++)
		cin>>nums[i];
	int A1,A2,A3,A5;
	float A4;
	A1=getEvenSum(nums,num);
	A2=getCrossSum(nums,num);
	A3=getLeft2Num(nums,num);
	A4=getLeft3Avr(nums,num);
	A5=getLeft4MaxNum(nums,num);
	if(A1==-1)
		cout<<"N ";
	else cout<<A1<<" ";
	if(A2==-1)
		cout<<"N ";
	else cout<<A2<<" ";
	if(A3==-1)
		cout<<"N ";
	else cout<<A3<<" ";
	if(A4==-1)
		cout<<"N ";
	else printf("%.1f ",A4);
	if(A5==-1)
		cout<<"N";
	else cout<<A5;
	return 0;
}
int getEvenSum(int* nums,int length){
	int sum=0;
	for(int i=0;i<length;i++)
		if(nums[i]%5==0 && nums[i]%2==0)
			sum+=nums[i];
	if(sum==0)
		return -1;
	return sum;
}
int getCrossSum(int* nums,int length){
	int count=0,sum=0;
	for(int i=0;i<length;i++)
		if(nums[i]%5==1){
			sum+=pow(-1,count)*nums[i];
			count++;
		}
	if(count==0)
		return -1;
	return sum;
}
int getLeft2Num(int* nums,int length){
	int count=0;
	for(int i=0;i<length;i++)
		if(nums[i]%5==2){
			count++;
		}
	return count;
}
float getLeft3Avr(int* nums,int length){
	int sum=0;
	float count=0;
	for(int i=0;i<length;i++)
		if(nums[i]%5==3){
			sum+=nums[i];
			count+=1;
		}
	if(count==0) 
		return -1;
	return sum/count;
}
int getLeft4MaxNum(int* nums,int length){
	int max=-1;
	for(int i=0;i<length;i++)
		if(nums[i]%5==4 && nums[i]>max )
			max=nums[i];
	return max;
}

