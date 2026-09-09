#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct node {
    int val;
    struct node *next;
};

bool isEmpty(struct node *head){
    return head == NULL;
}

struct node *createNode(int val){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->val = val;
    newNode->next= NULL;

    return newNode;
}

struct node *insertAtFirst(struct node *head,int val){
    struct node *newNode = createNode(val);
    newNode->next = head;
    head = newNode;

    return head;
}

struct node *insertAtEnd(struct node *head, int val){
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

struct node *insertNodeAfterPos(struct node *head,int val, int position){
   struct node *newNode = createNode(val) ;

   if(isEmpty(head)){
     printf("Linked list is empty.\n");
   }

   struct node *temp = head;
   int positionCount = 0;
   while(temp->next != NULL){
        temp = temp->next;
        positionCount++;
        if(positionCount == position){
            break;
        }
   }
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

int lengthCount(struct node *head){
    struct node *temp = head;
    int nodeCount = 0;
    while(temp != NULL){
        nodeCount++;
        temp = temp->next;
    }

    return nodeCount;
}

int main(){
    struct node *head = createNode(10);
    head->next = createNode(12);
    head->next->next = createNode(14);

    head = insertNodeAfterPos(head,4,1);
    printList(head);
    int length = lengthCount(head);
    printf("Length: %d \n",length);
    return 0;
}