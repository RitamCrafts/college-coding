//STACK
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct stack{
    int arr[MAX_SIZE];
    int top;
};

void init(struct stack *s){
    s->top=-1;
}

void push(struct stack *s,int n){
    if(s->top==(MAX_SIZE-1)){
        printf("Overflow");
        return;
    }
    s->top++;
    s->arr[s->top] = n;
}

int pop(struct stack *s){
    if(s->top==-1){
        printf("Underflow");
        return -1;
    }
    int poppedElement = s->arr[s->top];
    s->top--;
    return(poppedElement);
}

int peek(struct stack *s){
    if(s->top==-1){
        printf("Underflow");
        return -1;
    }
    int poppedElement = s->arr[s->top];
    return(poppedElement);
}

void display(struct stack *s){
    int i;
    for(i=s->top;i>=0;i--){
        printf("%d ",s->arr[i]);
    }
}


int main() { //main fn written by AI
    struct stack s;
    int choice, value;

    init(&s);

    while (1) {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(&s, value);
                break;

            case 2:
                value = pop(&s);
                if (s.top != -1)
                    printf("Popped: %d\n", value);
                break;

            case 3:
                value = peek(&s);
                if (s.top != -1)
                    printf("Top element: %d\n", value);
                break;

            case 4:
                display(&s);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}