#include <stdio.h>
int findGcd(int a,int b){
    int min=a<b?a:b;
    int gcd;
    for(int i=1;i<=min;i++){
        if ((a%i==0) && (b%i==0)){
            gcd=i;
        }
    }
    return gcd;
}
int findLcm(int a, int b){
    int gcd=findGcd(a,b);
    int lcm=a*b/gcd;
    return lcm;
}
int main(){
    int a,b;
    printf("Enter 1st number: ");
    scanf("%d",&a);
    printf("Enter 2st number: ");
    scanf("%d",&b);
    int gcd=findGcd(a,b);
    printf("Gcd=%d\n",gcd);
    int lcm=findLcm(a,b);
    printf("Lcm=%d",lcm);
    return 0;
}