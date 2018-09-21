#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct student{
	int id;
	int ability;
	int political;
} student;
void sort(student* s,int num);
void classify(student* students,student* s1,student* s2,student* s3,student* s4,
				int num,int L,int H,int* num1,int* num2,int* num3,int* num4);
int main(){
	int N=0,L=0,H=0;
	cin>>N;
	cin>>L;
	cin>>H;
	student students[N];
	student both[N],LPolitical[N],political[N],LElse[N];
	int numBoth=0,numLPolitical=0,numPolitical=0,numLElse=0;
	for(int i=0;i<N;i++)
		cin>>students[i].id>>students[i].political>>students[i].ability;
	classify(students,both,LPolitical,political,LElse,N,L,H,
		&numBoth,&numLPolitical,&numPolitical,&numLElse);
	sort(both,numBoth);
	sort(LPolitical,numLPolitical);
	sort(political,numPolitical);
	sort(LElse,numLElse);
	cout<<numBoth+numLPolitical+numPolitical+numLElse<<endl;
	//cout<<"\n";
	for(int i=0;i<numBoth;i++)
		cout<<both[i].id<<" "<<both[i].political<<" "<<both[i].ability<<endl;
	//cout<<"\n";
	for(int i=0;i<numPolitical;i++)
		cout<<political[i].id<<" "<<political[i].political<<" "<<political[i].ability<<endl;
	//cout<<"\n";
	for(int i=0;i<numLPolitical;i++)
		cout<<LPolitical[i].id<<" "<<LPolitical[i].political<<" "<<LPolitical[i].ability<<endl;
	//cout<<"\n";
	for(int i=0;i<numLElse;i++){
		cout<<LElse[i].id<<" "<<LElse[i].political<<" "<<LElse[i].ability;
		 if(i!=numLElse-1)
		 	cout<<endl;
	}
	return 0;
}
void classify(student* students,student* s1,student* s2,student* s3,student* s4,
				int num,int L,int H,int* num1,int* num2,int* num3,int* num4){
	for(int i=0;i<num;i++){
		if(students[i].ability>=H && students[i].political>=H){
			s1[*num1]=students[i];
			(*num1)++;
		} else if (students[i].ability>=L && students[i].political>=H){
				s3[*num3]=students[i];
				(*num3)++;
		} else if(students[i].ability>=L && students[i].political>=L
				&& students[i].political>students[i].ability){
				s2[*num2]=students[i];
				(*num2)++;
		} else if(students[i].ability>=L && students[i].political>=L){
				s4[*num4]=students[i];
				(*num4)++;
		}
	}

}
void sort(student* s,int num){
	student buf;
	for(int i=0;i<num;i++)
		for(int j=0;j<i;j++){
			if(s[i].ability+s[i].political>s[j].ability+s[j].political){
				buf=s[i];
				s[i]=s[j];
				s[j]=buf;
			} else if(s[i].ability+s[i].political==s[j].ability+s[j].political
				&& s[i].political>s[j].political){
				buf=s[i];
				s[i]=s[j];
				s[j]=buf;
			} else if(s[i].ability+s[i].political==s[j].ability+s[j].political
				&& s[i].political==s[j].political &&s[i].id<s[j].id){
				buf=s[i];
				s[i]=s[j];
				s[j]=buf;
				}
		}
}
