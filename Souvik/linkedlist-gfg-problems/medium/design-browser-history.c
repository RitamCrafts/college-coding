#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100
struct node *curr = NULL;

struct node {
    char val[100];
    struct node *prev;
    struct node *next;
};

bool isEmpty(struct node *head){
    return head == NULL;
}

struct node *createNode(char val[MAX_SIZE]){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->next = NULL;
    newNode->prev = NULL;
    strcpy(newNode->val,val);
    return newNode;
}

struct node *insertFirst(struct node *head, char val[MAX_SIZE]){
    struct node *newNode = createNode(val);
    newNode->next = head;
    if(!isEmpty(head)){
        head->prev = newNode;
    }
    head = newNode;

    return head;
}

struct node *deleteNodeNext(){
    struct node *temp = curr;
    if(temp == NULL || temp->next == NULL){
        return curr;
    }else{
        struct node *nextNode = temp->next;
        temp->next = nextNode->next;
        if(nextNode->next != NULL){
            nextNode->next->prev = temp;
        }
        free(nextNode);
    }

    return curr;
}


struct node *createBrowserHistory(struct node *head,char val[MAX_SIZE]){
    head = insertFirst(head,val);
    curr = head;

    return head;
}

struct node *visit(struct node *head,char val[MAX_SIZE]){
    if(isEmpty(head)){
        head = createBrowserHistory(head,val);
        return head;
    }

    while(curr->next != NULL){
        deleteNodeNext();
    }
    struct node *newNode = createNode(val);
    curr->next = newNode;
    newNode->prev = curr;
    newNode->next = NULL;

    curr = newNode;

    return curr;
}

struct node *back(){
    if(curr->prev != NULL){
        curr = curr->prev;
    }
    return curr;
}

struct node *forward(){
    if(curr->next != NULL){
        curr = curr->next;
    }

    return curr;
}



int main(){
    struct node *head = NULL;

    char val[MAX_SIZE];

    while (true) {

        int choice;

        printf("\n===== Browser History =====\n");
        printf("1. Visit\n");
        printf("2. Back\n");
        printf("3. Forward\n");
        printf("0. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:

                printf("Enter URL: ");
                scanf("%99s", val);

                head = visit(head, val);

                printf("Current Page: %s\n", curr->val);

                break;


            case 2:

                if (curr == NULL) {
                    printf("Browser history is empty.\n");
                    break;
                }

                curr = back();

                printf("Current Page: %s\n", curr->val);

                break;


            case 3:

                if (curr == NULL) {
                    printf("Browser history is empty.\n");
                    break;
                }

                curr = forward();

                printf("Current Page: %s\n", curr->val);

                break;



            case 0:

                printf("Exiting Browser History...\n");
                return 0;


            default:

                printf("Invalid Choice!\n");
        }
    }

    return 0;
}