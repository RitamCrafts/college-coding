#include <stdio.h>

int main(){
    int rows,cols;
    printf("Enter number of rows and columns:\n");
    scanf("%d %d", &rows, &cols);
    int a[rows][cols],b[rows][cols],sum[rows][cols];

    printf("Enter elements of 1st matrix:\n");
    for(int i = 0; i<rows; i++){
        printf("Row %d\n",i+1);
        for(int j = 0; j<cols; j++){
            scanf("%d",&a[i][j]);
        }
    }

    printf("\nEnter elements of 2nd matrix:\n");
    for(int i =0; i<rows; i++){
        printf("Row %d\n",i+1);
        for(int j = 0; j<cols; j++){
            scanf("%d",&b[i][j]);
        }
    }

    printf("\nSum of two matrices: \n");
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){ 
            sum[i][j] = a[i][j] + b[i][j];
            printf("%d\t", sum[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}