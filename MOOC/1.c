#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}

/* 你的代码将被嵌在这里 */
Position BinarySearch( List L, ElementType X ){
	Position left;  
    Position right;  
    if (L->Last) {  
        left = 1;  
        right = L->Last;   
        while(left <= right) {  
            if (X == L->Data[(left + right) / 2])  
                return (left + right) / 2;  
            else {  
                if (X < L->Data[(left + right) / 2])  
                    right = (left + right) / 2 - 1;  
                else   
                    left = (left + right) / 2 + 1;  
            }  
        }  
    }  
	return NotFound;
	
}
List ReadInput(){
	List L;
	Position num;
	L=(List)malloc(sizeof(struct LNode));
	scanf("%d",&num);
	L->Last=num;
	for(Position i=1;i<=num;i++)
		scanf("%d",&L->Data[i]);
	
	return L;
}

