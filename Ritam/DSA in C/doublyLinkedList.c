#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

void insertNodeStart(struct node **head, int data) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void insertNodeEnd(struct node **head, int data){
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;

    if(*head==NULL){
        newNode->prev=NULL;
        *head=newNode;
    }
    else{
        struct node *ptr = *head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=newNode;
        newNode->prev=ptr;
    }
}

void insertNodeAt(struct node **head, int data, int position){
    if(position==0){
        insertNodeStart(head,data);
        return;
    }
    if(*head==NULL){
        printf("List is Empty!");
        return;
    }
    int count=0;
    struct node *ptr=*head;
    while(1){
        if(ptr==NULL){
            printf("Position doesn't exist!");
            return;
        }
        if(count==position){
            break;
        }
        ptr=ptr->next;
        count++;
    }
    struct node *newNode=malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=ptr;
    newNode->prev=ptr->prev;
    ptr->prev->next=newNode;
    ptr->prev=newNode;
}





void longDisplay(struct node **head){
    struct node *ptr = *head;
    int i=0;
    if(ptr!=NULL) printf("DOUBLY LINKED LIST\n");
    while(ptr!=NULL){
        i++;
        printf("%d. %p\t%d\n",i,(void*)ptr,ptr->data);
        ptr = ptr->next;
    }
}

void display(struct node *head){
    struct node *ptr = head;
    int i=0;
    if(ptr!=NULL) printf("DOUBLY LINKED LIST\n");
    while(ptr!=NULL){
        i++;
        printf("%d. %d\n",i,ptr->data);
        ptr = ptr->next;
    }
}