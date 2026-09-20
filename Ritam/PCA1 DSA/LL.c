#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *insertStart(struct node *head,int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->next=head;
    newNode->data=data;
    head=newNode;
    return head;
}

struct node *insertEnd(struct node *head,int data){
    if(head==NULL){
        head = insertStart(head,data);
        return head;
    }
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->next=NULL;
    newNode->data=data;
    struct node *ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=newNode;
    return head;
}

struct node *insertMultiple(struct node *head){
    int data;
    printf("Enter Linked List(-1 to exit):\n");
    while(1){
        scanf("%d",&data);
        if(data==-1){
            break;
        }
        head=insertEnd(head,data);
    }
    return head;
}

void display(struct node *head){
    printf("Linked List:\n");
    struct node *ptr=head;
    int c=1;
    while(ptr->next!=NULL){
        printf("%d. %d\n",c,ptr->data);
        ptr=ptr->next;
        c++;
    }
}

int main(){
    struct node* myLL=NULL;
    myLL=insertMultiple(myLL);
    display(myLL);
    return 0;
}