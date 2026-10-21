#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
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
        return NULL;
    }

    struct ListNode *newNode = createNode(val);
    struct ListNode *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

struct ListNode *createLL(struct ListNode *head, int val){
    if(isEmpty(head)){
        head =insertFirst(head,val);
    }else{
        head = insertEnd(head,val);
    }

    return head;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(headA == NULL || headB == NULL){
        return NULL;
    }

    struct ListNode *tempOne = headA;
    while(tempOne != NULL){
        struct ListNode *tempTwo = headB;
        while(tempTwo != NULL){
            if(tempOne == tempTwo){
                return tempOne;
            }

            tempTwo = tempTwo->next;
        }

        tempOne = tempOne->next;
    }

    return NULL;
}

int main(){
    struct ListNode *headA = createNode(4);
    headA->next = createNode(1);
    headA->next->next = createNode(8);
    headA->next->next->next = createNode(4);
    headA->next->next->next->next = createNode(5);
    struct ListNode *headB = createNode(5);
    headA->next = createNode(6);
    headA->next->next = createNode(1);
    headA->next->next->next = createNode(8);
    headA->next->next->next->next = createNode(4);
    headA->next->next->next->next->next = createNode(5);

    struct ListNode *result = getIntersectionNode(headA,headB);
    printf("%d \n",result->val);
    return 0;
}