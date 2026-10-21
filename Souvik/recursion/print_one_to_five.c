#include <stdio.h>

void printNumber(int n){
    if(n == 0){
        return;
    }

    printNumber(n-1);
    printf("%d \n",n);
}

int main(){
    int n;
    printf("Enter Number: ");
    scanf("%d",&n);
    printNumber(n);
    return 0;
}