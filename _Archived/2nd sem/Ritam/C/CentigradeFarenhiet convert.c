#include <stdio.h>
int main(){
    float c,f;
    printf("Enter temperature in centigrade C:");
    scanf("%f",&c);
    f=c*9/5+32;
    printf("Temperature in farenheit: %.2f degree Farenheit.",f);
    return 0;
}