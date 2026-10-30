
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

struct queue {
    int arr[MAX_SIZE];
    int front, rear;
};

void enQueue(struct queue *q, int n) {
    if (q->rear == MAX_SIZE-1) {
        printf("Queue Overflow\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;

    q->arr[++q->rear] = n;
}

int deQueue(struct queue *q) {
    int val;
    if (q->front == -1) {
        printf("Queue Underflow\n");
        return -1;
    }

    val = q->arr[q->front];

    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;

    return val;
}

void display(struct queue *q) {
    int i;
    if (q->front == -1) {
        printf("Queue is empty\n");
        return;
    }

    for (i = q->front; i <= q->rear; i++)
        printf("%d ", q->arr[i]);

    printf("\nFront --> Back\n");
}

int main() {
    struct queue q;
    int choice, value;

    q.front = q.rear = -1;

    printf("--- QUEUE MENU ---\n");
    printf("1.Enqueue  2.Dequeue  3.Display  4.Menu  5.Exit\n");

    while (1) {
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enQueue(&q, value);
                break;

            case 2:
                value = deQueue(&q);
                if (value != -1)
                    printf("Deleted: %d\n", value);
                break;

            case 3:
                display(&q);
                break;

            case 4:
                printf("--- QUEUE MENU ---\n");
                printf("1.Enqueue  2.Dequeue  3.Display  4.Menu  5.Exit\n");
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}

/*
--- QUEUE MENU ---
1.Enqueue  2.Dequeue  3.Display  4.Menu  5.Exit

Enter choice: 1
Enter value: 10

Enter choice: 1
Enter value: 20

Enter choice: 1
Enter value: 30

Enter choice: 3
10 20 30
Front --> Back

Enter choice: 2
Deleted: 10

Enter choice: 3
20 30
Front --> Back

Enter choice: 5
*/