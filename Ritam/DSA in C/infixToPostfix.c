//INFIC TO POSTFIX
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct stack{
    char arr[MAX_SIZE];
    int top;
};

void init(struct stack *s){
    s->top=-1;
}

void push(struct stack *s,char ch){
    if(s->top==(MAX_SIZE-1)){
        printf("Overflow");
        return;
    }
    s->top++;
    s->arr[s->top] = ch;
}

char pop(struct stack *s){
    if(s->top==-1){
        printf("Underflow");
        return -1;
    }
    char poppedElement = s->arr[s->top];
    s->top--;
    return(poppedElement);
}

char peek(struct stack *s){
    if(s->top==-1){
        printf("Underflow");
        return -1;
    }
    char poppedElement = s->arr[s->top];
    return(poppedElement);
}

void display(struct stack *s){
    int i;
    for(i=s->top;i>=0;i--){
        printf("%c",s->arr[i]);
    }
}

int getPrecedence(char op) {
    if (op == '^') {
        return 3;
    }
    else if (op == '*' || op == '/' || op == '%') {
        return 2;
    }
    else if (op == '+' || op == '-') {
        return 1;
    }
    else {
        return 0;
    }
}

bool isOperand(char ch) {
    if ((ch >= 'A' && ch <= 'Z') ||
        (ch >= 'a' && ch <= 'z') ||
        (ch >= '0' && ch <= '9')) {
        return true;
    }
    return false;
}

void infixToPostfix(char infix[], char postfix[]) {
    struct stack *s = malloc(sizeof(struct stack));
    init(s);
    int i=0;
    int j=0;

    while(infix[i]!='\0'){
        if(isOperand(infix[i])){
            postfix[j]=infix[i];
            j++;
        }
        else if(infix[i]=='('){
            push(s,infix[i]);
        }
        else if(infix[i]==')'){
            while(peek(s)!='('){
                postfix[j]=pop(s);
                j++;
            }
            pop(s);
        }
        else { //operator
            while(s->top!=-1 && getPrecedence(peek(s))>=getPrecedence(infix[i])){
                postfix[j] = pop(s);
                j++;
            }
            push(s,infix[i]);
        }
        i++;
    }

    while(s->top!=-1){
        postfix[j] = pop(s);
        j++;
    }

    postfix[j] = '\0';

    free(s);
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter infix: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix: %s", postfix);

    return 0;
}

