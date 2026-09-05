#include <stdio.h>
#include <string.h>

int* bubbleSort(int* arr, int n);
int* selectionSort(int* arr, int n);
int* insertionSort(int* arr, int n);
int* sort(int* arr, int n);
void printIntArray(int* arr, int len, char* del);

int main(){
    int initArr[]={45,2,32,1,4,2,9,8};
    int lenArr=sizeof(initArr)/sizeof(initArr[0]);
    int arr[lenArr];

    memcpy(arr, initArr, lenArr * sizeof(int));
    printf("\nOriginal array: ");
    printIntArray(arr,lenArr," ");
    bubbleSort(arr,lenArr);
    printf("\nBubble sorted: ");
    printIntArray(arr,lenArr,", ");
    printf("\n");

    memcpy(arr, initArr, lenArr * sizeof(int));
    printf("\nOriginal array: ");
    printIntArray(arr,lenArr," ");
    insertionSort(arr,lenArr);
    printf("\nInsertion sorted: ");
    printIntArray(arr,lenArr,", ");
    printf("\n");

    memcpy(arr, initArr, lenArr * sizeof(int));
    printf("\nOriginal array: ");
    printIntArray(arr,lenArr," ");
    selectionSort(arr,lenArr);
    printf("\nSelection sorted: ");
    printIntArray(arr,lenArr,", ");
    printf("\n");

    memcpy(arr, initArr, lenArr * sizeof(int));
    printf("\nOriginal array: ");
    printIntArray(arr,lenArr," ");
    sort(arr,lenArr);
    printf("\nSorted: ");
    printIntArray(arr,lenArr,", ");
    printf("\n");
}

void printIntArray(int* arr, int len, char* del){
    int i=0;
    for(i=0;i<len;i++){
        printf("%d",arr[i]);
        if(i!=(len-1)) printf("%s",del);
    }
}


int* bubbleSort(int* arr, int n){
    int i,j,swapped,temp;
    for(i=0;i<n-1;i++){
        swapped=0;
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swapped=1;
            }
        }
        if(swapped==0)break;
    }
    return arr;
}

int* insertionSort(int* arr, int n){
    int i,j,key;
    for(i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    return arr;
}

int* selectionSort(int* arr, int n){
    int i,j;
    for(i=0;i<n-1;i++){
        int min_idx=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[min_idx]){
                min_idx=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[min_idx];
        arr[min_idx]=temp;
    }
    return arr;
}

int* sort(int* arr, int n){
    int i,j,minIdx,temp;
    for(i=0;i<n-1;i++){
        minIdx=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[minIdx]){
                minIdx=j;
            }
        }
        temp=arr[minIdx];
        arr[minIdx]=arr[i];
        arr[i]=temp;
        
    }
    return arr;
}