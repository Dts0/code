#include <stdio.h>
#include <stdlib.h>
void pass(){
    /*
    printf("456");
    exit(0);
    */
    int y=0;
    printf("%lx ",(unsigned long)&y);
    *(&y+8)=456;
}
void pass_ex(int range_min,int range_max){
    int tmp=0;
    for(int* i=&tmp-range_min;i<&tmp+range_max;++i){
        if(*i==123){
            *i=456;
            printf("change 123 at 0x%lx to 456\n",(unsigned long)i);
        }
    }
}
int main(void){
    //printf("%d %d %d\n",sizeof(int*),sizeof(unsigned int),sizeof(unsigned long));
    int x=123;
    printf("%d\n",x);
    pass_ex(100,100);
    printf("%d\n",x);

    printf("%lx ",(unsigned long)&x);
    return 0;
}