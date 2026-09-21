#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct node{
    int val;
    struct node *next;
};

struct node *createNode(int val){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->val = val;
    newNode->next = NULL;

    return newNode;
}

struct node *insertNodeAtBeginning(struct node *head,int val){
    struct node *newNode = createNode(val);
    newNode->next = head;
    head = newNode;

    return head;
}

struct node *insertNodeAtEnd(struct node *head,int val){

    struct node *newNode = createNode(val);

    if(head == NULL) return newNode;
    struct node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;

    return head;
}

struct node *insertNodeBeforeANodeWithGivenValue(struct node *head,int value,int nodeValue){
    struct node *temp = head;
    while(temp != NULL && temp->next != NULL && temp->next->val != nodeValue){
        temp = temp->next;
    }
    struct node *newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

void printList(struct node *head){
    struct node *temp = head;
    if(head == NULL){
        return;
    }
    while(temp != NULL){
        printf("%d ",temp->val);
        if(temp->next != NULL){
            printf(" -> ");
        }

        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct node *head = createNode(10);
    head->next = createNode(11);
    head->next->next = createNode(12);

    int value;
    printf("Enter Value for insertion at beggining: ");
    scanf("%d",&value);
    head = insertNodeAtBeginning(head,value);

    printList(head);

    printf("\n");
    int val2;
    printf("Enter Value for node insertion at end: ");
    scanf("%d",&val2);
    head = insertNodeAtEnd(head,val2);
    printList(head);

    printf("\n");
    head = insertNodeBeforeANodeWithGivenValue(head,8,11);
    printList(head);
}