#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 5

struct queue {
    int front;
    int rear;
    int arr[MAX_SIZE];
};

void init(struct queue *q) {
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(struct queue *q) {
    return (q->front == -1);
}

bool isFull(struct queue *q) {
    return ((q->rear+1)%MAX_SIZE) == q->front;
}

void enQueue(struct queue *q, int value) {
    if (isFull(q)) {
        printf("Queue overflow.\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear=(q->rear+1)%MAX_SIZE;
    q->arr[q->rear] = value;
}

int deQueue(struct queue *q) {
    if (isEmpty(q)) {
        printf("Queue underflow.\n");
        return -1;
    }
    if(q->front==q->rear){
        int deletedElement = q->arr[q->front];
        init(q);
        return deletedElement;
    }
    else{
        int deletedElement = q->arr[q->front];
        q->front=(q->front+1)%MAX_SIZE;
        return deletedElement;
    }
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
    int i = q->front;
    while(i!=q->rear){
        printf("%d ",q->arr[i]);
        i=(i+1)%MAX_SIZE;
    }
    printf("%d ",q->arr[q->rear]);
    printf("\n");
}

int main() {
    struct queue *q = malloc(sizeof(struct queue));
    init(q);

    while (1) {
        int op = 0;
        int n = 0;
        printf("Enter 1 to enQueue(insert)\n");
        printf("Enter 2 to deQueue(delete)\n");
        printf("Enter 3 to peek\n");
        printf("Enter 4 to display\n");
        printf("Enter your choice: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Enter no. to insert: ");
                scanf("%d", &n);
                enQueue(q, n);
                printf("\n");
                break;
            case 2:
                n = deQueue(q);
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
