#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct stack {
    int top;
    char arr[MAX_SIZE];
};

void initialise(struct stack *s){
    s->top = -1;
}

bool isFull(struct stack *s){
    return s->top == MAX_SIZE -1;
}

bool isEmpty(struct stack *s){
    return s->top == -1;
}

void push(struct stack *s, char val){
    if(isFull(s)){
        printf("Stack Overflow.\n");
        return;
    }
    s->top++;
    s->arr[s->top] = val;
}


void pop(struct stack *s){
    if(isEmpty(s)){
        printf("Stack Underflow.\n");
        return;
    }

    char poppedValue = s->arr[s->top];
    s->top--;
}

void removeOuterMostParenthisis(char str[MAX_SIZE]){
    struct stack *s = malloc(sizeof(struct stack));
    initialise(s);

    char result[MAX_SIZE] = {};
    int j = 0;
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == '('){
            if(isEmpty(s)){
                push(s, str[i]);
            }else{
                result[j++] = str[i];
                push(s,str[i]);
            }
        }else if(str[i] == ')'){
            pop(s);
            if(!isEmpty(s)){
                result[j++] = str[i];
            }
        }
    }

    result[j] = '\0';

    for(int k = 0; result[k] != '\0'; k++){
        printf("%c",result[k]);
    }

    printf("\n");
    
}

int main(){
    char str[MAX_SIZE] = "()((()))";
    removeOuterMostParenthisis(str);
    return 0;
}