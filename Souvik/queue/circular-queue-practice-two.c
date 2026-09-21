#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 100

struct queue {
    int arr[MAX_SIZE];
    int front;
    int rear;
};

void inti(struct queue *q){
    q->front = -1;
    q->rear = -1;
}

bool isFull(struct queue *q){
    return (q->rear+1)%MAX_SIZE == q->front;
}

bool isEmpty(struct queue *q){
    return q->front == -1;
}


int main(){
    
    return 0;
}