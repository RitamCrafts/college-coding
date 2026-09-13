#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};

bool isempty(struct node *head){
    return head == NULL;
}

struct node *createNode(int val){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->val = val;
    newNode->next = NULL;

    return newNode;
}

struct node *insertAtFirst(struct node *head, int val){
    struct node *newNode = createNode(val);
    newNode->next = head;
    head = newNode;

    return head;
}

struct node *insertAtEnd(struct node *head, int val){
    if(isempty(head)){
        printf("Linkedlist is empty.\n");
        return NULL;
    }

    struct node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    struct node *newNode = createNode(val);
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

struct node *createList(struct node *head){
    if(isempty(head)){
        int val;
        printf("Enter Value of Node: ");
        scanf("%d",&val);
        head = insertAtFirst(head,val);
    }else{
        int val;
        printf("Enter Value of Node: ");
        scanf("%d",&val);
        head = insertAtEnd(head,val);
    }

    return head;
}

struct node *deleteNodeWithGivenKey(struct node *head, int key){

    if(isempty(head)){
        printf("Linkedlist is empty.\n");
        return NULL;
    }

    if(head->val == key){
        struct node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct node *temp = head;
    struct node *q = head->next;

    while(q != NULL && q->val != key){
        temp = q;
        q = q->next;
    }

    if(q == NULL){
        printf("Key not found.\n");
        return head;
    }

    temp->next = q->next;
    free(q);

    return head;
}

void display(struct node *head){

    if(isempty(head)){
        printf("Linkedlist is empty.\n");
        return;
    }

    struct node *temp = head;

    printf("Linkedlist: ");

    while(temp != NULL){
        printf("%d -> ", temp->val);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main(){
    int opt;
    struct node *head = NULL;
    while(true){
        printf("\n Enter 1 to create linkedlist: \n");
        printf("\n Enter 2 to delete key from linkedlist: \n");
        printf("\n Enter 3 to display linkedlist: \n");
        printf("\n Enter -1 to cancel: \n ");

        scanf("%d",&opt);

        switch (opt)
        {
        case 1:
            head = createList(head);
            break;

        case 2: {
            int value;
            printf("Enter Value of key: ");
            scanf("%d", &value);
            head = deleteNodeWithGivenKey(head, value);
            break;
        }

        case 3:
            display(head);
            break;

        case -1:
            printf("Exitted successfully.\n");
            return -1;
        
        default:
            printf("Invalid choice.\n");
            break;
        }
    }
    return 0;
}