#include <stdlib.h>
#include<stdio.h>
//#include<malloc.h>
//#include<errno.h>

//static int line = 0;
int size = 0;
void head();
void increase();
void _select();
void condition();
int main()
{
//head();
//_select();
head();
return 0;

}
/*
学生类
*/
struct stu
{
int id; //学生学号
char name[10];	//学生名字
int Mathematics; //数学成绩
int Chinese; //语文成绩
int English; //英语成绩
};
void head()
{
int num;
printf("----------------欢迎使用学生管理系统----------------------\n");
printf("1:查询所有学生信息\n");
printf("2:按条件查询学生信息\n");
printf("3:添加学生信息\n");
printf("4:删除学生信息\n");
printf("5:退出学生管理系统\n");
do{
printf("\n");
printf("请输入:");
scanf("%d",&num);
getchar();
switch (num)
{
case 1:
_select();
break;
case 2:
printf("测试语句2\n");
break;
case 3:
increase();
break;
case 4:
printf("测试语句4\n");
break;
case 5:
printf("退出程序！");
break;
default:
printf("输入错误！请重新输入\n");
break;
}



} while (num != 5);
}
/*
添加
*/
void increase()
{
struct stu student;
FILE *fp;
int err;
printf("请输入学生学号\n");
scanf("%d", &student.id);
getchar();
printf("请输入学生姓名\n");
gets(student.name);
fflush(stdin);	//防止回车作为输入
printf("请输入学生数学成绩\n");
scanf("%d", &student.Mathematics);
getchar();
printf("请输入学生语文成绩\n");
scanf("%d", &student.Chinese);
getchar();
printf("请输入学生英语成绩\n");
scanf("%d", &student.English);
getchar();
//student = {student.id,student.name[10],student.Mathematics,student.Chinese,student.English};
//struct stu student = { 1,"zxxx",78,69,32 };
fp = fopen("student.dat", "ab+");
if (fp==0)
{
printf("打开文件失败");
exit(0);
}
//fwrite(&student, sizeof(struct stu), 1, fp); //向文件中写入数据
if (fwrite(&student, sizeof(struct stu), 1, fp)<1)
{
printf("文件写入失败!\n");
}
else
{
printf("文件写入成功！\n");
++size;
}
fclose(fp);
}
void _select()
{
FILE *fp;
int err;
fp = fopen("student.dat", "rb");
int i = 1;
long count;
if (fp== 0)
{
printf("文件打开失败！\n");
exit(0);
}
struct stu student[size];
for (int i = 0; i< size; ++i) {
fgets((char *)&student[i], sizeof(struct stu) + 1, fp);
}
fclose(fp);

for (int i = 0; i < size; ++i) {
printf("%d,%s,%d,%d,%d\n", student[i].id, student[i].name,
student[i].Mathematics, student[i].Chinese, student[i].English);
}
}
void condition()
{
FILE *fp;
int err;
struct stu student;
fp = fopen("student.dat", "rb");
if (fp==0)
{
printf("文件打开失败！\n");
exit(0);
}
fread(&student,sizeof(struct stu),1,fp);

}
