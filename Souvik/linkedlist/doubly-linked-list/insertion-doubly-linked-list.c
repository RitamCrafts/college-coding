#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int val;
    struct node *prev;
    struct node *next;
};

bool isEmpty(struct node *head){
    return head == NULL;
}

struct node *createNode(int val){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->prev = NULL;
    newNode->next = NULL;
    newNode->val = val;

    return newNode;
}

struct node *insertAtBeginning(struct node *head, int val){
    struct node *newNode = createNode(val);
    newNode->next = head;

    if(head != NULL){
        head->prev = newNode;
    }
    
    head = newNode;

    return head;
}

struct node *insertAtEnd(struct node *head, int val){
    if(isEmpty(head)){
        printf("Linked-list is empty.\n");
        return NULL;
    }

    struct node *temp = head;
    struct node *newNode = createNode(val);

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

struct node *insertAfterSpecificNodeWithGivenValue(struct node *head, int val, int nodeValue){
    if(isEmpty(head)){
        printf("Linked list is empty.\n");
        return NULL;
    }

    struct node *temp = head;
    struct node *newNode = createNode(val);

    while(temp!= NULL && temp->val != nodeValue){
        temp = temp->next;
    }

    if(temp == NULL){
        printf("Node not found.\n");
        return head;
    }
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

void printList(struct node *head){
    if(isEmpty(head)){
        printf("Linked list is empty.\n");
        return ;
    }
    struct node *temp = head;
    while(temp != NULL){
        printf("%d ",temp->val);
        if(temp->next != NULL){
            printf(" -> ");
        }
        temp = temp->next;
    }

    printf("\n");
}

void printListReverse(struct node *head){
    if(isEmpty(head)){
        printf("Linkedlist empty.\n");
        return;
    }
    struct node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    while(temp != NULL){
        printf("%d ",temp->val);
        if(temp->prev != NULL){
            printf(" <- ");
        }
        temp = temp->prev;
    }
    printf("\n");

}

int main(){
    struct node *head = createNode(10);
    head->next = createNode(11);
    head->next->prev = head;
    head->next->next = createNode(12);
    head->next->next->prev = head->next;

    printList(head);

    printf("\n");

    head = insertAtBeginning(head,8);
    printList(head);
    printf("\n");

    head = insertAtEnd(head,13);
    printList(head);
    printf("\n");

    head = insertAfterSpecificNodeWithGivenValue(head,9,11);
    printList(head);
    printf("\n");
    printListReverse(head);
    printf("\n");
    return 0;
}