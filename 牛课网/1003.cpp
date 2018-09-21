#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int value;
	struct node* next;
} list;
void init(list* l);
void add(list* l,int v);
int getPrimes(list* result,int M,int N);
int getPrimeWithTh(int th);
bool isPrime(int n);
int main(){
   int M,N;
   scanf("%d",&M);
   scanf("%d",&N);
   
   list* result=(list*)malloc(sizeof(list));
   init(result);
   
   int m=getPrimeWithTh(M);
   int n=getPrimeWithTh(N);
   int count=getPrimes(result,m,n);
   
   list* p=result;
   int i=1;
	while(p->next)
	{	
		p=p->next;
		printf("%d",p->value);
		//cout<<p->value<<" "<<i;
       if(i%10==0)
           printf("\n");
       else if(p->next) printf(" ");
       i++;
	}
   
   return 0;
}
int getPrimes(list* result,int M,int N){
	int count=0;
    for(int i=M;i<=N;i++){
        if(isPrime(i)){
            add(result,i);
            count++;
        }
    }
    return count;
}
int getPrimeWithTh(int th){
	//if(th==10000)
	//	return 104729;
	int count=0;
	for(int i=2;;i++){
		if(isPrime(i)){
			count++;
		}
		if(count==th)
			return i;
	}
	return -1;
}
bool isPrime(int n){
    for(int i=2;i*i<=n;i++)
        if(n%i==0)
            return false;
    return true;
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

