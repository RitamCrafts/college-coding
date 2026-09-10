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
    newNode->next = NULL;

    return newNode;
}

struct node *insertAtFirst(struct node *head, int val){
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

struct node *createLL(struct node *head){
    if(isEmpty(head)){
        int val;
        printf("Enter Value of Node: ");
        scanf("%d",&val);
        head = insertAtFirst(head,val);
    }else{
        int val;
        printf("Enter Value of Node: ");
        scanf("%d",&val);
        head = insertAtEnd(head,val);
    }

    return head;
}

bool findKey(struct node *head, int key){
    if(isEmpty(head)){
        printf("The linkedlist is empty.\n");
        return NULL;
    }

    struct node *temp = head;
    int nodeCount = 0;
    while(temp != NULL){
        nodeCount++;
        if(temp->val == key){
            return true;
        }
        temp = temp->next;
    }
    
    return false;
}

int main(){
    struct node *head = NULL;
    int opt;
    while(true){
        printf("Enter -1 to cancel: \n ");
        scanf("%d",&opt);
        
        if(opt == -1){
            break;
        }
        head = createLL(head);

    }

    int key;
    printf("Enter Key to Search: ");
    scanf("%d",&key);

    if(findKey(head,key)){
        printf("Key Found.\n");
    }else{
        printf("Key Not Found.\n");
    }

    return 0;
}