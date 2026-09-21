#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define maxsize 100

struct stack {
    int top;
    int arr[maxsize];
};

void initialise(struct stack *s){
    s->top = -1;
}

bool isEmpty(struct stack *s){
    return s->top == -1;
}

bool isFull(struct stack *s){
    return s->top == maxsize-1;
}

void push(struct stack *s,int val){
    if(isFull(s)){
        printf("Stack is full. \n");
        return;
    }
    s->top++;
    s->arr[s->top] = val;
}

int pop(struct stack *s){
    if(isEmpty(s)){
        printf("Stack underflow. \n");
        return -1;
    }
    int poppedElement = s->arr[s->top];
    s->top--;
    return poppedElement;
}

int peek(struct stack *s){
    if(isEmpty(s)){
        printf("Stack underflow.\n");
        return -1;
    }

    int topElement = s->arr[s->top];
    return topElement;
}

void printStack(struct stack *s){
    if(isEmpty(s)){
        printf("Stack underflow.\n");
        return;
    }

    for(int i  = s->top; i>=0; i--){
        printf("%d \n",s->arr[i]);
    }
}

int main(){
    struct stack *s = malloc(sizeof(struct stack));
    initialise(s);
    push(s,5);
    push(s,6);
    push(s,7);
    printStack(s);
    return 0;
}