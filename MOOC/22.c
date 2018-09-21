#include<stdio.h>
#include<math.h>
#define inf 9999999
int n,d,flag=0,exist=0,newp;
int mark[101];
int path[101];
int distance[101];
struct node{
	int x;
	int y;
}stu[101];
double dis(int x,int y){
	return sqrt(x*x+y*y);
}
int canjump(int x1,int y1,int x2,int y2){
	if(sqrt(pow((x1-x2),2)+pow(y1-y2,2))<=d){
		return 1;
	}
	else{
		return 0;
	}
}
void init(){
	int i;
	flag=0;
	for(i=0;i<n;i++){
		mark[i]=0;
		path[i]=-1;
		distance[i]=inf;
	}
}
void dijkstra(int s){
	mark[s]=1;
	distance[s]=1;//从第一跳开始 ！ 
	path[s]=-2;
	int i;
	newp=s;
	while(1){
		if(50-abs(stu[newp].x)<=d||50-abs(stu[newp].y)<=d){
			distance[newp]++;//还要跳到岸上！ 
			flag=1;exist=1;break;
		}
		for(i=0;i<n;i++){
			if(mark[i]==0&&canjump(stu[newp].x,stu[newp].y,stu[i].x,stu[i].y)){
				if(distance[newp]+1<distance[i]){
					distance[i]=distance[newp]+1;
					path[i]=newp;
				}
			}
		}
		int min=inf;
		for(i=0;i<n;i++){
			if(mark[i]==0&&distance[i]<inf){
				if(distance[i]<min){
					min=distance[i];
					newp=i;
				}				
			}
		}
		mark[newp]=1;
		if(min==inf){
			break;
		}
	}
}
int main(){
	int i;
	scanf("%d %d",&n,&d);
	for(i=0;i<n;i++){
		scanf("%d %d",&stu[i].x,&stu[i].y);
	}
	if(d>=50-7.5){
		printf("1\n");return 0;//最小N，一步跳到岸 错了这个点 
	}
	int firstjump[n];//第一跳下标 
	int numfirst=0;
	for(i=0;i<n;i++){
		if(d+7.5>=dis(stu[i].x,stu[i].y)){
			firstjump[numfirst++]=i;
		}
	}
	int min=inf,index; 
	int store[n],cou=0;
	for(i=0;i<numfirst;i++){
		init();
		dijkstra(firstjump[i]); 
		if(flag){//找到路径 
			if(distance[newp]<min){
				min=distance[newp];
				cou=0;
				store[cou++]=firstjump[i];
			}
			else if(distance[newp]==min){
				store[cou++]=firstjump[i];
			}
		}
	}
	if(exist==0){
		printf("0");return 0;
	}
	min=inf;
	int indexmin;//如果最短路径相同，则距离源点最近的点唯一（题目保证） 
	for(i=0;i<cou;i++){
		int index=store[i];
		if(min>dis(stu[index].x,stu[index].y)-7.5){
			min=dis(stu[index].x,stu[index].y)-7.5;
			indexmin=store[i];
		}
	} 
	init();//别忘了初始化 !!!!
	dijkstra(indexmin); 
	printf("%d\n",distance[newp]);
	cou=0;
	while(1){
		store[cou++]=newp;
		newp=path[newp];
		if(newp==-2){
			break;
		}
	}
	for(i=cou-1;i>=0;i--){
		printf("%d %d\n",stu[store[i]].x,stu[store[i]].y);
	}
} 
