#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
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
};

struct node *deleteNodeBeginning(struct node *head){
    if(head == NULL){
        printf("Linked list is empty.\n");
        return NULL;
    }

    if (head->next == head) {
        free(head);
        return NULL;
    }

    struct node *temp = head;
    struct node *lastNode = head->prev;

    head = head->next;
    lastNode->next = head;
    head->prev = lastNode;
    free(temp);

    return head;
}

struct node *deleteNodeEnd(struct node *head){
    if(head == NULL){
        printf("Linked list is empty.\n");
        return NULL;
    }

    if(head->next == head){
        free(head);
        return NULL;
    }
    struct node *lastNode = head->prev;
    struct node *prevLastNode = lastNode->prev;

    prevLastNode->next = head;
    head->prev = prevLastNode;
    free(lastNode);
    return head;
}

struct node *deleteNodeWithaGivenValue(struct node *head, int nodeValue){
    if(head == NULL){
        printf("Linked list is empty.\n");
        return NULL;
    }

    struct node *temp = head;
    do {
        if (temp->val == nodeValue) {
            break;
        }

        temp = temp->next;

    } while (temp != head);
    if (temp->val != nodeValue) {
        printf("No node found with value %d in linkedlist.\n", nodeValue);
        return head;
    }

    if (temp->next == temp) {
        free(temp);
        return NULL;
    }
    
    struct node *deletedNode = temp;

    deletedNode->prev->next = deletedNode->next;
    deletedNode->next->prev = deletedNode->prev;

    if (deletedNode == head) {
        head = deletedNode->next;
    }

    free(deletedNode);

    return head;
}

void printList(struct node *head){
    if(head == NULL){
        printf("Linked list is empty.\n");
        return;
    }
    
    struct node *temp = head;
    do
    {
        printf("%d ",temp->val);
        if(temp->next != head){
            printf(" -> ");
        }
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void printListReverse(struct node *head){
    if(head == NULL){
        printf("Linked list is empty.\n");
        return;
    }

    struct node *lastNode = head->prev;
    struct node *temp = lastNode;

    do
    {
        printf("%d ",temp->val);
        temp = temp->prev;
        if(temp != lastNode){
            printf(" <- ");
        }
    } while (temp != lastNode);
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
    head->next->next->next->next = head;
    head->prev = head->next->next->next;

    printList(head);
    printListReverse(head);

    printf("\n");
    head = deleteNodeBeginning(head);
    printList(head);
    printListReverse(head);
    printf("\n");
    head = deleteNodeEnd(head);
    printList(head);
    printListReverse(head);
    printf("\n");
    head = deleteNodeWithaGivenValue(head,120);
    printList(head);
    printListReverse(head);

}