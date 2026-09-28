#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


struct node {
    int val;
    struct node *next;
};

struct node *push(struct node *top,int val){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->next=top;
    newNode->val=val;
    top=newNode;
    return top;
};

struct node *pop(struct node *top){
    if(top==NULL){
        printf("\nStack Underflow\n");
        return top;
    }
    struct node *temp=top;
    top=top->next;
    free(temp);
    return top;
};

int peek(struct node *top){
    if(top==NULL){
        printf("\nStack Underflow\n");
        return -9999;
    }
    return top->val;
};

void display(struct node *top){
    struct node *ptr=top;
    printf("\nStack:\n");
    while(ptr!=NULL){
        printf("%d\n",ptr->val);
        ptr=ptr->next;
    }
}

void main(){
    struct node *myStack=NULL;
    while(true){
        int op,val;
        printf("\n\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&op);
        switch(op){
        case 1:
            printf("Enter value to push:");
            scanf("%d",&val);
            myStack=push(myStack,val);
            break;
        case 2:
            val=peek(myStack);
            myStack=pop(myStack);
            printf("Popped value:%d",val);
            break;
        case 3:
            val=peek(myStack);
            printf("Top value:%d",val);
            break;
        case 4:
            display(myStack);
            break;
        case 5:
            return;
        default:
            printf("\nWrong Choice\n");

        }
    }
}
