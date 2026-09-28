#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct queue {
    int front;
    int rear;
    int arr[MAX_SIZE];
};

void initialize(struct queue *q) {
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(struct queue *q) {
    return (q->front == -1 && q->rear == -1) || (q->front > q->rear);
}

bool isFull(struct queue *q) {
    return q->rear == MAX_SIZE - 1;
}

void insert(struct queue *q, int value) {
    if (isFull(q)) {
        printf("Queue overflow.\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->arr[q->rear] = value;
}

int delete(struct queue *q) {
    if (isEmpty(q)) {
        printf("Queue underflow.\n");
        return -1;
    }
    int deletedElement = q->arr[q->front];
    q->front++;
    return deletedElement;
}

int peek(struct queue *q) {
    if (isEmpty(q)) {
        printf("Queue underflow.\n");
        return -1;
    }
    return q->arr[q->front];
}

void display(struct queue *q) {
    if (isEmpty(q)) {
        printf("Queue underflow.\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    struct queue *q = malloc(sizeof(struct queue));
    initialize(q);

    while (1) {
        int op = 0;
        int n = 0;
        printf("Enter 1 to insert\n");
        printf("Enter 2 to delete\n");
        printf("Enter 3 to peek\n");
        printf("Enter 4 to display\n");
        printf("Enter your choice: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Enter no. to insert: ");
                scanf("%d", &n);
                insert(q, n);
                printf("\n");
                break;
            case 2:
                n = delete(q);
                if (n != -1) {
                    printf("Deleted element: %d", n);
                }
                printf("\n\n");
                break;
            case 3:
                n = peek(q);
                if (n != -1) {
                    printf("Front element: %d", n);
                }
                printf("\n\n");
                break;
            case 4:
                display(q);
                printf("\n\n");
                break;
            default:
                printf("Invalid choice.\n\n");
        }
    }
    return 0;
}
