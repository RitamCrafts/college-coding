#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stack {
    int val;
    struct stack *next;
};

struct stack *createStack(int val){
    struct stack *top = (struct stack *)malloc(sizeof(struct stack));
    top->val = val;
    top->next = NULL;

    return top;
}

bool isEmpty(struct stack *s){
    return s == NULL;
}

bool isFull(struct stack *s) {
    struct stack *temp = malloc(sizeof(struct stack));

    if (temp == NULL) {
        return true;
    }

    free(temp);
    return false;
}

struct stack *push(struct stack *s, int val){
    if (isFull(s)) {
        printf("Stack is full.\n");
        return s;
    }

    struct stack *newElement = createStack(val);

    newElement->next = s;
    s = newElement;

    return s;
    
}

struct stack *pop(struct stack *s){

    if(isEmpty(s)){
        printf("Stack underflow.\n");
        return NULL;
    }

    struct stack *temp = s;
    s  = s->next;
    free(temp);

    return s;
}

int peek(struct stack *s){
    if(isEmpty(s)){
        printf("Stack underflow.\n");
        return -1;
    }

    return s->val;
}

void display(struct stack *s){
    if(isEmpty(s)){
        printf("Stack underflow.\n");
        return;
    }

    struct stack *temp = s;
    while(temp != NULL){
        printf("%d",temp->val);
        if(temp->next != NULL){
            printf(" -> ");
        }
        temp = temp->next;
    }

    printf("\n");
}

int main(){
    struct stack *top = createStack(10);
    top->next = createStack(11);
    top->next->next = createStack(12);
    top->next->next->next = createStack(13);

    display(top);

    printf("\n");
    top = push(top,12);
    display(top);
    printf("\n");

    top = pop(top);
    display(top);
    printf("\n");

    int topElement = peek(top);
    printf("Top element is: %d\n",topElement);
    
    return 0;
}