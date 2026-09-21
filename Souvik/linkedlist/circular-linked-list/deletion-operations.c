#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node *createNode(int val){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = val;
    newNode->next = NULL;

    return newNode;
}

struct node *deleteNodeBeginning(struct node *head){
    struct node *temp = head;
    struct node *oldHead = head;

    while(temp->next != head){
        temp = temp->next;
    }

    head = head->next;
    temp->next = head;
    free(oldHead);

    return head;
}

struct node *deleteNodeEnd(struct node *head){

    if(head == NULL){
        return NULL;
    }
    if(head->next == head){
        free(head);
        return NULL;
    }
    struct node *temp = head;
    struct node *nextTemp = head->next;

    while(nextTemp->next != head){
        nextTemp = nextTemp->next;
        temp = temp->next;
    }
    temp->next = head;
    free(nextTemp);
    return head;
}

struct node *deleteNodeWithaGivenValue(struct node *head,int val){
    struct node *temp = head;
    struct node *q = head->next;
    while(temp->next != head){
        if(q->info == val){
            temp->next = q->next;
            free(q);
            break;
        }
        temp = temp->next;
        q = q->next;
    }

    return head;
}

void printList(struct node *head){
    struct node *temp = head;

    if(head == NULL){
        printf("List is empty\n");
        return;
    }

    do
    {
        printf("%d ",temp->info);
        temp = temp->next;
    } while (temp != head);
}

int main(){
    struct node *head = createNode(10);
    head->next = createNode(11);
    head->next->next = createNode(12);
    head->next->next->next = createNode(13);
    head->next->next->next->next = createNode(14);
    head->next->next->next->next->next = head;
    printList(head);

    printf("\n");
    head = deleteNodeBeginning(head);
    printList(head);
    printf("\n");
    head = deleteNodeEnd(head);
    printList(head);
    printf("\n");
    head = deleteNodeWithaGivenValue(head, 11);
    printList(head);
    printf("\n");
    
    return 0;
}