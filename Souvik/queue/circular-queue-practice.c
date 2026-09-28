#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct queue {
    int arr[MAX_SIZE];
    int front;
    int rear;
};

void init(struct queue *q){
    q->front = -1;
    q->rear = -1;
}

bool isFull(struct queue *q){
    return ((q->rear)+1)%MAX_SIZE == q->front;
}

bool isEmpty(struct queue *q){
    return q->front == -1;
}

void enqueue(struct queue *q, int val){
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

int dequeue(struct queue *q){
    if(isEmpty(q)){
        printf("Queue Underflow.\n");
        return -1;
    }

    int dequeued = q->arr[q->front];

    if(q->front == q->rear){
        q->front = -1;
        q->rear = -1;
    }else{
        q->front = ((q->front)+1)%MAX_SIZE;
    }

    return dequeued;
}

int peek(struct queue *q){
    if(isEmpty(q)){
        printf("queue underflow.\n");
        return -1;
    }

    int topElement = q->arr[q->front];

    return topElement;
}

void display(struct queue *q){
    if(isEmpty(q)){
        printf("Queue is empty.\n");
        return;
    }

    int i = q->front;
    while(i != q->rear){
        printf("%d ",q->arr[i]);
        i = (i+1)%MAX_SIZE;
    }
    printf("%d\n",q->arr[q->rear]);
}

int main(){
    struct queue *q = malloc(sizeof(struct queue));
    init(q);
    enqueue(q,4);
    enqueue(q,5);
    enqueue(q,6);
    display(q);
    printf("\n");
    dequeue(q);
    display(q);

    printf("Top Element: %d \n",peek(q));
    return 0;
}