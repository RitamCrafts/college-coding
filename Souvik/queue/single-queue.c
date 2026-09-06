#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct queue{
    int front;
    int rear;
    int arr[MAX_SIZE];
};

void initialize(struct queue *q){
    q->front = -1;
    q->rear = -1;
}

bool isFull(struct queue *q){
    return q->rear == MAX_SIZE-1;
}

bool isEmpty(struct queue *q){
    return q->front == -1;
}

void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("Queue is full. \n");
        return;
    }

    if (q->front == -1) {
        q->front = 0;
    }

    q->rear++;
    q->arr[q->rear] = val;
}

int dequeue(struct queue *q){
    if(isEmpty(q)){
        printf("Queue is empty. \n");
        return -1;
    }

    int poppedElement = q->arr[q->front];
    q->front++;

    if (q->front > q->rear) {
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

    for(int i = q->front; i<=q->rear; i++){
        printf("%d ",q->arr[i]);
    }
}



int main(){
    struct queue *q = malloc(sizeof(struct queue));
    initialize(q);
    enqueue(q,4);
    enqueue(q,5);
    enqueue(q,6);
    enqueue(q,7);
    printQueue(q);
    printf("\n");
    dequeue(q);
    printQueue(q);
    printf("\n");
    int topElement = peek(q);
    printf("Top element is: %d\n",topElement);
    printf("\n");
    
    return 0;
}