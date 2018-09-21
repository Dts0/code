#include <iostream>
#include <math.h>

const int x_max=10,y_max=100;
using namespace std;

int main(){
	bool points[x_max][y_max];

	for(int i=0;i<x_max;++i)
	for(int j=0;j<y_max;++j)
	points[i][j]=false;

	for(int x=0;x<x_max;++x){
		int y=pow(x,2);//公式放在这*********************************************
		points[x][y]=true;
		cout<<"("<<x<<","<<y<<") ";
	}
	cout<<endl;
	for(int i=0;i<y_max;++i)
		cout<<" ";
	cout<<"--> Y轴"<<endl;
	for(int i=0;i<x_max;++i){
		for(int j=0;j<y_max;j++)
			if(points[i][j])
				cout<<"*";
			else cout<<" ";
		cout<<endl;
	}
	cout<<"| X轴"<<endl<<"V"<<endl;
}
