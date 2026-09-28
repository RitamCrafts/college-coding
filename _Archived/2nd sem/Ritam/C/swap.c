#include <stdio.h>

void swap(int *,int *);
int  main(){
    int a = 5;
    int b = 7;
    printf("a=%d\tb=%d",a,b);
    swap(&a,&b);
    printf("\nAfter swap \na=%d\tb=%d",a,b);
    return 0;
}
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}