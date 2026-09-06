#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *prev;
    struct node *next;
};

struct node *createNode(int val){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode->val = val;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

struct node *insertAtBeginning(struct node *head, int val){
    struct node *newNode = createNode(val);
    if(head == NULL){
        newNode->prev = newNode;
        newNode->next = newNode;
        head = newNode;
    }else{
        struct node *lastNode = head->prev;
        newNode->next = head;
        lastNode->next = newNode;
        newNode->prev = lastNode;
        head->prev = newNode;

        head = newNode;
    }

    return head;
}

struct node *insertAtEnd(struct node *head, int val){
    struct node *newNode = createNode(val);
    if(head == NULL){
        newNode->prev = newNode;
        newNode->next = newNode;
        head = newNode;
    }else{
        struct node *lastNode = head->prev;
        lastNode->next = newNode;
        newNode->prev = lastNode;
        newNode->next = head;
        head->prev = newNode;
    }

    return head;
}

struct node *insertNodeAfteraNodeWithGivenVal(struct node *head, int val, int nodeValue){
    struct node *newNode = createNode(val);
    if(head == NULL){
        newNode->prev = newNode;
        newNode->next = newNode;
        return newNode;
    }

    struct node *temp = head;

    while(temp->val != nodeValue){
        temp = temp->next;
        if(temp == head){
            printf("Node with value %d not found in the list.\n", nodeValue);
            free(newNode);
            return head;
        }
    }
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
    
    return head;
}

void printList(struct node *head){
    if(head == NULL){
        printf("Linked list is empty.\n");
        return;
    }

    struct node *temp = head;
    do
    {
        printf("%d ",temp->val);
        if(temp->next != head){
            printf(" -> ");
        }
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void printListReverse(struct node *head){
    if(head == NULL){
        printf("Linked list is empty.\n");
        return;
    }

    struct node *lastNode = head->prev;
    struct node *temp = lastNode;

    do
    {
        printf("%d ",temp->val);
        temp = temp->prev;
        if(temp != lastNode){
            printf(" <- ");
        }
    } while (temp != lastNode);
    printf("\n");
    
}

int main(){
    struct node *head = createNode(10);
    head->next = createNode(11);
    head->next->prev = head;
    head->next->next = createNode(12);
    head->next->next->prev = head->next;
    head->next->next->next = createNode(13);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = head;
    head->prev = head->next->next->next;

    printList(head);
    printListReverse(head);

    printf("\n");

    head = insertAtBeginning(head,8);
    printList(head);
    printListReverse(head);

    printf("\n");

    head = insertAtEnd(head,14);
    printList(head);
    printListReverse(head);

    printf("\n");
    head = insertNodeAfteraNodeWithGivenVal(head,20,11);
    printList(head);
    printListReverse(head);


    return 0;
}