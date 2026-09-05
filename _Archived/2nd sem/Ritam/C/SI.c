#include <stdio.h>
int main(){
    int p,r,t;
    float si;
    printf("Enter principal,rate and time:\n");
    scanf("%d%d%d",&p,&r,&t);
    si=(p*r*t)/100;
    printf("Simple Interest=%.2f",si);
    return 0;
}