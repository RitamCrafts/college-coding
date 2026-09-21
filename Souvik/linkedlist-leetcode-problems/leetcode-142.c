#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct node {
    int val;
    struct node *next;
};

struct hashMap{
    struct node *address;
    int index;
};

struct node *createNode(int val){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

bool isEmpty(struct node *head){
    return head == NULL;
}

// naive approach
struct node *detectCycle(struct node *head){
    if(isEmpty(head) || head->next == NULL){
        return NULL;
    }


    struct node *temp = head;
    int index = 0;
    struct hashMap map[MAX_SIZE];
    while(temp != NULL){
        for(int i = 0; i<index; i++){
            if(map[i].address == temp){
                return temp;
            }
        }
        map[index].address = temp;
        map[index].index = index;
        index++;
        temp = temp->next;
    }

    return NULL;    
}

// optimal approach-by floyd's method
struct node *detectCycleTwo(struct node *head){
    if(isEmpty(head) || head->next == NULL){
        return NULL;
    }
    struct node *slow = head;
    struct node *fast = head;
    while(slow && fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return slow;
        }
    }

    return NULL;
}

int main(){
    struct node *head = createNode(3);
    head->next = createNode(2);
    head->next->next = createNode(0);
    head->next->next->next = createNode(-4);
    head->next->next->next->next = head->next->next;

    head = detectCycle(head);

    return 0;
}