#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10000

struct ListNode{
    int val;
    struct ListNode *next;
};

bool isEmpty(struct ListNode *head){
    return head == NULL;
}

struct ListNode *createNode(int val){
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode *insertFirst(struct ListNode *head, int val){
    struct ListNode *newNode = createNode(val);
    newNode->next = head;
    head = newNode;

    return head;
}

struct ListNode *insertEnd(struct ListNode *head, int val){
    if(isEmpty(head)){
        printf("Linked list empty.\n");
        return NULL;
    }

    struct ListNode *temp = head;
    struct ListNode *newNode = createNode(val);
    while(temp->next != NULL){
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
    
}

struct ListNode *createLL(struct ListNode *head,int val){
    if(isEmpty(head)){
        head = insertFirst(head,val);
    }else{
        head = insertEnd(head,val);
    }

    return head;
}

void rotateArray(int arr[], int arrSize, int k){
    int j = 0; 
    int m = 0;
    int s = 0;
    k = k%arrSize;

    int leftArray[arrSize];
    int rightArray[arrSize];
    int newArray[arrSize];
    
    for(int i = 0; i<arrSize-k; i++){
        leftArray[j++] = arr[i];
    }

    for(int i = arrSize-k; i<arrSize; i++){
        rightArray[m++] = arr[i];
    }

    for(int i = 0; i<m; i++){
        newArray[s++] = rightArray[i];
    }

    for(int i = 0; i<j; i++){
        newArray[s++] = leftArray[i];
    }

    for (int i = 0; i < arrSize; i++) {
        arr[i] = newArray[i];
    }

}

struct ListNode *rotateRight(struct ListNode *head, int k){
    if(isEmpty(head) || head->next == NULL || k == 0){
        return head;
    }

    struct ListNode *temp = head;
    int j = 0;
    int arr[MAX_SIZE];

    while(temp != NULL){
        arr[j] = temp->val;
        j++;
        temp = temp->next;
    }
    rotateArray(arr,j,k);
    struct ListNode *result = NULL;
    for(int i = 0; i<j; i++){
        result = createLL(result,arr[i]);
    }

    return result;
}

void display(struct ListNode *head){
    if(isEmpty(head)){
        return;
    }

    struct ListNode *temp = head;
    while(temp!= NULL){
        printf("%d ",temp->val);
        if(temp->next != NULL){
            printf(" -> ");
        }

        temp = temp->next;
    }

    printf("\n");
}

int main(){
    struct ListNode *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    head = rotateRight(head,2);
    display(head);
    return 0;
}