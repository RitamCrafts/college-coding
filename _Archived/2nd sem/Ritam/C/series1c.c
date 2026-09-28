//1+(1/1!)+(2/2!)+(3/3!)+...(n/n!)
#include <stdio.h>
int main(){
    int n,i;
    float fact=1,sum=1,denom,num;
    printf("Enter n:");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        fact=fact*i;
        denom=fact;
        num=i;
        sum=sum+num/denom;
    }
    printf("%.2f",sum);
    return 0;
}