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

struct node *insertAtFirst(struct node *head, int val){
    struct node *newNode = createNode(val);
    newNode->next = head;
    head = newNode;
    return head;
}

struct node *insertAtEnd(struct node *head, int val){
    if(isEmpty(head)){
        printf("Linkedlist is empty.\n");
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

struct node *createLL(struct node *head){
    if(isEmpty(head)){
        int val;
        printf("Enter Node value: ");
        scanf("%d",&val);
        head = insertAtFirst(head,val);
    }else{
        int val;
        printf("Enter Node value: ");
        scanf("%d",&val);
        head = insertAtEnd(head,val);
    }

    return head;
}

int occurence(struct node *head, int key){
    if(isEmpty(head)){
        printf("The Linkedlist is empty.\n");
        return -1;
    }

    int count = 0;
    struct node *temp = head;
    while (temp != NULL)
    {
        if(temp->val == key){
            count++;
        }
        temp = temp->next;
    }

    return count;
    
}

void displayLinkedList(struct node *head){
    if(isEmpty(head)){
        printf("Linkedlist is empty.\n");
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
    struct node *head = NULL;
    int opt;
    while(true){
        
        printf("\n .... MENU .... \n");
        printf("1. Create Linked List\n");
        printf("2. Count Occurences of a given key.\n");
        printf("3. Print Linked list\n");
        printf("4. Exit\n");

        printf("\n Enter Your Choice. \n");
        scanf("%d",&opt);

        switch (opt)
        {
        case 1:
            head = createLL(head);
            break;
        
        case 2: {
            int key;
            printf("Enter Key to count occurences: ");
            scanf("%d",&key);
            int count = occurence(head,key);
            if(count != -1){
                printf("Count of %d is %d \n",key,count);
            }
            break;
        }

        case 3:
            displayLinkedList(head);
            break;

        case 4:
            printf("Exit Successfull.\n");
            return -1;
        default:
            break;
        }
    }
    return 0;
}