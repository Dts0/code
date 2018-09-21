#include<stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main(){
	string cmdString="cmdString";
	string intent="intent";
	string cmd="insert into command(cmdString) values('"+cmdString+"');"
	+"insert into relation(intent,command) values('"+intent
	+"',(select id from command where cmdString='"+cmdString+"'));";
	cout<<cmd<<endl<<cmdString<<1;
	int i=1000;
	ostringstream buf;
			buf<<i;
	cout<<cmdString+buf.str();
	return 0;
}

