#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct queue{
    int arr[MAX_SIZE];
    int front;
    int rear;
};

void initialise(struct queue *q){
    q->front = -1;
    q->rear = -1;
}

bool isFull(struct queue *q){
    return (q->rear)+1 % MAX_SIZE == q->front;
}

bool isEmpty(struct queue *q){
    return q->front == -1;
}

void enQueue(struct queue *q,int val){
    if(isFull(q)){
        printf("Queue is full.\n");
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
        printf("Queue is empty.\n");
        return -1;
    }
    int deQueued = q->arr[q->front];
    if(q->front == q->rear){
        q->front = -1;
        q->rear = -1;
    }else{
        q->front = (q->front+1)%MAX_SIZE;
    }

    return deQueued;
}

int peek(struct queue *q){
    if(isEmpty(q)){
        printf("Queue is empty.\n");
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
    initialise(q);
    enQueue(q,5);
    enQueue(q,6);
    enQueue(q,7);
    enQueue(q,8);
    enQueue(q,9);

    display(q);
    printf("\n");
    deQueue(q);
    display(q);
    printf("\n");

    int topElement = peek(q);
    printf("Top Element: %d \n",topElement);

    return 0;
}