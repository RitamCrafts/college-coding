#include <stdio.h>

int main(){
    int size;
    printf("Enter number of rows and columns of square matrix: ");
    scanf("%d", &size);
    int matx[size][size],diagonal[size];

    //input the matrix
    printf("Enter elements of matrix:\n");
    for(int i = 0; i<size; i++){
        printf("Row %d\n",i+1);
        for(int j = 0; j<size; j++){
            scanf("%d",&matx[i][j]);
        }
    }

    //find diagonal
    for(int i = 0; i<size; i++){
        diagonal[i]=matx[i][i];
    }

    printf("Diagonal of the matrix: ");
    for(int i = 0; i<size; i++){
        printf("%d ",diagonal[i]);
    }
    

}
