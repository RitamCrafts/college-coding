#include <stdio.h>
#include <string.h>

void nothing(char str[],char* st){
    printf("%s\n",str);
    printf("%s",st);
}
void main(){
    char str[20]="Ritam Mandal";
    str[strcspn(str," ")]='\0';
    int i=0;
    printf("%s\n",str);
    char *p=str;
    for(i=0;i<20;i++){
        printf("%c",*(p+i));
    }
    printf("\n\n");
    nothing(str,str);

}