#include<iostream>
#include<vector>
#include<string>
#include<time.h>

using namespace std;

void showHelp();
void unknowOption(string op);
void optionLackVal(string op);
void showVersion();
time_t timeTest(string doSomething,int times=1);

int main(int argc,char** argv){
	if(argc==1){
		showHelp();
		return 0;
	}
	vector<string> execFileNames;
	for(int argCnt=1;argCnt<argc;++argCnt){
		string argStr(argv[argCnt]);
		if(argStr[0]=='-'){
			if(argStr=="-h"){
				showHelp();
				return 0;
			}
			if(argStr=="-v"){
				showVersion();
				return 0;
			}
				unknowOption(argStr);
				showHelp();
				return 0;
		} else {
			execFileNames.push_back(argStr);
		}
	}
	for(auto file : execFileNames){
		time_t time=0;
		int runTimes=1;
		time=timeTest(string("./").append(file),runTimes);
		while(time<=1){//如果实际测算值过小，则多次运行取平均值
			cout<<"实际运行时间过小,time:"<<time
				<<"ms,正在增加运行次数以获得更精确运行时间,"
				<<"当前运行次数:"<<runTimes*10<<endl;
			runTimes=runTimes * 10;
			time=timeTest(string("./").append(file),runTimes);
		}
		cout<<runTimes<<"次"<<file<<"执行时间:"<<time<<"秒,平均值:"<<time*1.0/runTimes<<"秒"<<endl;
	}

	return 0;
}

time_t timeTest(string doSomething,int times){
	time_t startTime;
	time(&startTime);
	for(int i=0;i<times;++i){
		system(doSomething.c_str());
	}
	time_t endTime;
	time(&endTime);
	return endTime-startTime;
}

void showHelp(){
	cout<<"用法：commandTimer [选项]... [要测试运行时间de命令]... \n"
		<<"\t-h\t打印帮助并退出\n"
		<<"\t-v\t打印版本信息并退出\n";
	cout<<"您可以像这样使用:\n"
		<<"commandTimer \"test.out 20000\"\n";
}
void unknowOption(string op){
	cout<<"未知的选项\""<<op<<"\""<<endl;
}
void showVersion(){
	cout<<"commandTimer:1.0.0\n"
		<<"Copyright (C) DTS\n"
		<<"License MIT\n"
		<<"Written by DTS\n"
		<<"my website: <http://www.dreamoftime0.com/>"
		<<endl;
}
