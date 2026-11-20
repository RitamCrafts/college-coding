
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE], top = -1;

void push(int n) {
    if (top == MAX_SIZE-1) {
        printf("Overflow\n");
        return;
    }
    stack[++top] = n;
}

int pop() {
    if (top == -1) {
        printf("Underflow\n");
        return -1;
    }
    return stack[top--];
}

int peek() {
    if (top == -1) {
        printf("Underflow\n");
        return -1;
    }
    return stack[top];
}

void display() {
    int i;
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    for (i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    int choice, value;

    printf("--- STACK MENU ---\n");
    printf("1.Push  2.Pop  3.Peek  4.Display  5.Menu  6.Exit\n");

    while (1) {
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                value = pop();
                if (value != -1)
                    printf("Popped: %d\n", value);
                break;

            case 3:
                value = peek();
                if (value != -1)
                    printf("Top: %d\n", value);
                break;

            case 4:
                display();
                break;

            case 5:
                printf("--- STACK MENU ---\n");
                printf("1.Push  2.Pop  3.Peek  4.Display  5.Menu  6.Exit\n");
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}

/*
--- STACK MENU ---
1.Push  2.Pop  3.Peek  4.Display  5.Menu  6.Exit

Enter choice: 1
Enter value: 10

Enter choice: 1
Enter value: 20

Enter choice: 1
Enter value: 30

Enter choice: 4
30 20 10

Enter choice: 3
Top: 30

Enter choice: 2
Popped: 30

Enter choice: 4
20 10

Enter choice: 6
*/