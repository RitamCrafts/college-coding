//1+((x^1)/1!)+((x^2)/2!)+((x^3)/3!)+...((x^n)/n!)
#include <stdio.h>
#include <math.h>
int main(){
    int n,i;
    float fact=1,sum=1,denom,num,x;
    printf("Enter x:");
    scanf("%f",&x);
    printf("Enter n:");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        fact=fact*i;
        denom=fact;
        num=pow(x,i);
        sum=sum+num/denom;
    }
    printf("%.2f",sum);
    return 0;
}