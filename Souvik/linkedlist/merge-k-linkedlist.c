#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

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

bool isEmpty(struct node *head){
    return head == NULL;
}

struct node *insertFirst(struct node *head, int val){
    struct node *newNode = createNode(val);
    newNode->next = head;
    head = newNode;

    return head;
}



struct node *insertEnd(struct node *head, int val){
    if(isEmpty(head)){
        printf("Linked list is Empty.\n");
        return NULL;
    }

    struct node *newNode = createNode(val);
    struct node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

struct node *createLinkedList(struct node *head,int val){
    if(isEmpty(head)){
        
        head = insertFirst(head,val);
    }else{
        
        head = insertEnd(head,val);
    }

    return head;
}

struct node *mergeKLists(struct node **head,int listSize){
    if(head == NULL) {
        return NULL;
    }
    int arr[MAX_SIZE];
    int j = 0;
    for(int i = 0; i<listSize; i++){
        struct node *temp = head[i];
        while(temp != NULL){
            arr[j] = temp->val;
            j++;
            temp = temp->next;
        }
    }
    for(int i = 0; i<j; i++){
        for(int k = 0; k<j-i-1; k++){
            if(arr[k]>arr[k+1]){
                int temp = arr[k];
                arr[k] = arr[k+1];
                arr[k+1] = temp;
            }
        }
    }

    struct node *sortedHead = NULL;
    for(int i = 0; i<j; i++){
        sortedHead = createLinkedList(sortedHead,arr[i]);
    }
    return sortedHead;
}

struct node *mergeTwoLinkedListSorted(struct node *headOne, struct node *headTwo){
    if(headOne == NULL){
        return headTwo;
    }

    if(headTwo == NULL){
        return headOne;
    }

    if(headOne == NULL && headTwo == NULL){
        return NULL;
    }

    struct node *tempOne = headOne;
    struct node *tempTwo = headTwo;

    struct node *result = NULL;

    while(tempOne != NULL && tempTwo != NULL){
        if(tempOne->val < tempTwo->val){
            result = createLinkedList(result,tempOne->val);
            tempOne = tempOne->next;
        }else{
            result = createLinkedList(result,tempTwo->val);
            tempTwo = tempTwo->next;
        }
    }

    while(tempOne != NULL){
        result = createLinkedList(result,tempOne->val);
        tempOne = tempOne->next;
    }

    while (tempTwo != NULL)
    {
        result = createLinkedList(result,tempTwo->val);
        tempTwo = tempTwo->next;
    }
    

    return result;
}

struct node *mergeKListSortedOptimal(struct node **head, int listSize){
    if(head == NULL || listSize == 0){
        return NULL;
    }

    struct node *result = mergeTwoLinkedListSorted(head[0],head[1]);
    for(int i = 2; i<listSize; i++){
        result = mergeTwoLinkedListSorted(head[i],head[i+1]);
    }

    struct node *newResult = mergeKListSortedOptimal(head,listSize);
    return newResult;
}

void display(struct node *head){
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
    struct node *headOne = createNode(10);
    headOne->next = createNode(11);
    headOne->next->next = createNode(12);
    headOne->next->next->next = createNode(13);

    struct node *headtwo = createNode(14);
    headtwo->next = createNode(16);
    headtwo->next->next = createNode(18);
    headtwo->next->next->next = createNode(20);

    struct node *headThree = createNode(222);
    headThree->next = createNode(224);

    struct node *headFour = createNode(11);
    headFour->next = createNode(106);
    headFour->next->next = createNode(108);

    struct node *lists[] = {
        headOne,headtwo,headThree,headFour
    };

    int listSize = 4;
    struct node *newHead = NULL;

    // newHead = mergeKLists(lists,listSize);
    // display(newHead);

    newHead = mergeKListSortedOptimal(lists,listSize);
    display(newHead);
    return 0;
}