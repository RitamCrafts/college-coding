#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char target[] = "Hello";
    printf("%s\n",target);
    strcpy(target,"World");
    printf("%s\n",target);
    strcpy(target,"");
    printf("%s",target);
    target="five";
    printf("%s",target);
}




