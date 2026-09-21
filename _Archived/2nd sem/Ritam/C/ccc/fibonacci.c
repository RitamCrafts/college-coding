#include <stdio.h>
int fibonacci(int);

int main(){
    int n=0;
    printf("Enter length:");
    scanf("%d",&n);
    int fibarr[n];
    int i=0;
    for(i=1;i<=n;i++){
        fibarr[i-1]=fibonacci(i);
    }
    for(i=0;i<n;i++){
        printf("%d ",fibarr[i]);
    }
}

int fibonacci(int n){
    if(n==1) return 0;
    if(n==2) return 1;
    return(fibonacci(n-2)+fibonacci(n-1));
}

// 0 1 1 2 3 5 8 13