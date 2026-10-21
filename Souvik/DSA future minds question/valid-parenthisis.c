#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack {
    char val;
    struct Stack *next;
};

bool isEmpty(struct Stack *s){
    return s == NULL;
}

struct Stack *createElement(char val){
    struct Stack *newElement = (struct Stack *)malloc(sizeof(struct Stack));
    newElement->val = val;
    newElement->next = NULL;

    return newElement;
}

struct Stack *push(struct Stack *s, char val){
    struct Stack *newElement = createElement(val);
    newElement->next = s;
    s = newElement;

    return s;
}

struct Stack *pop(struct Stack *s){
    if(isEmpty(s)){
        return NULL;
    }

    struct Stack *temp = s;
    s = s->next;
    free(temp);

    return s;
}

char peek(struct Stack *s){
    if(isEmpty(s)){
        return '\0';
    }

    return s->val;
}

bool isValid(char *s){
    struct Stack *top = NULL;

    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            top = push(top,s[i]);
        }else if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
            if(isEmpty(top)){
                return false;
            }

            if((s[i] == ')' && peek(top) != '(')||(s[i] == '}' && peek(top) != '{')||(s[i] == ']' && peek(top) != '[')){
                return false;
            }

            top = pop(top);
        }
    }

    if(isEmpty(top)){
        return true;
    }

    return false;
}

int main(){
    char *s="()[]{}";
    if(isValid(s) == true){
        printf("Valid.\n");
    }else{
        printf("Not valid.\n");
    }
    return 0;
}