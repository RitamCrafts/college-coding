#include <stdio.h>
#include "factorial.h"
int main(){
    int a=1;
    int b=4;
    int c=a+b;
    int f=factorial(c);
    printf("Sum=%d\nFactorial of %d=%d\n",c,c,f);
    getchar();
    return 0;
}