#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;

int main(int argc,char** argv){
	if(argc==1){
		time_t startTime;
		time(&startTime);
		system(string("./test.out 20000").c_str());
		time_t endTime;
		time(&endTime);
		cout<<"startTime:"<<startTime<<endl;
		cout<<"endTime:"<<endTime<<endl;
		cout<<"time:"<<endTime-startTime<<endl;
		return 0;
	}
	for(long i=stoi(argv[1]);i>0;--i){
		//cout<<i<<endl;
	}
	return 0;
}
