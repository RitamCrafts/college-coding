#include <stdio.h>
void main(){
    int marks;
    printf("Enter  marks out of 100:");
    scanf("%d",&marks);
    char ch='N';
    if(marks<40){
        ch='F';
    }
    else if(marks>=40 && marks<50){
        ch='D';
    }
    else if(marks>=50 && marks<60){
        ch='C';
    }
    else if(marks>=60 && marks<70){
        ch='B';
    }
    else if(marks>=70 && marks<80){
        ch='A';
    }
    else if(marks>=80 && marks<90){
        ch='E';
    }
    else if(marks>=90 && marks<=100){
        ch='O';
    }
    if (ch=='F'){
        printf("Grade %c: You have failed!",ch);
    }
    else{
        printf("Grade %c: You have passed with grade %c!\n",ch,ch);
    }

}