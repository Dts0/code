#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

struct stu{
	int id;
	char name[10];
	int Mathematics;
	int Chinese;
	int English;
};

int main(){
	struct stu student;
	FILE *fp;

	printf("学号\n");
	scanf("%d",&student.id);
	getchar();

	printf("姓名\n");
	gets(student.name);
	fflush(stdin);

	printf("数学\n");
	scanf("%d",&student.Mathematics);
	getchar();
	printf("语文\n");
	scanf("%d",&student.Chinese);
	getchar();
	printf("英语\n");
	scanf("%d",&student.English);
	getchar();

	fp=fopen("student.dat","ab+");
	if(fp==NULL){
		printf("打开文件失败");
		exit(0);
	}
	fwrite(&student,sizeof(struct stu),1,fp);

	fclose(fp);
	return 0;
}
