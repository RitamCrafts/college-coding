#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 30

struct stack {
    char top;
    char arr[MAX_SIZE];
};

void init(struct stack *s){
    s->top = -1;
}

bool isEmpty(struct stack *s){
    return s->top == -1;
}

bool isFull(struct stack *s){
    return s->top == MAX_SIZE -1;
}

void push(struct stack *s,char val){
    if(isFull(s)){
        printf("Stack Overflow.\n");
        return;
    }

    s->top++;
    s->arr[s->top] = val;
}

char pop(struct stack *s){
    if(isEmpty(s)){
        printf("Stack Undeflow.\n");
        return -1;
    }

    char poppedElement = s->arr[s->top];
    s->top--;
    return poppedElement;
}

void reverseString(char str[],struct stack *s){
    for(int i = 0; str[i] != '\0'; i++){
        push(s,str[i]);
    }

    char result[MAX_SIZE + 1]="";
    int j = 0;
    while(!isEmpty(s)){
        char poppedElement = pop(s);
        result[j] = poppedElement;
        j++;
    }

    result[j] = '\0';
    for(int i = 0; result[i] != '\0'; i++){
        printf("%c ",result[i]);
    }

    printf("\n");
}

int main(){
    struct stack *s = malloc(sizeof(struct stack));
    init(s);
    char str[]="Souvik";
    reverseString(str,s);
    return 0;
}