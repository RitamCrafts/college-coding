#include <stdio.h>
void main(){
    int m,n;
    printf("Setting values of m=5 and n=10\n");
    printf("\nPre/Post Increment\n");
    m=5;
    n=10;
    int preIncr, postIncr;
    printf("m=%d, n=%d\n",m,n);
    preIncr=++m;
    postIncr=n++;
    printf("Increment done\n");
    printf("m=%d, n=%d\n",m,n);
    printf("preIncr=%d, postIncr=%d\n",preIncr,postIncr);

    printf("\nResetting value of m and n\n");

    printf("\nPre/Post Decrement\n");
    m=5;
    n=10;
    int preDecr, postDecr;
    printf("m=%d, n=%d\n",m,n);
    preDecr=--m;
    postDecr=n--;
    printf("Decrement done\n");
    printf("m=%d, n=%d\n",m,n);
    printf("preDecr=%d, postDecr=%d\n",preDecr,postDecr);
}