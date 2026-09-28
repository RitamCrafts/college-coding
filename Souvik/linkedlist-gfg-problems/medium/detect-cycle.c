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

bool hasCycle(struct node *head){
    if(isEmpty(head) || head->next == NULL){
        return false;
    }
    struct node *arr[MAX_SIZE];
    struct node *temp = head;
    int j = 0;
    while(temp != NULL){
        for(int i = 0; i<j; i++){
            if(arr[i] == temp){
                return true;
            }

        }
        arr[j++] = temp;
        temp = temp->next;
    }
    return false;
}

int main(){
    struct node *head = createNode(1);
    head->next = createNode(3);
    head->next->next = createNode(4);
    head->next->next->next = createNode(3);

    if(hasCycle(head) == true){
        printf("Has Cycle \n");
    }else{
        printf("No Cycle \n");
    }

    return 0;
}