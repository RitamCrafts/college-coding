#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct queue{
    int arr[MAX_SIZE];
    int front;
    int rear;
};

bool isEmpty(struct queue *q){
    return q->front == -1;
}

bool isFull(struct queue *q){
    return (q->rear+1)%MAX_SIZE == q->front;
}

void init(struct queue *q){
    q->front = -1;
    q->rear = -1;
}

void enQueue(struct queue *q, int val){
    if(isFull(q)){
        printf("Queue Overflow.\n");
        return;
    }
    
    if(q->front == -1){
        q->front = 0;
    }

    q->rear = ((q->rear)+1)%MAX_SIZE;
    q->arr[q->rear] = val;
}

int deQueue(struct queue *q){
    if(isEmpty(q)){
        printf("Queue Underflow.\n");
        return -1;
    }

    int deQueuedElement = q->arr[q->front];
    if(q->front == q->rear){
        q->front = -1;
        q->rear = -1;
    }
    else{
        q->front = ((q->front)+1)%MAX_SIZE;
    }

    return deQueuedElement;
}

int peek(struct queue *q){
    if(isEmpty(q)){
        printf("Queue Underflow.\n");
        return -1;
    }

    int topElement = q->arr[q->front];
    return topElement;
}

void displayQueue(struct queue *q){
    if(isEmpty(q)){
        printf("Queue is Empty.\n");
        return;
    }

    for(int i = q->front; i!= q->rear; i = (i+1)%MAX_SIZE){
        printf("%d ",q->arr[i]);

    }
    printf("%d\n",q->arr[q->rear]);
}

int main(){
    struct queue *q = malloc(sizeof(struct queue));
    init(q);
    int opt,val;
    while(true){
        printf("\n .... MENU ....\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your option: ");
        scanf("%d",&opt);
        switch (opt)
        {
        case 1:
            printf("Enter Value: ");
            scanf("%d",&val);
            enQueue(q,val);
            break;
        
        case 2:{
            int deQueued = deQueue(q);
            printf("Dequeued element: %d\n",deQueued);
            break;
        }
        
        case 3:{
            int topElement = peek(q);
            printf("Top Element: %d \n",topElement);
            break;
        }

        case 4:
            displayQueue(q);
            break;
        
        case 5:
            printf("Exit Successfull.\n");
            return -1;

        default:
            printf("Invalid Choice.\n");
            break;
        }
    }
    return 0;
}