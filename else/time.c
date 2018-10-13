#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	//setenv("TZ","Asia/Shanghai",1);
	while(1){
		time_t now_1970=time(NULL);//从1970到现在的秒数
		struct tm tm_now=*localtime(&now_1970);//现在的年月日等
		/*//测试用
		tm_now.tm_year=78;
		tm_now.tm_mon=1;
		tm_now.tm_mday=1;
		tm_now.tm_hour=0;
		tm_now.tm_min=0;
		tm_now.tm_sec=2;
		*/

		int year=tm_now.tm_year-78;
		int month=tm_now.tm_mon-0;//注意mon为从0到11
		int day=tm_now.tm_mday-1;
		int hour=tm_now.tm_hour;
		int minute=tm_now.tm_min;
		int second=tm_now.tm_sec;

		printf("无协成立%d年%d月%d日%d时%d分%d秒\n",year,month,day,hour,minute,second);

		while(time(NULL)==now_1970);
	}
}
