#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 5
struct Queue {
    int arr[MAX_SIZE];
    int front;
    int rear;
};

void init(struct Queue *q){
    q->front= -1;
    q->rear = -1;
}

bool isFull(struct Queue *q){
    return (q->rear+1)%MAX_SIZE == q->front;
}

bool isEmpty(struct Queue *q){
    return q->front == -1;
}

void enQueue(struct Queue *q, int val){
    if(isFull(q)){
        printf("Queue Overflow.\n");
        return;
    }

    if(isEmpty(q)){
        q->front = 0;
    }

    q->rear = (q->rear+1)%MAX_SIZE;
    q->arr[q->rear] = val;
}

int deQueue(struct Queue *q){
    if(isEmpty(q)){
        printf("Queue Underflow.\n");
        return -1;
    }

    int deQueuedElement = q->arr[q->front];

    if(q->front == q->rear){
        init(q);
    }else{
        q->front = (q->front+1)%MAX_SIZE;
    }

    return deQueuedElement;

}

int peek(struct Queue *q){
    if(isEmpty(q)){
        printf("Queue Underflow.\n");
        return -1;
    }

    int topElement = q->arr[q->front];
    return topElement;
}

void printQueue(struct Queue *q){
    if(isEmpty(q)){
        printf("Queue is Empty.\n");
        return;
    }

    int i = q->front;
    while(i != q->rear){
        printf("%d ",q->arr[i]);
        i = (i+1)%MAX_SIZE;
    }
    printf("%d ",q->arr[q->rear]);
    printf("\n");
}
int main(){
    struct Queue *q = malloc(sizeof(sizeof(struct Queue)));
    init(q);
    int opt;
    while(true){
        printf("\n... MENU ...\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("0. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &opt);

        if(opt == 1){

            int val;

            printf("Enter Value: ");
            scanf("%d", &val);

            enQueue(q, val);

        }
        else if(opt == 2){

            int deQueuedElement = deQueue(q);

            if(deQueuedElement != -1){
                printf("Dequeued Element: %d\n", deQueuedElement);
            }

        }
        else if(opt == 3){

            int topElement = peek(q);

            if(topElement != -1){
                printf("Front Element: %d\n", topElement);
            }

        }
        else if(opt == 4){
            printQueue(q);
        }
        else if(opt == 0){

            printf("Exit.\n");

            free(q);
            return 0;

        }
        else{

            printf("Invalid Choice.\n");

        }
    }
    free(q);
    return 0;
}