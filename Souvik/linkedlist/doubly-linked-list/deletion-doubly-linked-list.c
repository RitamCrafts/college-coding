#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *prev;
    struct node *next;
};

struct node *createNode(int val){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->val = val;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

bool isEmpty(struct node *head){
    return head == NULL;
}

bool hasOnlyOneNode(struct node *head){
    return head != NULL && head->next == NULL;
}

struct node *deleteFromBeginning(struct node *head){
    if(isEmpty(head)){
        printf("Linked-list is empty.\n");
        return NULL;
    }
    

    if(hasOnlyOneNode(head)){
        free(head);
        return NULL;
    }

    struct node *temp = head;
    head = head->next;
    head->prev = NULL;

    free(temp);
    return head;
}

struct node *deleteFromEnd(struct node *head){
    if(isEmpty(head)){
        printf("Linked list is empty.\n");
        return NULL;
    }

    if(hasOnlyOneNode(head)){
        free(head);
        return NULL;
    }

    struct node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    struct node *secondLastNode = temp->prev;
    secondLastNode->next = NULL;
    free(temp);
    return head;
}

struct node *deleteNodeWithGivenValue(struct node *head, int val){

    if(isEmpty(head)){
        printf("Linked-list is empty.\n");
        return NULL;
    }

    if(hasOnlyOneNode(head) && head->val == val){
        free(head);
        return NULL;
    }

    struct node *temp = head;

    while(temp != NULL && temp->val != val){
        temp = temp->next;
    }

    if(temp == NULL){
        printf("Node with given value not found.\n");
        return head;
    }

    if(temp == head){
        return deleteFromBeginning(head);
    }

    if(temp->next == NULL){
        return deleteFromEnd(head);
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    free(temp);

    return head;
}

void printList(struct node *head){
    if(isEmpty(head)){
        printf("Linked-list is empty.\n");
        return;
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
        printf("Linked-list is empty.\n");
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
    head->next->next->next = createNode(13);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = createNode(14);
    head->next->next->next->next->prev = head->next->next->next;

    printList(head);
    printListReverse(head);
    printf("\n");

    head = deleteFromBeginning(head);
    printList(head);
    printListReverse(head);
    printf("\n");

    head = deleteFromEnd(head);
    printList(head);
    printListReverse(head);
    printf("\n");

    head = deleteNodeWithGivenValue(head,12);
    printList(head);
    printListReverse(head);
    printf("\n");
    return 0;
}