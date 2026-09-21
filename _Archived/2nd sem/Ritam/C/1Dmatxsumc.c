#include <stdio.h>

int main() {

    int n;

    printf("Enter size: ");
    scanf("%d", &n);

    int a[n], b[n], sum[n];

    printf("Enter first 1D matrix:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    printf("\nEnter second 1D matrix:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &b[i]);
    }

    for(int i = 0; i < n; i++){
        sum[i] = a[i] + b[i];
    }

    printf("\nSum of the 1D matrices:\n");
    for(int i = 0; i < n; i++){
        printf("%d\n", sum[i]);
    }

    return 0;
}