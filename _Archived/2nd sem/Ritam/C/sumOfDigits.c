#include <stdio.h>
int main(){
    int rem,sum=0;
    long n, temp;
    printf("Enter a no.: ");
    scanf("%ld",&n);
    temp=n;
    while(temp>0){
        rem=temp%10;
        sum=sum+rem;
        temp=temp/10;
    }
    printf("Sum of digits= %d",sum);
    return 0;
}