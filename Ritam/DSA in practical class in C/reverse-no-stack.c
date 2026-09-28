#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct stack{
    int top;
    int arr[MAX_SIZE];
};

void initialize(struct stack *s){
    s->top = -1;
}

bool isEmpty(struct stack *s){
    return s->top == -1;
}

bool isFull(struct stack *s){
    return s->top == MAX_SIZE-1;
}

void push(struct stack *s,int value){
    if(isFull(s)){
        printf("Stack overflow.\n");
        return;
    }
    s->top++;
    s->arr[s->top]=value;
}

void pushMultiple(struct stack *s,int *numarr,int len){
    if(isFull(s)){
        printf("Stack overflow.\n");
        return;
    }
    int i = 0;
    for(i=0;i<len;i++){
        push(s,numarr[i]);
    }
}

int pop(struct stack *s){
    if(isEmpty(s)){
        printf("Stack underflow.\n");
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
    return s->arr[s->top];
}

void display(struct stack *s){
    if(isEmpty(s)){
        printf("Stack underflow.\n");
        return;
    }
    int i=0;
    for(i=s->top;i>=0;i--){
        printf("%d ",s->arr[i]);
    }
}

int main(){
    struct stack *s = malloc(sizeof(struct stack));
    initialize(s);
    int len;
    printf("Enter length of array:");
    scanf("%d",&len);
    int arr[len];
    printf("Input an array:\n");
    int i;
    for(i=0;i<len;i++){
        scanf("%d",&arr[i]);
    }
    pushMultiple(s,arr,len);

    for(i=0;i<len;i++){
        printf("%d",pop(s));
    }
}





