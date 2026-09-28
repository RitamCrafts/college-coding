#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node *createNode(int val){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = val;
    newNode->next = NULL;

    return newNode;
}


struct node *insertNodeBeginning(struct node *head,int val){
    struct node *newNode = createNode(val);
    struct node *temp = head;

    if(head == NULL){
        newNode->next = newNode;
        return newNode;
    }


    while(temp->next != head){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
    head = newNode;

    return head;
}

struct node *insertAfterNodeWithGivenValue(struct node *head, int val, int nodeValue){
    struct node *temp = head;
    
    if(head == NULL) return head;

    struct node *newNode = createNode(nodeValue);
    do
    {
        if(temp->info == val){
            newNode->next = temp->next;
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    } while (temp != head);


    free(newNode);
    return head;
    
}


struct node *insertNodeAtEnd(struct node *head, int val){
    struct node *temp = head;
    struct node *q = head->next;
    struct node *newNode = createNode(val);

    while(q->next != head){
        q = q->next;
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = q->next;

    return head;

}

void printList(struct node *head){
    struct node *temp = head;
    do{ 
        printf("%d ",temp->info);
        temp = temp->next;
        
    }while(temp != head);
}
int main(){
    struct node *head = createNode(11);
    head->next = createNode(12);
    head->next->next = createNode(13);
    head->next->next->next = head;

    printList(head);
    printf("\n");
    head = insertNodeBeginning(head,4);
    printList(head);
    printf("\n");
    head = insertNodeAtEnd(head,14);
    printList(head);

    printf("\n");
    head = insertAfterNodeWithGivenValue(head,11,10);
    printList(head);
    
    return 0;
}