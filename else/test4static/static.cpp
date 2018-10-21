#include<iostream>
#include"testmod.hpp"

using namespace std;

namespace test{
 	void testFunc(){
		static unsigned int value=0;
		cout<<++value<<endl;
	}

}

int main(){
	test::testFunc();
	test::testFunc();
	func();
	cout<<"mod_value in main "<<mod_value<<endl;

}
