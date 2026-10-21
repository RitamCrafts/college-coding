#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 3

bool checkKnowing(int arr[MAX_SIZE][MAX_SIZE], int c){

    for(int i = 0; i < MAX_SIZE; i++){

        if(i == c)
            continue;

        if(arr[c][i] != 0 || arr[i][c] != 1){
            return false;
        }
    }

    return true;
}

int main(){
    int arr[MAX_SIZE][MAX_SIZE];
    for(int i = 0; i<MAX_SIZE; i++){
        for(int j = 0; j<MAX_SIZE; j++){
            printf("Enter Value: [%d][%d]: ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }

    for(int i = 0; i<MAX_SIZE; i++){
        if(checkKnowing(arr,i) == true){
            printf("%d \n",1);
            break;
        }
    }

    

    
    return 0;
}