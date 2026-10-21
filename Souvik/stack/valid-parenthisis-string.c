#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10000

struct Stack {
    int top;
    int arr[MAX_SIZE];
};

void init(struct Stack *s){
    s->top = -1;
}

bool isFull(struct Stack *s){
    return s->top == MAX_SIZE-1;
}

bool isEmpty(struct Stack *s){
    return s->top == -1;
}

void push(struct Stack *s, int val){
    if(isFull(s)){
        printf("Stack Overflow.\n");
        return;
    }

    s->top++;
    s->arr[s->top] = val;
}

int pop(struct Stack *s){
    if(isEmpty(s)){
        printf("Stack Underflow.\n");
        return -1;
    }

    int poppedElement = s->arr[s->top];
    s->top--;
    return poppedElement;
}

int peek(struct Stack *s){
    if(isEmpty(s)){
        return -1;
    }
    return s->arr[s->top];
}

bool checkValidString(char *s){
    struct Stack *st =malloc(sizeof(struct Stack));
    init(st);

    struct Stack *star = malloc(sizeof(struct Stack));
    init(star);

    for(int i = 0; s[i] != '\0'; i++){
        char elem = s[i];
        if(s[i] == '('){
            push(st,i);
        }else if(elem == '*'){
            push(star,i);
        }else{
            if(!isEmpty(st)){
                pop(st);
            }else if(isEmpty(st) && !isEmpty(star)){
                pop(star);
            }else if(isEmpty(st) && isEmpty(star)){
                return false;
            }
        }
    }

    while(!isEmpty(st)){
        if(isEmpty(star)){
            return false;
        }

        if(peek(st)<peek(star)){
            pop(st);
            pop(star);
        }else{
            return false;
        }
    }

    free(st);
    free(star);
    return true;


}   



int main(){
    char *s = "(";
    if(checkValidString(s) == true){
        printf("Valid.\n");
    }else{
        printf("Invalid.\n");
    }
    return 0;
}