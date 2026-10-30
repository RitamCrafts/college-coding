
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct queue {
    int arr[MAX_SIZE];
    int front, rear;
};

void enQueue(struct queue *q, int n) {
    if ((q->rear+1)%MAX_SIZE == q->front) {
        printf("Queue Overflow\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;

    q->rear = (q->rear+1)%MAX_SIZE;
    q->arr[q->rear] = n;
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
        q->front = (q->front+1)%MAX_SIZE;

    return val;
}

int getQueue(struct queue *q, int *arr, int len) {
    int i, j = 0;

    if (q->front == -1)
        return 0;

    int size = (q->rear-q->front+MAX_SIZE)%MAX_SIZE+1;

    if (size > len) {
        printf("Array size too small\n");
        return 0;
    }

    i = q->front;
    while (1) {
        arr[j++] = q->arr[i];

        if (i == q->rear)
            break;

        i = (i+1)%MAX_SIZE;
    }
    return j;
}

void displayQueue(struct queue *q) {
    int arr[MAX_SIZE], len, i;

    len = getQueue(q, arr, MAX_SIZE);

    if (len == 0) {
        printf("Queue is empty\n");
        return;
    }

    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);

    printf("\nFront --> Back\n");
}

int main() {
    struct queue q;
    int choice, value;

    q.front = q.rear = -1;

    printf("--- CIRCULAR QUEUE MENU ---\n");
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
                displayQueue(&q);
                break;

            case 4:
                printf("--- CIRCULAR QUEUE MENU ---\n");
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
--- CIRCULAR QUEUE MENU ---
1.Enqueue  2.Dequeue  3.Display  4.Menu  5.Exit

Enter choice: 1
Enter value: 10

Enter choice: 1
Enter value: 20

Enter choice: 1
Enter value: 30

Enter choice: 1
Enter value: 40

Enter choice: 3
10 20 30 40
Front --> Back

Enter choice: 2
Deleted: 10

Enter choice: 2
Deleted: 20

Enter choice: 1
Enter value: 50

Enter choice: 1
Enter value: 60

Enter choice: 3
30 40 50 60
Front --> Back

Enter choice: 5
*/
