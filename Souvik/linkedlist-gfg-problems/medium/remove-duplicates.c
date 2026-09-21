#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100
struct node{
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

struct node *removeDuplicates(struct node *head){
    if(isEmpty(head) || head->next == NULL){
        return head;
    }
    struct node *temp = head;
    struct node *prev = NULL;
    int arr[MAX_SIZE];
    int j = 0;
    while(temp != NULL){
        bool duplicate = false;
        for(int i = 0; i<j; i++){
            if(arr[i] == temp->val){
                duplicate = true;
                break;
            }
        }
        if(duplicate == true){
            prev->next = temp->next;
            struct node *temp2 = temp;
            temp = temp->next;
            free(temp2);
        }else{
            arr[j++] = temp->val;
            prev = temp;
            temp = temp->next;
        }
    }

    return head;
}

struct node *insertFirst(struct node *head, int val){
    struct node *newNode = createNode(val);
    newNode->next = head;
    head = newNode;

    return head;
}

struct node *insertEnd(struct node *head, int val){
    if(isEmpty(head)){
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

struct node *createLL(struct node *head,int val){
    if(isEmpty(head)){
        head = insertFirst(head,val);
    }else{
        head = insertEnd(head,val);
    }

    return head;
}

struct node *removeDuplicatesTwo(struct node *head){
    if(isEmpty(head) || head->next == NULL){
        return head;
    }

    struct node *temp = head;
    int arr[MAX_SIZE];
    int j = 0;
    while(temp != NULL){
       arr[j++] = temp->val;
       temp = temp->next;
    }



    int unique_arr[MAX_SIZE];
    int k = 0;
    for(int i = 0; i<j; i++){
            int element = arr[i];
            int frequnecy = 0;
            for(int m = 0; m<j; m++){
                if(arr[m] == element){
                    frequnecy++;
                }
            }

            if(frequnecy == 1){
                unique_arr[k++] = arr[i];
            }
    }

    struct node *newHead = NULL;
    for(int i = 0; i<k; i++){
        newHead = createLL(newHead,unique_arr[i]);
    }
    return newHead;
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
    struct node *head = createNode(11);
    head->next = createNode(11);
    head->next->next = createNode(11);
    head->next->next->next = createNode(23);
    head->next->next->next->next = createNode(40);

    printList(head);

    head = removeDuplicates(head);
    printList(head);

    head = removeDuplicatesTwo(head);

    printList(head);

    return 0;
}