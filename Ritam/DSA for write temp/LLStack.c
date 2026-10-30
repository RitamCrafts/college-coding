
#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};

struct node *push(struct node *top, int val) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->val = val;
    newNode->next = top;
    return newNode;
}

struct node *pop(struct node *top) {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return top;
    }

    struct node *temp = top;
    top = top->next;
    free(temp);
    return top;
}

int peek(struct node *top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -9999;
    }
    return top->val;
}

void display(struct node *top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack:\n");
    while (top != NULL) {
        printf("%d\n", top->val);
        top = top->next;
    }
}

int main() {
    struct node *top = NULL;
    int choice, val;

    printf("--- STACK USING LINKED LIST ---\n");
    printf("1.Push  2.Pop  3.Peek  4.Display\n");
    printf("5.Menu  6.Exit\n");

    while (1) {
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                top = push(top, val);
                break;

            case 2:
                if (top != NULL) {
                    printf("Popped value: %d\n", peek(top));
                    top = pop(top);
                } else {
                    top = pop(top);
                }
                break;

            case 3:
                if (top != NULL)
                    printf("Top value: %d\n", peek(top));
                else
                    printf("Stack is empty\n");
                break;

            case 4:
                display(top);
                break;

            case 5:
                printf("--- STACK USING LINKED LIST ---\n");
                printf("1.Push  2.Pop  3.Peek  4.Display\n");
                printf("5.Menu  6.Exit\n");
                break;

            case 6:
                exit(0);

            default:
                printf("Wrong Choice\n");
        }
    }
}

/*
--- STACK USING LINKED LIST ---
1.Push  2.Pop  3.Peek  4.Display
5.Menu  6.Exit

Enter choice: 1
Enter value: 10

Enter choice: 1
Enter value: 20

Enter choice: 1
Enter value: 30

Enter choice: 4
Stack:
30
20
10

Enter choice: 3
Top value: 30

Enter choice: 2
Popped value: 30

Enter choice: 4
Stack:
20
10

Enter choice: 6
*/