//LINEAR QUEUE STANDERED
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 20

struct queue{
    int arr[MAX_SIZE];
    int front;
    int rear;
};

void init(struct queue *q){
    q->rear=-1;
    q->front=-1;
}

bool isFull(struct queue *q){
    if(q->rear==(MAX_SIZE-1)){
        return true;
    }
    else{
        return false;
    }
}

bool isEmpty(struct queue *q){
    if(q->front==-1){
        return true;
    }
    else{
        return false;
    }
}

void enQueue(struct queue *q,int n){
    if(isFull(q)){
        printf("Queue Overflow");
        return;
    }
    if(isEmpty(q)){
        q->front = 0;
    }
    q->rear++;
    q->arr[q->rear]=n;
}

int deQueue(struct queue *q){
    if(isEmpty(q)){
        printf("Queue Underflow");
        return -1;
    }
    int delVal = q->arr[q->front];
    if(q->front==q->rear){
        q->front=-1;
        q->rear=-1;
    }
    else{
        q->front++;
    }
    return delVal;
}

int getQueue(struct queue *q,int *arr,int len){
    int i;
    int j=0;
    if(isEmpty(q)){
        return 0;
    }
    if((q->rear - q->front + 1) > len){
        printf("getQueue abort: passed array size is too small!");
        return 0;
    }
    for(i=q->front;i<=q->rear;i++){
        *(arr+j)=q->arr[i];
        j++;
    }
    return j;
}

void displayQueue(struct queue *q) {
    int queueCopy[MAX_SIZE];
    int len = getQueue(q,queueCopy,MAX_SIZE);
    int i;
    for(i=0;i<len;i++){
        printf("%d  ",queueCopy[i]);
    }
}


int main() { //by AI
    struct queue q;
    int choice, value;

    init(&q);

    while (1) {
        printf("\n\n--- QUEUE MENU ---\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Show All\n");
        printf("4. Exit\n");
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
                printf("Queue: ");
                displayQueue(&q);
                printf("\n");
                printf("Front --> Back");
                printf("\n");
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}





