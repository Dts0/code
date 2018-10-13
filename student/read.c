#include<stdio.h>
#include<stdlib.h>

struct stu{
	int id;
	char name[10];
	int Mathematics;
	int Chinese;
	int English;
};


int main(){
	FILE *fp;
	fp=fopen("student.dat","ab+");
	const int size=5;
	struct stu student[size];
	for(int i=0;i<size;++i){
		fgets(&student[i],sizeof(struct stu)+1,fp);
	}
	fclose(fp);

	for(int i=0;i<size;++i){
		printf("%d,%s,%d,%d,%d\n",student[i].id,student[i].name,
			student[i].Mathematics,student[i].Chinese,student[i].English);
	}
	return 0;
}
