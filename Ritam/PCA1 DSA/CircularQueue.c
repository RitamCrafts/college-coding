#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 4

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void reset(){
    front = -1;
    rear = -1;
}

bool isFull(){
    if(((rear+1)%MAX_SIZE)==front)
        return true;
    else
        return false;
}

bool isEmpty(){
    if(front == -1)
        return true;
    else
        return false;
}

void enQueue(int data){
    if(isFull()){
        printf("Overflow");
        return;
    }
    if(front==-1) front = 0;
    rear=(rear+1)%MAX_SIZE;
    queue[rear]=data;
}

void deQueue(){
    if(isEmpty()){
        printf("Underflow");
        return;
    }
    if(front==rear){
        front=-1;
        rear=-1;
        return;
    }
    front = (front+1)%MAX_SIZE;
}

void displayQueue(){
    if(isEmpty()){
        printf("Underflow");
        return;
    }
    int i=front;
    printf("Queue:\n");
    while(true){
        printf("%d\n",queue[i]);
        if(i==rear) break;
        i=(i+1)%MAX_SIZE;
    }
}

int main(){
    int op=0,data;
    while(true){
        printf("\n\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter:");
        scanf("%d",&op);
        switch(op){
            case 1:
                printf("Enter data:");
                scanf("%d",&data);
                enQueue(data);
                break;
            case 2:
                deQueue();
            case 3:
                displayQueue();
                break;
            case 4:
                return 0;
        }
    }
    return 0;
}