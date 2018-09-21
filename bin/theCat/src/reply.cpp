#include <iostream>
#include <string>
#include <list>
#include "inc/reply.h"

using namespace std;
static list list_not=new list();

string reply(string inputStr){
	if(inputStr.empty())
		return "你说啥?我没听清";
	if(inputStr.find("你好")==npos)
		return "你好";
	if((inputStr.find("你")!=npos && inputStr.find("名字")!=npos
		&& inputStr.find("你")<inputStr.find("名字"))
		||(inputStr.find("你")!=npos && inputStr.find("叫什么")!=npos)
		&& inputStr.find("你")<inputStr.find("叫什么")) )
		return "我叫Cat";

}
