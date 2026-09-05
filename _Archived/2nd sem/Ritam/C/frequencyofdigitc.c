#include <stdio.h>
int main(){
    int rem;
    long long n,temp;
    int freq[10]={0};
    printf("Enter a no.: ");
    scanf("%lld",&n);
    temp=n;
    while(temp>0){
        rem=temp%10;
        temp=temp/10;
        freq[rem]=freq[rem]+1;
    }
    
    printf("Digit\tfrequency\n");
    for(int i=0;i<10;i++){
        if(freq[i]!=0){
            printf("%d\t%d\n",i,freq[i]);
        }
    }
    return 0;
}