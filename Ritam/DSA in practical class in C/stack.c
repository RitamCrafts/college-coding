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

    while(1){
        int op=0;
        int n=0;
        printf("Enter 1 to push\n");
        printf("Enter 2 to pop\n");
        printf("Enter 3 to peek\n");
        printf("Enter 4 to display\n");
        printf("Enter your choice:");
        scanf("%d",&op);
        switch(op){
        case 1:
            n=0;
            printf("Enter no. to push:");
            scanf("%d",&n);
            push(s,n);
            printf("\n");
            break;
        case 2:
            n=0;
            n = pop(s);
            printf("Popped element: %d",n);
            printf("\n\n");
            break;
        case 3:
            int n = peek(s);
            printf("Top element: %d",n);
            printf("\n\n");
            break;
        case 4:
            display(s);
            printf("\n\n");
            break;
        }
    }
}




