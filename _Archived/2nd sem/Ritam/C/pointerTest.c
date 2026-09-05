#include <stdio.h>

int main(){
    int a=100;
    int *p=&a;
    printf("%d\t%p",a,*p);
    return 0;
}