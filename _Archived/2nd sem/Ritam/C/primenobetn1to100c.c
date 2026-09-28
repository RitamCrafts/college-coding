#include <stdio.h>
int main(){
    printf("Prime numbers between 1 to 100:\n");
    for(int i=1;i<=100;i++){
        if(i == 1) continue;
        int flag=1;
        for(int j=2;j<=i/2;j++){
            if(i%j==0)
            {
                flag=0;
                break;
            }
        }
        if (flag==1)printf("%d ",i);
    }
}