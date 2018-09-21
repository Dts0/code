#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}
/* 你的代码将被嵌在这里 */
List Read()
{
    int n;
    scanf("%d",&n);
    List L=(List)malloc(sizeof(PtrToNode));   ///申请一个头结点
    L->Next = NULL;        ///头指针为空
    if(n)    ///当n不是0时
    {
        List r=L;     ///r是一个中间变量的节点
        for(int i=0;i<n;i++) 
        {
            List p=(List)malloc(sizeof(struct Node));
            scanf("%d",&(p->Data));    ///尾插法
            r->Next = p;
            r = p;
        }
        r->Next = NULL;         
    }
    return L;
}

void Print( List L )
{
   List p=L->Next;
   if(p)
   {
       List r;
       r = L;
       while(r->Next)
       {
           r = r->Next;
           printf("%d ",r->Data);
       }
   }
   else
   {
       printf("NULL");
   }
   printf("\n");
}

List Merge( List L1, List L2 )   ///合并函数  重点要写的函数！
{
    List list1,list2,p,L;
    L = (List)malloc(sizeof(struct Node));
    list1=L1->Next;
    list2=L2->Next;
    p = L;
    while(list1 && list2)
    {
        if(list1->Data <= list2->Data)
        {
            p->Next = list1;
            p = list1;
            list1 = list1->Next;
        }
        else
        {
            p->Next = list2;
            p = list2;
            list2 = list2->Next;
        }
    }
    p->Next = list1 ? list1 : list2;
    L1->Next = NULL;
    L2->Next = NULL;
    return L;
}

