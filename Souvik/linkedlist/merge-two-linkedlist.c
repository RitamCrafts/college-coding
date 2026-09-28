#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *createNode(int val){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    return newNode;
}

bool isEmpty(struct node *head){
    return head == NULL;
}

struct node *insertFirst(struct node *head, int val){
    struct node *newNode = createNode(val);
    newNode->next = head;
    head = newNode;

    return head;
}

struct node *insertEnd(struct node *head, int val){
    if(isEmpty(head)){
        printf("Linkedlist is empty.\n");
        return NULL;
    }

    struct node *temp = head;
    struct node *newNode = createNode(val);
    while(temp->next != NULL){
        temp = temp->next;

    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

struct node *createLL(struct node *head){
    if(isEmpty(head)){
        int val;
        printf("Enter Node Value: ");
        scanf("%d",&val);
        head = insertFirst(head,val);
    }else{
        int val;
        printf("Enter Node Value: ");
        scanf("%d",&val);
        head = insertEnd(head,val);
    }

    return head;

}

struct node *mergeTwoLinkedList(struct node *headOne, struct node *headTwo){
    if(isEmpty(headOne)){
        return headTwo;
    }

    if(isEmpty(headTwo)){
        return headOne;
    }

    if(isEmpty(headOne) && isEmpty(headTwo)){
        return NULL;
    }

    struct node *tempOne = headOne;
    while(tempOne->next != NULL){
        tempOne = tempOne->next;
    }

    tempOne->next = headTwo;

    return headOne;
}


void display(struct node *head){
    if(isEmpty(head)){
        printf("Empty Linked list.\n");
        return;
    }
    struct node *temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        if(temp->next != NULL){
            printf(" -> ");
        }

        temp = temp->next;
    }

    printf("\n");
}

int main(){
    struct node *headOne = createNode(10);
    headOne->next = createNode(12);
    headOne->next->next = createNode(14);
    headOne->next->next->next = createNode(16);

    struct node *headTwo = createNode(18);
    headTwo->next = createNode(20);
    headTwo->next->next = createNode(22);
    headTwo->next->next->next = createNode(24);

    headOne = mergeTwoLinkedList(headOne,headTwo);
    display(headOne);

    return 0;
}