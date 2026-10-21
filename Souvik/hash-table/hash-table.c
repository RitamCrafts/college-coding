#include <stdio.h>


int main(){
    int n;
    printf("Enter Size of Array: ");
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i<n; i++){
        printf("Enter Number %d: ",i+1);
        scanf("%d",&arr[i]);
    }

    int hash[6] = {0};
    for(int i = 0; i<n; i++){
        hash[arr[i]]++;
    }

    for(int i = 0; i<n; i++){
        printf("%d - %d \n",arr[i],hash[i]);
    }


    return 0;
}