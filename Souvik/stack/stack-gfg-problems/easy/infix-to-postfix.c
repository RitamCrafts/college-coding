#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 30

struct stack {
    int top;
    char arr[MAX_SIZE];
};

bool isEmpty(struct stack *s){
    return s->top == -1;
}

bool isFull(struct stack *s){
    return s->top == MAX_SIZE-1;
}

void init(struct stack *s){
    s->top = -1;
}

void push(struct stack *s, char val){
    if(isFull(s)){
        printf("Stack Overflow.\n");
        return;
    }

    s->top++;
    s->arr[s->top] = val;
}

bool isAlNum(char val){
    if ((val >= 'A' && val <= 'Z') ||
    (val >= 'a' && val <= 'z') ||
    (val >= '0' && val <= '9')){
        return true;
    }else{
        return false;
    }
}

char pop(struct stack *s){
    if(isEmpty(s)){
        printf("Stack Underflow.\n");
        return -1;
    }

    int topElement = s->arr[s->top];
    s->top--;
    return topElement;
}

char peek(struct stack *s){
    if(isEmpty(s)){
        printf("Stack Underflow.\n");
        return -1;
    }

    char topElement = s->arr[s->top];
    return topElement;
}

int checkPreceedence(char val){
    if(val == '^'){
        return 3;
    }else if(val == '*' || val == '/'){
        return 2;
    }else if(val == '+' || val == '-'){
        return 1;
    }else{
        return 0;
    }
}

bool checkRightAssociative(char val){
    return val == '^';
}

void infixToPostFix(struct stack *s, char str[MAX_SIZE]){
    char result[MAX_SIZE+1]="";
    int j = 0;
    for(int i = 0; str[i] != '\0'; i++){
        if(isAlNum(str[i]) == true){
            result[j++] = str[i];
        }

        else if(str[i] == '('){
            push(s,str[i]);
        }else if(str[i] == ')'){
            while (!isEmpty(s) && peek(s) != '(') {
                result[j++] = pop(s);
            }

            if (!isEmpty(s) && peek(s) == '(') {
                pop(s);   
            }
        }else{
            while((!isEmpty(s) && peek(s) != '(')&& (checkPreceedence(peek(s)) > checkPreceedence(str[i]) ||(checkPreceedence(peek(s)) == checkPreceedence(str[i])) && !checkRightAssociative(str[i]))){
                result[j++] = pop(s);
            }
            push(s,str[i]);
        }
    }

    while(!isEmpty(s)){
       result[j++] = pop(s);
    }

    result[j] = '\0';

    printf("Result: %s\n",result);
}

int main(){
    struct stack *s = malloc(sizeof(struct stack));
    init(s);
    char arr[MAX_SIZE] = "A+B-C*D";
    infixToPostFix(s,arr);
    return 0;
}