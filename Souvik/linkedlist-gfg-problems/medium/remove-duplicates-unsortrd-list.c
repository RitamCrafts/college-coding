#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

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

struct node *insertNodeFirst(struct node *head,int val){
    struct node *newNode = createNode(val);
    newNode->next = head;
    head = newNode;

    return head;
}

struct node *insertEnd(struct node *head,int val){
    if(isEmpty(head)){
        printf("Linkedlist is emtpy.\n");
        return NULL;
    }

    struct node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    struct node *newNode = createNode(val);
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

struct node *createLL(struct node *head,int val){
    if(isEmpty(head)){
        head = insertNodeFirst(head,val);
    }else{
        head = insertEnd(head,val);
    }

    return head;
}

struct node *removeDuplicates(struct node *head){
    if(isEmpty(head) || head->next == NULL){
        return head;
    }
    struct node *temp = head;
    int arr[MAX_SIZE];
    int j = 0;
    while(temp != NULL){
        arr[j++] = temp->val;
        temp = temp->next;
    }

    int unique_arr[MAX_SIZE];
    int k = 0;
    for(int i = 0; i<j; i++){
        int elem = arr[i];
        int freq = 0;
        for(int m = 0; m<j; m++){
            if(arr[m] == elem){
                freq++;
            }
        }

        if(freq == 1){
            unique_arr[k++] = arr[i];
        }
    }
    struct node *newHead = NULL;
    for(int i = 0; i<k; i++){
        newHead = createLL(newHead,unique_arr[i]);
    }

    return newHead;
}

struct node *removeDuplicatesTwo(struct node *head){
    if(isEmpty(head) || head->next == NULL){
        return head;
    }

    struct node *curr = head;
    while(curr != NULL){
        struct node *prev = curr;
        struct node *temp = curr->next;

        while(temp != NULL){
            if(curr->val == temp->val){
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            }else{
                prev = temp;
                temp = temp->next;
            }
        }

        curr = curr->next;
    }

    return head;

    
}

void printList(struct node *head){
    if(isEmpty(head)){
        printf("Empty Linked list.\n");
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

int main(){
    struct node *head = createNode(5);
    head->next = createNode(2);
    head->next->next = createNode(2);
    head->next->next->next = createNode(4);

    printList(head);
    head = removeDuplicatesTwo(head);
    printList(head);
    return 0;
}