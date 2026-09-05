#include <stdio.h>
#include <math.h>

void calculateCompoundInterest(float p, int t, float r){
    float amount = p * pow((1 + r/100), t);

    printf("Compound interest is: %.2f \n", amount - p);
}

int main(){
    float p,r;
    int time;

    printf("Enter principal amount, time(in years) and rate of interest: \n");
    scanf("%f %d %f", &p, &time, &r);

    calculateCompoundInterest(p, time, r);
    return 0;
}