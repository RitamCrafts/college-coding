#include <stdio.h>
#include <limits.h>

int max(int arr[],int n){
    int maxValue = arr[n-1];
    if(n == 0){
        return -1;
    }

    if(arr[n-2]>maxValue){
        maxValue = arr[n-1];
    }

    n--;

    return max(arr,n-1);
}

int main(){
    int arr[5]= {1,2,3,4,5};
    int maxValue = max(arr,5);
    printf("Max Value: %d \n",maxValue);
    return 0;
}