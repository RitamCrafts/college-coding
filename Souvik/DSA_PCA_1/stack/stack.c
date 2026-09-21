#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100
struct Stack {
    int top;
    int arr[MAX_SIZE];
};

bool isEmpty(struct Stack *s){
    return s->top == -1;
}

bool isFull(struct Stack *s){
    return s->top == MAX_SIZE-1;
}

void init(struct Stack *s){
    s->top = -1;
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
        printf("Stack Underflow.\n");
        return -1;
    }

    int topElement = s->arr[s->top];
    return topElement;
}

void printStack(struct Stack *s){
    if(isEmpty(s)){
        printf("Stack Underflow.\n");
        return;
    }
    for(int i = s->top; i>=0; i--){
        printf("%d ",s->arr[i]);
    }
    printf("\n");
}

int main(){
    
    struct Stack *s = malloc(sizeof(struct Stack));
    init(s);
    push(s,4);
    push(s,5);
    push(s,6);
    printStack(s);

    int poppedElement = pop(s);
    printf("Popped Element: %d \n",poppedElement);
    printStack(s);

    int peekElement = peek(s);
    printf("Top Element: %d \n",peekElement);
    return 0;
}