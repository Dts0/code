#include<stdio.h>
//#include<iostream>
#include<stdlib.h>

typedef struct node{
	int value;
	struct node* next;
} list;
void init(list* l);
void add(list* l,int v);
int del(list* l,int v);//只删除第一个
list* find(list* l,int v);
void print(list* l);

int main(){
	list* l=(list*)malloc(sizeof(list));
	init(l);

	int num=0;
	scanf("%d",&num);
	int nums[num];
	for(int i=0;i<num;i++)
		{
			scanf("%d",&nums[i]);
			add(l,nums[i]);
		}

	print(l);
	list* r=find(l,4);
	if(r)
		//cout<<r->value;
		printf("\n%d\n",r->value);
	del(l,4);
	print(l);
	return 0;
}

void init(list* l){
	l->next=NULL;
	l->value=0;
}
void add(list* l,int v){
	list* newNote=(list*)malloc(sizeof(list));
	newNote->value=v;
	newNote->next=NULL;

	list* p=l;
	while(p->next)
		p=p->next;
	p->next=newNote;
}
list* find(list* l,int v){
	list* p=l;
	while(p->next){
		p=p->next;
		if(p->value==v)
			goto found;
	}
	return NULL;
	found:
	return p;
}
int del(list* l,int v){
	list* p=l;
	list* p0;
	while(p->next){
		p0=p;
		p=p->next;
		if(p->value==v)
			goto foundIt;
	}
	return -1;
	foundIt:
	p0->next=p->next;

	free(p);
	return 1;
}
void print(list* l){
	list* p=l;
	while(p->next)
	{
		p=p->next;
		printf("%d ",p->value);
	}


}
