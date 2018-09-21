#include<iostream>
//#include<math.h>
#include <iomanip>
using namespace std;
int main(){
/*
	double num=100*sqrt(2.0);
	cout<<"default:\t"<<num<<"\n"
		<<"scientific:\t"<<scientific<<num<<"\n"
		<<"fixed decimal:\t"<<fixed<<num<<"\n"
		<<"hexfloat:\t"<<hexfloat<<num<<"\n"
		<<"use default:\t"<<defaultfloat<<num<<"\n"
		<<"showpos:\t"<<showpos<<num<<"\n";

	cout<<endl<<noshowpos;
	cout<<"default:\t"<<10.0<<endl;
	cout<<"noshowpoint:\t"<<noshowpoint<<10.0<<"\n";
	cout<<"showpoint:\t"<<showpoint<<10.0<<"\n";
*/

	int i=-16;
	double d=3.14159;
	//补白第一列，使用输出中最小12个位置
	cout<<"i:"<<setw(12)<<i<<"next rol"<<"\n"
		<<"d:"<<setw(12)<<d<<"next rol"<<"\n";

	//左对齐
	cout<<left
		<<"i:"<<setw(12)<<i<<"next rol"<<"\n"
		<<"d:"<<setw(12)<<d<<"next rol"<<"\n";

	//右对齐
	cout<<right
		<<"i:"<<setw(12)<<i<<"next rol"<<"\n"
		<<"d:"<<setw(12)<<d<<"next rol"<<"\n";

	//补在符号和值之间
	cout<<internal
		<<"i:"<<setw(12)<<i<<"next rol"<<"\n"
		<<"d:"<<setw(12)<<d<<"next rol"<<"\n";

	//使用#作为补白字符
	cout<<setfill('#')
		<<"i:"<<setw(12)<<i<<"next rol"<<"\n"
		<<"d:"<<setw(12)<<d<<"next rol"<<"\n"
		<<setfill(' ');
	return 0;
}
