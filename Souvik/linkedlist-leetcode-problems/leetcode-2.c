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

struct node *insertFirst(struct node *head, int val){
    struct node *newNode = createNode(val);
    newNode->next = head;
    head = newNode;
    return head;
}

struct node *insertEnd(struct node *head, int val){
    if(isEmpty(head)){
        printf("Empty Linkedlist.\n");
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

struct node *createLinkedList(struct node *head,int val){
    if(isEmpty(head)){
        head = insertFirst(head,val);
    }else{
        head = insertEnd(head,val);
    }

    return head;
}

int lengthLinkedList(struct node *head){
    int nodeCount = 0;
    struct node *temp = head;

    while(temp != NULL){
        nodeCount++;
        temp = temp->next;
    }

    return nodeCount;
}

struct node *sumTwoNumbers(struct node *l1, struct node *l2){
    int carry = 0;
    if(isEmpty(l1) || isEmpty(l2)){
        printf("Linked lists are empty.\n");
        return NULL;
    }
    
    int nodeCountOne = lengthLinkedList(l1);
    int nodeCountTwo = lengthLinkedList(l2);
    int arrOne[nodeCountOne];
    int arrTwo[nodeCountTwo];

    struct node *tempOne = l1;
    struct node *tempTwo = l2;
    int i = 0,j = 0;
    while(tempOne != NULL){
        arrOne[i++] = tempOne->val;
        tempOne = tempOne->next;
    }

    while(tempTwo != NULL){
        arrTwo[j++] = tempTwo->val;
        tempTwo = tempTwo->next;
    }

    struct node *newHead = NULL;
    int sum = 0;
    for(int m = 0; m<nodeCountOne || m<nodeCountTwo; m++){
        int digitOne,digitTwo;
        if(m<nodeCountOne){
            digitOne = arrOne[m];
        }else{
            digitOne = 0;
        }

        if(m<nodeCountTwo){
            digitTwo = arrTwo[m];
        }else{
            digitTwo = 0;
        }
        sum = digitOne+digitTwo+carry;
        int resultDigit = sum%10;
        carry = sum/10;

        newHead = createLinkedList(newHead,resultDigit);


    }

    if(carry != 0){
        newHead = createLinkedList(newHead,carry);
    }

    return newHead;
}

void printLinkedList(struct node *head){
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
    struct node *l1 = createNode(9);
    l1->next = createNode(9);
    l1->next->next = createNode(9);

    struct node *l2 = createNode(5);
    l2->next = createNode(6);
    l2->next->next = createNode(4);

    struct node *newHead = NULL;
    newHead = sumTwoNumbers(l1,l2);
    printLinkedList(newHead);

    return 0;
}