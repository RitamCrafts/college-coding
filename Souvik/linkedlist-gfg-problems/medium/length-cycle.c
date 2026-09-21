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


int lengthOfLoop(struct node *head){
    if(isEmpty(head) || head == NULL){
        return 0;
    }
    struct node *arr[MAX_SIZE];
    struct node *temp = head;
    int j = 0;
    while(temp != NULL){
        for(int i = 0; i<j; i++){
            if(arr[i] == temp){
                return j-i;
            }
        }
        arr[j++] = temp;
        temp = temp->next;
    }

    return 0;
}


int main(){
    struct node *head = createNode(25);
    head->next = createNode(14);
    head->next->next = createNode(19);
    head->next->next->next = createNode(33);
    head->next->next->next->next = createNode(10);
    head->next->next->next->next->next = head->next->next;
    int length = lengthOfLoop(head);
    printf("%d \n",length);
    return 0;
}