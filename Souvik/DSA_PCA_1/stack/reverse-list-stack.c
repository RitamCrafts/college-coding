#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 8
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

void reverseList(struct Stack *s, int arr[MAX_SIZE]){
    for(int i = 0; i<MAX_SIZE; i++){
        push(s,arr[i]);
    }
    int resultArray[MAX_SIZE];
    int j = 0;
    while(!isEmpty(s)){
        int poppedElement = pop(s);
        resultArray[j++] = poppedElement;
    }
    for(int i = 0; i<j; i++){
        printf("%d ",resultArray[i]);
    }

    printf("\n");
}

int main(){
    int arr[MAX_SIZE];
    for(int i = 0; i<MAX_SIZE; i++){
        printf("Enter Number %d: ",i+1);
        scanf("%d",&arr[i]);
    }

    struct Stack *s = malloc(sizeof(struct Stack));
    init(s);
    reverseList(s,arr);
    return 0;
}