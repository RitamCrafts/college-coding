#include <stdio.h>
#include <stdlib.h>

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

struct node *deleteNodeBeginning(struct node *head){
    if(head == NULL) return NULL;
    struct node *temp = head;
    head = head->next;
    free(temp);

    return head;
}

struct node *deleteNodeEnd(struct node *head){
    struct node *p = head->next;
    struct node *q = head;
    while(p->next != NULL){
        p = p->next;
        q = q->next;
    }
    q->next = p->next;
    free(p);
    return head;
}

struct node *deleteNodeWithGivenValue(struct node *head,int val){
    struct node *temp = head->next;
    struct node *q = head;
    while(head == NULL){
        return NULL;
    }
    while(temp->val != val){
        temp = temp->next;
        q = q->next;
    }
    q->next = temp->next;
    free(temp);
    return head;
    
}

void printList(struct node *head){
    if(head == NULL) return;
    struct node *temp = head;

    while(temp != NULL){
        printf("%d ",temp->val);
        if(temp->next != NULL){
            printf(" -> ");
        }
        temp = temp->next;
    }
}

int main(){
    struct node *head = createNode(10);
    head->next = createNode(11);
    head->next->next = createNode(12);
    head->next->next->next = createNode(13);
    head->next->next->next->next = createNode(14);

    printList(head);
    printf("\n");
    head = deleteNodeBeginning(head);
    printList(head);

    printf("\n");
    head = deleteNodeEnd(head);
    printList(head);

    printf("\n");
    head = deleteNodeWithGivenValue(head,12);
    printList(head);
    return 0;
}