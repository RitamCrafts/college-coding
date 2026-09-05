#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
};

void insertNodeStart(struct node **head,int data){
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=*head;
    *head = newNode;
}

void insertNodeEnd(struct node **head,int data){
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct node *ptr = *head;
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    ptr->next = newNode;
}

void insertNodeAfterPosition(struct node **head,int data,int position){
    if(position < 0){
        printf("Invalid position!");
        return;
    }
    if(position==0){
        insertNodeStart(head,data);
        return;
    }
    if(*head==NULL){
        printf("List is Empty!");
        return;
    }
    struct node *ptr = *head;
    int i=1;

    while(1){
        if(ptr==NULL){
            printf("Position %d does not exist.",position);
            return;
        }
        if(i==position){
            break;
        }
        ptr=ptr->next;
        i++;
    }
    
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=ptr->next;
    ptr->next=newNode;
}

void insertNodeAtPosition(struct node **head,int data,int position){
    if(position < 1){
        printf("Invalid position!");
        return;
    }
    if(position==1){
        insertNodeStart(head,data);
        return;
    }
    if(*head==NULL){
        printf("List is Empty!");
        return;
    }
    struct node *ptr = *head;
    struct node *prePtr = ptr;
    ptr=ptr->next;
    int i=2;

    while(1){
        if(ptr==NULL){
            printf("Position %d does not exist.",position);
            return;
        }
        if(i==position){
            break;
        }
        prePtr = ptr;
        ptr=ptr->next;
        i++;
    }
    
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=prePtr->next;
    prePtr->next=newNode;
}


void deleteNodeByPosition(struct node **head,int position){
    if(position < 1){
        printf("Invalid position!");
        return;
    }
    if(*head==NULL){
        printf("List is Empty!");
        return;
    }
    if(position==1){
        struct node *temp = *head;
        *head=(*head)->next;
        free(temp);
        return;
    }
    struct node *ptr = *head;
    struct node *prePtr = ptr;
    ptr=ptr->next;
    int i=2;

    while(1){
        if(ptr==NULL){
            printf("Position %d does not exist.",position);
            return;
        }
        if(i==position){
            break;
        }
        prePtr = ptr;
        ptr=ptr->next;
        i++;
    }
    prePtr->next=ptr->next;
    free(ptr);
}

void deleteNodeByValue(struct node **head,int target){
    if (*head == NULL) {
        printf("List is Empty!");
        return;
    }

    struct node *ptr = *head;
    struct node *prePtr = ptr;
    ptr=ptr->next;
    //this skips the 1st node for now preptr is at 1st rn ptr is in next to reduce initial pointing complications using wtv loops etc

    while(ptr!=NULL){
        if(ptr->data==target){
            prePtr->next=ptr->next;
            struct node *temp=ptr;
            ptr=ptr->next;
            free(temp);
        }
        else{
            prePtr=ptr;
            ptr=ptr->next;
        }
    }

    //handle the 1st node now
    ptr = *head;
    if(ptr->data==target){
        *head=ptr->next;
        free(ptr);
    }
}


void longDisplay(struct node **head){
    struct node *ptr = *head;
    int i=0;
    if(ptr!=NULL) printf("LINKED LIST\n");
    while(ptr!=NULL){
        i++;
        printf("%d. %p\t%d\n",i,(void*)ptr,ptr->data);
        ptr = ptr->next;
    }
}

void display(struct node *head){
    struct node *ptr = head;
    int i=0;
    if(ptr!=NULL) printf("LINKED LIST\n");
    while(ptr!=NULL){
        i++;
        printf("%d. %d\n",i,ptr->data);
        ptr = ptr->next;
    }
}



int main() {
    struct node *myList = NULL;
    int choice, value, pos;

    while (1) {
        printf("\nSINGLY LINKED LIST MENU\n");
        printf("1.Insert End | 2.Insert Start | 3.Insert at/before position | 4.Insert after position \n5.Display | 6.Long Display \n7.Delete Position | 8.Delete specific value \n9.Exit \n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
            case 1:
                printf("Enter integer data to insert: ");
                scanf("%d", &value);
                insertNodeEnd(&myList, value);
                break;
            case 2:
                printf("Enter integer data to insert: ");
                scanf("%d", &value);
                insertNodeStart(&myList, value);
                break;
            case 3:
                display(myList);
                printf("Enter position to insert: ",value);
                scanf("%d", &pos);
                printf("Enter integer data to insert: ");
                scanf("%d", &value);
                insertNodeAtPosition(&myList, value, pos);
                break;
            case 4:
                display(myList);
                printf("After which position to insert? ",value);
                scanf("%d", &pos);
                printf("Enter integer data to insert: ");
                scanf("%d", &value);
                insertNodeAfterPosition(&myList, value, pos);
                break;
            case 5:
                display(myList);
                break;
            case 6:
                longDisplay(&myList);
                break;
            case 7:
                display(myList);
                printf("Which position to delete? ");
                scanf("%d", &pos);
                deleteNodeByPosition(&myList, pos);
                break;
            case 8:
                printf("Which value to mass remove? ");
                scanf("%d", &value);
                deleteNodeByValue(&myList, value);
                break;
            case 9:
                return 0;
            default:
                printf("Invalid\n");
        }
    }
    return 0;
}