#include <stdio.h>

int main(){
    int n = 5;
    for(int i = n; i>=1; i--){
        for(int k = 1; k<=i-1; k++){
            printf(" ");
        }
        for(int j = i; j<=n; j++){
            printf("%d ", j);
        }
        printf("\n");
    }

    return 0;
}