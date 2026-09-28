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

struct node *insertFirst(struct node *head,int val){
    struct node *newNode = createNode(val);
    newNode->next = head->next;
    head = newNode;
    return head;
}

struct node *insetEnd(struct node *head,int val){
    struct node *newNode = createNode(val);
    if(isEmpty(head)){
        printf("Empty Linkedlist.\n");
        return NULL;
    }

    struct node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// struct node *createLinkedList(struct node *head){
//     if(isEmpty(head)){
//         int val;
//         printf("Enter Node Value: ");
//         scanf("%d",&val);
//         head = insertFirst(head,val);
//     }else{
//         int val;
//         printf("Enter Node Value: ");
//         scanf("%d",&val);
//         head = insetEnd(head,val);
//     }

//     return head;
// }

int lengthLinkedList(struct node *head){
    struct node *temp = head;
    int nodeCount = 0;
    while(temp != NULL){
        nodeCount++;
        temp = temp->next;
    }

    return nodeCount;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// swapping by node value(modifying)
struct node *swapPair(struct node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    struct node *temp = head;
    struct node *nextTemp = head->next;

    while(temp->next != NULL){
        swap(&temp->val, &nextTemp->val);
        temp = nextTemp->next;
        if(temp == NULL || temp->next == NULL){
            break;
        }
        nextTemp = temp->next;
    }

    return head;
}


// swapping by linking the nodes
struct node *swapPairTwo(struct node *head){
    if(isEmpty(head) || head->next == NULL){
        return head;
    }
    struct node *temp = head;
    struct node *nextTemp = temp->next;

    temp->next = nextTemp->next;
    nextTemp->next = temp;
    head = nextTemp;
    temp->next= swapPairTwo(temp->next);

    return head;
}

void printList(struct node *head){
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
    struct node *head = createNode(10);
    head->next = createNode(12);
    head->next->next = createNode(14);
    head->next->next->next = createNode(13);

    printList(head);

    head = swapPair(head);
    printList(head);

    head = swapPairTwo(head);
    printList(head);
    return 0;
}