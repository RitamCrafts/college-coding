#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int val;
    struct node *next;
};

struct node *createNode(int val){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct node *insertAtFirst(struct node *head , int val){
    struct node *newNode = createNode(val);
    if(head == NULL){
        newNode->next = newNode;
        return newNode;
    }

    struct node *temp = head;
    while(temp->next != head){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
    head = newNode;

    return head;

}

struct node *insertAtEnd(struct node *head,int val){
    struct node *temp = head;
    struct node *q = head->next;

    struct node *newNode = createNode(val);

    while(q->next != head){
        q = q->next;
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = q->next;

    return head;
}

struct node *exchangeFirstAndLastNode(struct node *head){
    struct node *temp = head;
    struct node *q = head->next;

    while(q->next != head){
        q = q->next;
        temp = temp->next;
    }

    struct node *lastNode = q;
    struct node *prevLastNode = temp;

    struct node *newLastNode = lastNode->next;
    struct node *newFirstNode = lastNode;
    newFirstNode->next = head->next;

    prevLastNode->next = newLastNode;
    newLastNode->next = newFirstNode;

    head = newFirstNode;

    return head;
}


void printList(struct node *head){
    struct node *temp = head;
    do
    {
       printf("%d ",temp->val);
       if(temp->next !=  head){
        printf(" -> ");
       }

       temp = temp->next;
    } while (temp != head);
    

    printf("\n");
}

int main(){
    struct node *head = createNode(10);
    head->next = createNode(11);
    head->next->next = createNode(12);
    head->next->next->next = createNode(13);
    head->next->next->next->next = createNode(14);
    head->next->next->next->next->next = head;
    printList(head);

    head = exchangeFirstAndLastNode(head);
    printList(head);
}