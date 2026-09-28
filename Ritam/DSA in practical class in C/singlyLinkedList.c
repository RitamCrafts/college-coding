#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node *next;
};

struct node *insertStart(struct node *start, int data){
    struct node* newNode=(struct node*)(malloc(sizeof(struct node)));
    newNode->data=data;
    newNode->next=start;
    start=newNode;
    return start;
};

struct node *insertEnd(struct node *start, int data){
    if(start==NULL){
        return insertStart(start,data);
    }
    struct node *ptr=start;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    struct node* newNode=(struct node*)(malloc(sizeof(struct node)));
    newNode->data=data;
    newNode->next=NULL;
    ptr->next=newNode;
    return start;
};

struct node *createLL(struct node *start){
    struct node *newNode,*ptr;
    int num=0;
    while(num!=-1){
        printf("\nEnter data(-1 to end):");
        scanf("%d",&num);
        if(num==-1){
            break;
        }

        newNode=(struct node*)(malloc(sizeof(struct node)));
        newNode->data=num;
        newNode->next=NULL;

        if(start==NULL){
            start=newNode;
        }
        else{
            ptr=start;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=newNode;
        }
    }
    return start;
};

struct node *insertAfterIndex(struct node *start,int data,int index){
    if(index<0){
        printf("\nInvalid index\n");
        return start;
    }
    if(index==0){
        return insertStart(start,data);
    }
    int i=0;
    struct node *ptr=start;

    while(1){
        if(ptr==NULL){
            printf("\nPosition not Found\n");
            return start;
        }
        if(i==index){
            struct node *newNode=(struct node*)(malloc(sizeof(struct node)));
            newNode->data=data;
            newNode->next=ptr->next;
            ptr->next=newNode;
            return start;
        }
        i++;
        ptr=ptr->next;
    }
    return start;
};

struct node *insertAtIndex(struct node *start,int data,int index){
    if(index<0){
        printf("\nInvalid index\n");
        return start;
    }
    if(index==0){
        return insertStart(start,data);
    }
    int i=1;
    struct node *ptr=start;
    struct node *prePtr=ptr;
    if(ptr==NULL){
        printf("\nPosition not Found\n");
        return start;
    }
    ptr=ptr->next;

    while(1){
        if(ptr==NULL){
            printf("\nPosition not Found\n");
            return start;
        }
        if(i==index){
            struct node *newNode=(struct node*)(malloc(sizeof(struct node)));
            newNode->data=data;
            newNode->next=ptr;
            prePtr->next=newNode;
            return start;
        }
        i++;
        prePtr=ptr;
        ptr=ptr->next;
    }
    return start;
};





struct node *deleteAtIndex(struct node *start,int index){
    if(index<0){
        printf("\nInvalid index\n");
        return start;
    }
    if(index==0){
        return start->next;
    }
    int i=1;
    struct node *ptr=start;
    struct node *prePtr=ptr;
    if(ptr==NULL){
        printf("\nPosition not Found\n");
        return start;
    }
    ptr=ptr->next;

    while(1){
        if(ptr==NULL){
            printf("\nPosition not Found\n");
            return start;
        }
        if(i==index){
            struct node *temp=ptr;
            prePtr->next=ptr->next;
            free(temp);
            return start;
        }
        i++;
        prePtr=ptr;
        ptr=ptr->next;
    }
    return start;
};





void displayLL(struct node *start){
    if(start==NULL){
        printf("\nEmpty Linked List please insert to continue...\n\n");
        return;
    }
    printf("\nLinked List\n");
    struct node *ptr=start;
    int count=1;
    while(ptr!=NULL){
        printf("%d. %d\n",count,ptr->data);
        ptr=ptr->next;
        count++;
    }
}

void displayLLDetailed(struct node *start){
    if(start==NULL){
        printf("\nEmpty Linked List please insert to continue...\n\n");
        return;
    }
    printf("\nLinked List\n");
    struct node *ptr=start;
    int count=1;
    while(ptr!=NULL){
        printf("%d. %p\t%d\n\n",count,ptr,ptr->data);
        ptr=ptr->next;
        count++;
    }
}




int main(){
    struct node *myLL=NULL;
    while(1){
        int op,val,pos;
        printf("\nLinked List Menu\n");
        printf("1. Create Linked List | 2. Insert End | 3.Insert Start | 4. Insert at position | 5. Insert after position\n");
        printf("6. Display Linked List | 7. Display Linked List(detailed)\n");
        printf("8. Delete from position \n");
        printf("9. Exit\n");
        printf("Enter your option:");
        scanf("%d",&op);
        switch(op){
            case 1:
                myLL=createLL(myLL);
                break;
            case 2:
                printf("Enter value to insert:");
                scanf("%d",&val);
                myLL=insertEnd(myLL,val);
                break;
            case 3:
                printf("Enter value to insert:");
                scanf("%d",&val);
                myLL=insertStart(myLL,val);
                break;
            case 4:
                displayLL(myLL);
                printf("Enter position to insert at:");
                scanf("%d",&pos);
                printf("Enter value to insert:");
                scanf("%d",&val);
                myLL=insertAtIndex(myLL,val,pos-1);
                break;
            case 5:
                displayLL(myLL);
                printf("Enter position to insert after:");
                scanf("%d",&pos);
                printf("Enter value to insert:");
                scanf("%d",&val);
                myLL=insertAfterIndex(myLL,val,pos-1);
                break;
            case 6:
                displayLL(myLL);
                break;
            case 7:
                displayLLDetailed(myLL);
                break;
            case 8:
                displayLL(myLL);
                printf("Enter position to delete:");
                scanf("%d",&pos);
                myLL=deleteAtIndex(myLL,pos-1);
                break;
            case 9:
                return 0;
            default:
                printf("Invalid Choice");
        }

    }
    return 0;
}
