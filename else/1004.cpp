 #include<iostream>
 #include<stdio.h>
 #include<string>
 #include<sstream>
using namespace std;
class student
{
public:
	string name;
	string id;
	int score;
	void init(string n,string i,int s)
	{
		name=n;
		id=i;
		score=s;
	}
	student()
	{
		name="";
		id="";
		score=0;
	}
};
void fillStudents(student* students,int num);
int findMax(student* students,int length);
int findMin(student* students,int length); 

int main()
{
	int num=0;
	cin>>num;
	//cout<<num<<endl;
	student students[num];
	
	fillStudents(students,num);
	
	int indexMax=findMax(students,num);
	int indexMin=findMin(students,num);
	
	cout<<students[indexMax].name<<" "<<students[indexMax].id<<endl;
	cout<<students[indexMin].name<<" "<<students[indexMin].id<<endl;
	
	while(1);
	return 0;
}

void fillStudents(student* students,int num)//这个真的是迷,用C++的流写了半天，忽然发现用scanf直接解决
{
	for(int j=0;j<num;j++)
	{
		char name[10],id[10];
		int score;
		scanf("%s %s %d",name,id,&score);
		students[j].init(string(name),string(id),score);
		//cout<<name<<":"<<id<<":"<<score<<" "<<j<<endl;
	}
}
int findMax(student* students,int length)
{
	int index=0;
	int max=0;
	for(int i=0;i<length;i++)
	{
		if(students[i].score>max)
		{
			max=students[i].score;
			index=i;
		}
	}
	return index;
}
int findMin(student* students,int length)
{
	int index=0;
	int min=100;
	for(int i=0;i<length;i++)
	{
		if(students[i].score<min)
		{
			min=students[i].score;
			index=i;
		}
	}
	return index;
}

