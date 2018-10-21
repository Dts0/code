#include"testmod.hpp"
#include<iostream>

/*static*/ void func(){
	mod_value=100;
	std::cout<<"this is the //* static *// func in test mod"<<std::endl;
	std::cout<<"mod_value is testmod "<<mod_value<<std::endl;
}
