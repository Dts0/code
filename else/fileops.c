#include<stdio.h>

int main(){
    FILE* tty;
    tty = fopen("./test","w");
    fputs("hi",tty);
    fclose(tty);
}
