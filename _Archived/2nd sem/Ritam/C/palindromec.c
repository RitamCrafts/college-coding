#include <stdio.h>
int main(){
    int n,temp,nrev,rem;
    printf("Enter a no.: ");
    scanf("%d",&n);
    //reverse the no. below
    nrev=0;
    temp=n;
    while(temp>0){
        rem=temp%10;
        nrev=nrev*10+rem;
        temp=temp/10;
    }
    printf((nrev==n)?"Palindrome":"Not Palindrome");
    return 0;
}