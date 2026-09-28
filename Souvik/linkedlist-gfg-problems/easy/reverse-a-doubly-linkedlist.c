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
    newNode->val = val;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

struct node *insertFirst(struct node *head, int val){
    struct node *newNode = createNode(val);
    if(isEmpty(head)){
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;

    return head;
}

struct node *insertEnd(struct node *head, int val){
    if(isEmpty(head)){
        printf("Empty Linked list.\n");
        return NULL;
    }

    struct node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    struct node *lastNode = temp;
    struct node *newNode = createNode(val);
    lastNode->next = newNode;
    newNode->prev = lastNode;

    return head;
}

struct node *createLinkedList(struct node *head){
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

void printListReverse(struct node *head){
    if(isEmpty(head)){
        printf("Empty Linked list.\n");
        return;
    }

   struct node *temp = head;
   while(temp->next != NULL){
        temp = temp->next;
   }

   struct node *lastNode = temp;

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
    struct node *head = NULL;
    int opt;
    while(true){
        printf("\n .... MENU .... \n");
        printf("\n 1 for creating Linked List.\n ");
        printf("\n 2 for printing it reverse. \n");
        printf("\n 3 for exit. \n");

        printf("Enter Your Choice: ");
        scanf("%d",&opt);

        switch(opt){
            case 1:
                head = createLinkedList(head);
                break;
            case 2:
                printListReverse(head);
                break;
            case 3:
                return -1;
            
            default:
                printf("Invalid Choice.\n");
                break;
            
        }
    }

    return 0;
}