#include <stdio.h>
#include <stdlib.h>
int firstNum(char *str);
int main() {
    FILE *testFC;
    FILE *testFW;
    FILE *testFR;
    char fileName[20]="number.txt";
    char str[20]="";

    testFC=fopen(fileName,"w");
    if (testFC == NULL) {
        printf("Error: Could not open file.\n");
        return 1; 
    }
    fclose(testFC);

    testFR=fopen(fileName,"r");
    if (testFR == NULL) {
        printf("Error: Could not open file.\n");
        return 1; 
    }
    fgets(str,sizeof(str),testFR);

    int num=0;
    int *temp;
    temp=malloc(sizeof(int));
    *temp=firstNum(str);
    if(*temp>0){
        num=*temp;
    }
    free(temp);
    temp=NULL;
    fclose(testFR);

    int newNum=num+5;

    if(newNum<0){
        printf("Negetive number not supported!");
        return 0;
    }

    testFW=fopen(fileName,"w");
    if (testFW == NULL) {
        printf("Error: Could not open file.\n");
        return 1; 
    }
    fprintf(testFW,"Number: %d",newNum);
    fclose(testFW);
    printf("Number changed from %d to %d.",num,newNum);
    return 0;
}

int firstNum(char *str){
    int i=0;
    int numFlag=0;
    int num=-1;
    while(*(str+i)!='\0'){
        int ascii=(int)*(str+i);
        if((numFlag==0)&&((ascii>=48)&&(ascii<58))){
            numFlag++;
            int digit=ascii-48;
            num=0;
            num=(num*10)+digit;
        }
        else if(numFlag==1){
            if((ascii>=48)&&(ascii<58)){
                int digit=ascii-48;
                num=(num*10)+digit;
            }
            else{
                numFlag++;
                break;
            }
        }
        i++;
    }
    return num;
}