#include <stdio.h>
#include <string.h>
int testUP(int*);
int main(){
    int a[3]={1,2,3};
    char c[20]="hello";
    int *p=a;
    for(int i=0;i<3;i++){
        printf("%d %d   %d  %p  %p\n",a[i],*(p+i),(p+i),(p+i),(a+i));
    }
    printf("%d\n",(sizeof(a)/sizeof(a[0])));
    printf("%d\n",(sizeof(a)));
    printf("%d\n\n",(sizeof(c)));
    char s[10];
    printf("%s\n",s);
    strcpy(s,c);
    printf("%s %s\n",s,c);
    printf("%d",testUP(a));
}
int testUP(int a[]){
    return a[0];
}