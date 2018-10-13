#include<iostream>
#include<math.h>

using namespace std;

double sin_x(double x,int n=10){
	while(x>M_PI*2){//如果大于2PI或者小于0，转换到0到2PI范围
		x-=M_PI*2;
		//cout<<"-2PI,"<<x<<endl;
	}
	while(x<0){
		x+=M_PI*2;
		//cout<<"+2PI,"<<x<<endl;
	}
	double ret=x,val=x,pw,ft;
    int i=2;
    while(fabs(val)>=1e-4 && i<n)//精度要求，可以修改
    {
        val=-x*x*val/((2*i-1)*(i*2-2));//val*(-x^2/((2n-1)*(2n-2))
		cout<<val<<endl;
        ret=ret+val;
        i++;
    }
	return ret;
}


int main(){
	cout<<"求sin(x),输入x,n"<<endl;
	int x,n;
	cin>>x>>n;
	cout<<sin_x(x,n)<<endl;
	cout<<sin(x)<<endl;
	return 0;
}
