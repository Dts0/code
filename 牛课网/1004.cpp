#include<iostream>
#include<string>
#define CON_UPPER 1
#define CON_LETTER 2
#define CON_CHAR 3
using namespace std;

int findSame(string s1,string s2,int th,int id,int start);
bool isUpper(char c);
bool isLowwer(char c);
bool isLetter(char c);
bool isChar(char c);
int main(){
	string s1,s2,s3,s4;
	string result="";
	cin>>s1>>s2>>s3>>s4;
	
	//cout<<s1.at(findSame(s1,s2,2,CON_CHAR));
	int i1=findSame(s1,s2,1,CON_UPPER,0);
	switch(s1.at(i1)){
		case 'A':result+="MON";break;
		case 'B':result+="TUE";break;
		case 'C':result+="WED";break;
		case 'D':result+="THU";break;
		case 'E':result+="FRI";break;
		case 'F':result+="SAT";break;
		case 'G':result+="SUN";break;
		default:break;
	}

	result+=" ";
	cout<<result;
	char c=s1.at(findSame(s1,s2,2,CON_CHAR,i1));
	int i2=0;
	if(c>='0'&&c<='9')
		i2=c-'0';
	if(c>='A'&&c<='N')
		i2=c-'A'+10;
	
	int i3=findSame(s3,s4,1,CON_LETTER,0);
	if(i2<10)
		cout<<0;
	cout<<i2<<":";
	if(i3<10)
		cout<<0;
	cout<<i3;
	
	
	return 0;
}
int findSame(string s1,string s2,int th,int id,int start){
	int count=0;
	int l1=s1.length(),l2=s2.length();
	int length=l1<l2?l1:l2;
	for(int i=start;i<length;i++)
		{
			bool con;
			switch(id){
				case CON_UPPER:con=(isUpper(s1.at(i)) && isUpper(s2.at(i)));
					break;
				case CON_CHAR:con=(isChar(s1.at(i)) && isChar(s2.at(i)));
					break;
				case CON_LETTER:con=(isLetter(s1.at(i)) && isLetter(s2.at(i)));
					break;
				default:con=false;
					break;
			}
			if(s1.at(i)==s2.at(i) && con){
				count++;
				if(count==th)
					return i;
			}
			}
	return -1;
}
bool isUpper(char c){
	if(c<='Z'&&c>='A')
		return true;
	return false;
}
bool isLowwer(char c){
	if(c<='z'&&c>='a')
		return true;
	return false;
}
bool isLetter(char c){
	if(isLowwer(c) || isUpper(c))
		return true;
	return false;
}
bool isChar(char c){
	if((c>='0'&&c<='9')||(c>='A'&&c<='N'))
		return true;
	return false;
}
