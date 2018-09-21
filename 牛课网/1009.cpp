#include<stdio.h>
#include<stdlib.h>
int getNum0(int s);
int getNum1(int s);
void itoa(int n,char* s);
int main(){
	int num0=0,num1=0,num2=0;
	scanf("%d",&num2);
	char s0[5];
	char s1[5];
	char s2[5];
	do{
		num0=getNum0(num2);
		num1=getNum1(num2);
		num2=num0-num1;
		itoa(num0,s0);
		itoa(num1,s1);
		itoa(num2,s2);
		printf("%s - %s = %s\n",s0,s1,s2);
	}while(num2!=0 && num2!=6174);
	return 0;
}
int getNum0(int s){
	char n[5];
	itoa(s,n);
	for(int i=0;i<4;i++)
		for(int j=0;j<i;j++)
			if(n[i]>n[j]){
				char c;
				c=n[i];
				n[i]=n[j];
				n[j]=c;
			}
	return atoi(n);
}
int getNum1(int s){
	char n[5];
	itoa(s,n);
	for(int i=0;i<4;i++)
		for(int j=0;j<i;j++)
			if(n[i]<n[j]){
				char c;
				c=n[i];
				n[i]=n[j];
				n[j]=c;
			}
	return atoi(n);
}
void itoa(int n,char* s){
	sprintf(s,"%4d",n);
	for(int i=0;i<4;i++)
		if(s[i]==' ')
			s[i]='0';
}
