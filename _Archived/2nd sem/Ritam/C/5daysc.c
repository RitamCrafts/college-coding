#include <stdio.h>
int main(){
    int ch;
    printf("Choose a day(1-7) from these:\n1:Monday\n2:Tuesday\n3:Wednesday\n6:Saturday\n7:Sunday\nChoice: ");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
        printf("First working day of week.");
        break;
    case 2:
        printf("Second working day of week.");
        break;
    case 3:
        printf("Mid day of week.");
        break;
    case 6:
        printf("Weekly off day.");
        break;
    case 7:
        printf("Holiday");
        break;
    default:
        printf("Enter from list only.");
        break;
    }
    return 0;
}