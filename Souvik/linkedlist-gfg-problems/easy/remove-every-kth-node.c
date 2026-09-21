#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

struct node *insertFirst(struct node *head, int val){
    struct node *newNode = createNode(val);
    newNode->next = head;
    head = newNode;
    return head;
}

struct node *insertAtEnd(struct node *head, int val){
    struct node *newNode = createNode(val);
    if(isEmpty(head)){
        printf("Empty Linked list.\n");
        return newNode;
    }

    struct node *temp = head;
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
        printf("Enter Value of Node: ");
        scanf("%d",&val);
        head = insertFirst(head,val);
    }else{
        int val;
        printf("Enter Value of Node: ");
        scanf("%d",&val);
        head = insertAtEnd(head,val);
    }

    return head;
}

int lengthLinkedList(struct node *head){
    int nodeCount = 1;
    if(isEmpty(head)){
        nodeCount = 0;
        return 0;
    }

    struct node *temp = head;
    while(temp->next != NULL){
        nodeCount++;
        temp = temp->next;
    }

    return nodeCount;
}

void displayLinkedList(struct node *head){
    if(isEmpty(head)){
        printf("Linked list is Empty.\n");
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

struct node *deleteNodeFirst(struct node *head){
    if(isEmpty(head)){
        printf("Linkedlist is empty.\n");
        return NULL;
    }

    struct node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct node *deleteNodeAtSpecificPosition(struct node *head, int position){
    if(isEmpty(head)){
        printf("LinkedList is Empty.\n");
        return NULL;
    }

    int length = lengthLinkedList(head);
    if(position > length){
        printf("Position can't be greater than length.\n");
        return NULL;
    }

    if(position == 1){
        head = deleteNodeFirst(head);
        return head;
    }

    struct node *temp = head;

    int positionCount = 0;
    while(temp->next != NULL){
        if(positionCount == position-2){
            struct node *deleteNode = temp->next;
            temp->next = deleteNode->next;
            free(deleteNode);
        }

        temp = temp->next;
        positionCount++;
    }

    return head;

}

struct node *deleteKthNode(struct node *head, int k){
    if(isEmpty(head)){
        printf("Empty linked list.\n");
        return NULL;
    }

    int length = lengthLinkedList(head);

    if(k>length){
        printf("Value of k can't be greater than length of linkedlist.\n");
        return NULL;
    }

    int position = k;
    while(position <= length){
        head = deleteNodeAtSpecificPosition(head,position);
        length--;
        position = position+(k-1);

    }

    return head;
}


int main(){
    struct node *head = NULL;
    int opt;
    while(true){
        printf("\n .... MENU .... \n");
        printf("1. Create Linked List\n");
        printf("2. Display Linked List\n");
        printf("3. Length of Linked List\n");
        printf("4. Delete First Node\n");
        printf("5. Delete kth node.\n");
        printf("6. Exit\n");

        printf("\n Enter Your Choice. \n");
        scanf("%d",&opt);

        switch (opt)
        {
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
            head = deleteNodeFirst(head);
            break;

        case 5: {
            int k;
            printf("Enter Value of K: ");
            scanf("%d",&k);
            head = deleteKthNode(head,k);

            break;
        }

        case 6:
            printf("Exit Successfull.\n");
            return -1;
        default:
            break;
        }
    }
    return 0;
}