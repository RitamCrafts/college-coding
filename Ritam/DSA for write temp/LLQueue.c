
#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};

struct queue {
    struct node *front, *rear;
};

void initQueue(struct queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

void enQueue(struct queue *q, int val) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->val = val;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
}

void deQueue(struct queue *q) {
    if (q->front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    struct node *temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    printf("Dequeue successful\n");
}

void display(struct queue *q) {
    struct node *ptr = q->front;

    if (ptr == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue:\n");
    while (ptr != NULL) {
        printf("%d\n", ptr->val);
        ptr = ptr->next;
    }
}

int main() {
    struct queue q;
    int choice, val;

    initQueue(&q);

    printf("--- QUEUE USING LINKED LIST ---\n");
    printf("1.Enqueue  2.Dequeue  3.Display\n");
    printf("4.Menu  5.Exit\n");

    while (1) {
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enQueue(&q, val);
                break;

            case 2:
                deQueue(&q);
                break;

            case 3:
                display(&q);
                break;

            case 4:
                printf("--- QUEUE USING LINKED LIST ---\n");
                printf("1.Enqueue  2.Dequeue  3.Display\n");
                printf("4.Menu  5.Exit\n");
                break;

            case 5:
                exit(0);

            default:
                printf("Wrong Choice\n");
        }
    }
}

/*
--- QUEUE USING LINKED LIST ---
1.Enqueue  2.Dequeue  3.Display
4.Menu  5.Exit

Enter choice: 1
Enter value: 10

Enter choice: 1
Enter value: 20

Enter choice: 1
Enter value: 30

Enter choice: 3
Queue:
10
20
30

Enter choice: 2
Dequeue successful

Enter choice: 3
Queue:
20
30

Enter choice: 5
*/