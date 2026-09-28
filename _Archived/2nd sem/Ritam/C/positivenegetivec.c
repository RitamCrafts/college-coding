#include <stdio.h>
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    if(n>0){
        printf("%d is positive.",n);
    }
    else if(n<0){
        printf("%d is negetive.",n);
    }
    else if(n==0){
        printf("%d is zero.",n);
    }
}