#include <stdio.h>
#include <string.h>

void main(){
    printf("Enter first name:");
    char str1[20]="";
    fgets(str1,sizeof(str1),stdin);
    str1[strcspn(str1,"\n")]='\0';

    printf("Enter last name:");
    char str2[20]="";
    fgets(str2,sizeof(str2),stdin);
    str2[strcspn(str2,"\n")]='\0';

    char str3[20]="";
    char *p1=str1;
    char *p2=str2;
    if(*p1>=97) *p1-=32;
    if(*p2>=97) *p2-=32;
    int i;
    i=1;
    while(*(p1+i)!='\0'){
        if(*(p1+i)<=90) *(p1+i)+=32;
        i++;
    }
    i=1;
    while(*(p2+i)!='\0'){
        if(*(p2+i)<=90) *(p2+i)+=32;
        i++;
    }
    strcat(str3,str1);
    strcat(str3," ");
    strcat(str3,str2);
    printf("%s",str3);

    printf("\n%d\n",strcmp(str1,str2));
}