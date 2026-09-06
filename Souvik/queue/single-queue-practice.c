#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct queue{
    int front;
    int rear;

    int arr[MAX_SIZE];
};

void initialise(struct queue *q){
    q->front = -1;
    q->rear = -1;
}

bool isFull(struct queue *q){
    return q->rear == MAX_SIZE-1;
}

bool isEmpty(struct queue *q){
    return q->front == -1;
}

void enque(struct queue *q, int value){
    if(isFull(q)){
        printf("Queue is full.\n");
        return;
    }

    if(q->front == -1){
        q->front = 0;
    }

    q->rear++;
    q->arr[q->rear] = value;
}

int deQueue(struct queue *q){
    if(isEmpty(q)){
        printf("Queue is empty.\n");
        return -1;
    }

    int poppedElement = q->arr[q->front];
    q->front++;

    if(q->front > q->rear){
        q->front = 0;
        q->rear = -1;
    }

    return poppedElement;
}

int peek(struct queue *q){
    if(isEmpty(q)){
        printf("Queue is empty.\n");
        return -1;
    }

    int topElement = q->arr[q->front];
    return topElement;
}

void printQueue(struct queue *q){
    if(isEmpty(q)){
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for(int i = q->front; i <= q->rear; i++){
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main(){
    struct queue *q = malloc(sizeof(struct queue));
    initialise(q);
    enque(q,5);
    enque(q,6);
    enque(q,7);
    enque(q,8);
    enque(q,9);
    
    printQueue(q);
    printf("\n");

    deQueue(q);
    printQueue(q);
    printf("\n");

    int topElement = peek(q);
    if(topElement != -1){
        printf("Top element: %d\n", topElement);
    }
    
    return 0;
}