#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


struct node {
    int val;
    struct node *next;
};

struct queue {
    struct node *front;
    struct node *rear;
};

struct queue* initQueue(struct queue *q){
    q->front=NULL;
    q->rear=NULL;
}

struct queue *enQueue(struct queue *q,int val){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->next=NULL;
    newNode->val=val;
    if(q->rear==NULL){
        q->front=newNode;
        q->rear=newNode;
        return q;
    }
    q->rear->next=newNode;
    q->rear=newNode;
    return q;
};


struct queue *deQueue(struct queue *q){
    if(q->front==NULL){
        printf("\nQueue Underflow\n");
        return q;
    }
    struct node *temp=q->front;
    q->front=q->front->next;
    if(q->front==NULL){
        q=initQueue(q);
    }
    free(temp);
    return q;
};


void display(struct queue *q){
    struct node *ptr=q->front;
    printf("\nQueue:\n");
    while(ptr!=NULL){
        printf("%d\n",ptr->val);
        ptr=ptr->next;
    }
}

void main(){
    struct queue *myQueue=(struct queue*)(malloc(sizeof(struct queue)));
    myQueue=initQueue(myQueue);

    while(true){
        int op,val;
        printf("\n\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&op);
        switch(op){
        case 1:
            printf("Enter value to enqueue:");
            scanf("%d",&val);
            myQueue=enQueue(myQueue,val);
            break;
        case 2:
            myQueue=deQueue(myQueue);
            printf("\nDequeue success\n");
            break;
        case 3:
            display(myQueue);
            break;
        case 4:
            return;

        }
    }
}
