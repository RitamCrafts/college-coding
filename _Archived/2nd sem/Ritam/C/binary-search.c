#include <stdio.h>
int binarySearch(int n,int arr[],int sElement){
    int low=0,high=n-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==sElement){
            return mid;
        }
        else if(sElement<arr[mid]){
            high=mid-1;
        }
        else if(sElement>arr[mid]){
            low=mid+1;
        }
    }
    return -1;
}
int printIntArr(int arr[],int n){
    printf("%d", arr[0]);
    for(int i=1;i<n;i++){
        printf(",%d",arr[i]);
    }
    return 0;
}
int main(){
    int n,searchElement,i;
    printf("Enter size of array:");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter elements of array 1 by 1:\n");
    for(i=0;i<n;i++){
        printf("%d> ",(i+1));
        scanf("%d",&arr[i]);
    }
    printf("\nEntered sorted array= ");
    printIntArr(arr,n);
    printf("\n");
    printf("Enter element to be searched: ");
    scanf("%d",&searchElement);
    int res=binarySearch(n,arr,searchElement);
    printf("\n");
    if(res==(-1)){
        printf("Error finding %d\nPlease check if the element is present in the array and the array is sorted.\n",searchElement);
    }
    else{
        printf("The element %d was found in position %d of the array!\n",searchElement,(res+1));
    }
    return 0;
}
