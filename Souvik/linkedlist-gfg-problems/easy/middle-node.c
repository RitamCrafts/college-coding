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

struct node *insertAtFirst(struct node *head,int val){
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
        printf("Enter Node Value: ");
        scanf("%d",&val);

        head = insertAtFirst(head,val);
    }else{
        int val;
        printf("Enter Node Value: ");
        scanf("%d",&val);

        head = insertAtEnd(head,val);
    }

    return head;
}

int lengthLinkedList(struct node *head){


    int nodeCount = 1;

    if(isEmpty(head)){
        nodeCount = 0;
        return nodeCount;
    }

    struct node *temp = head;

    while(temp->next != NULL){
        nodeCount++;
        temp = temp->next;
    }

    return nodeCount;
}

int getValueOfNodeByPosition(struct node *head, int position){
    if(isEmpty(head)){
        printf("Linkedlist is empty.\n");
        return -1;
    }

    int value = 0;

    struct node *temp = head;

    int positionCount = 1;

    while(temp != NULL){
        if(positionCount == position){
            value = temp->val;
            break;
        }
        temp = temp->next;
        positionCount++;
    }

    return value;
}

void middleNodeValue(struct node *head){
    if(isEmpty(head)){
        printf("Empty Linked list.\n");
        return;
    }

    int length = lengthLinkedList(head);
    if(length % 2 != 0){
        int middlePosition = (length / 2)+1;
        int val = getValueOfNodeByPosition(head,middlePosition);
        printf("Value of Middle Node: %d \n",val);
    }else{
        int middlePositionOne = (length / 2);
        int middlePositionTwo = (length / 2)+1;
        int valOne = getValueOfNodeByPosition(head, middlePositionOne);
        int valTwo = getValueOfNodeByPosition(head,middlePositionTwo);

        printf("value of Middle Node One: %d \n",valOne);
        printf("value of Middle Node two: %d \n",valTwo);
    }
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
        
        printf("\n .... MENU ..... \n");
        printf("\n 1. for creating linked list.\n ");
        printf("\n 2. for displaying linked list.\n");
        printf("\n 3. for length of linked list.\n");
        printf("\n 4. for getting value of middle node.\n");
        printf("\n 5. for exit.\n");

        printf("\n Enter Choice: \n");
        scanf("%d",&opt);

        switch(opt){
            case 1:
                head = createLL(head);
                break;
            case 2:
                displayLinkedList(head);
                break;
            case 3:
                printf("Length of Linked List: %d \n",lengthLinkedList(head));
                break;
            case 4:
                middleNodeValue(head);
                break;
            case 5:
                printf("Exit Successfull.\n");
                return -1;
            
            default:
                printf("Invalid Choice: ");
                break;
        }
    }

    return 0;
}