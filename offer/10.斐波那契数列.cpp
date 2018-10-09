#include<iostream>
#include<time.h>
/*		0,n=0
f(n)=	1,n=1
		f(n-1)+f(n-2)
*/
using namespace std;

long long Fibonacci_Recursive(unsigned int n){
	if(n==0 || n==1)
		return n;
	return Fibonacci_Recursive(n-1)+Fibonacci_Recursive(n-2);
}
long long Fibonacci_for(unsigned int n){
	if(n==0 || n==1)
		return n;

	long long Fibo_first=0,Fibo_second=1;
	long long result=0;
	for(int i=2;i<=n;++i){//从第3个开始加
		result=Fibo_first+Fibo_second;
		Fibo_first=Fibo_second;
		Fibo_second=result;
	}
	return result;
}

int main(){
	for(unsigned int n=0;n<100;++n){
	cout<<"斐波那契数列第"<<n<<"位："<<endl;
	clock_t startTime=clock();
	long long resultFor = Fibonacci_for(n);
	clock_t endFor=clock();
	long long resultRec = Fibonacci_Recursive(n);
	clock_t endRec=clock();
	cout<<"\t循环的结果为："<<resultFor<<"，耗时"<<endFor-startTime<<"us"<<endl;
	cout<<"\t递归的结果为："<<resultRec<<"，耗时"<<endRec-endFor<<"us"<<endl;
	}
	return 0;
}
