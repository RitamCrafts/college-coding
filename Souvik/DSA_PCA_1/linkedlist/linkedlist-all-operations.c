#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Node{
    int val;
    struct Node *next;
};

bool isEmpty(struct Node *head){
    return head == NULL;
}

struct Node *createNode(int val){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node ));
    newNode->val = val;
    newNode->next = NULL;

    return newNode;
}
struct Node *insertBeginning(struct Node *head, int val){
    struct Node *newNode = createNode(val);
    newNode->next = head;
    head = newNode;
    return head;
}
struct Node *insertEnd(struct Node *head, int val){
    if(isEmpty(head)){
        printf("Empty Linked list.\n");
        return NULL;
    }

    struct Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    struct Node *newNode = createNode(val);
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

struct Node *createLL(struct Node *head){
    if(isEmpty(head)){
        int val;
        printf("Enter Node Value: ");
        scanf("%d",&val);
        head = insertBeginning(head,val);
    }else{
        int val;
        printf("Enter Node Value: ");
        scanf("%d",&val);
        head = insertEnd(head,val);
    }

    return head;
}

int lengthCount(struct Node *head){
    int length = 0;
    if(isEmpty(head)){
        return 0;
    }
    struct Node *temp = head;
    while(temp != NULL){
        length++;
        temp = temp->next;
    }

    return length;
}

struct Node *deleteBeginning(struct Node *head){
    if(isEmpty(head)){
        printf("Empty Linked list.\n");
        return NULL;
    }

    struct Node *temp = head;
    head = head->next;
    free(temp);

    return head;
}

struct Node *deleteEnd(struct Node *head){
    if(isEmpty(head)){
        printf("Empty Linked list.\n");
        return NULL;
    }

    if(head->next == NULL){
        free(head);
        return NULL;
    }
    
    struct Node *temp = head;
    struct Node *nextTemp = head->next;


    while(nextTemp->next != NULL){
        nextTemp = nextTemp->next;
        temp = temp->next;
    }

    temp->next = nextTemp->next;
    free(nextTemp);

    return head;
}

struct Node *insertAtSpecificPosition(struct Node *head,int val, int index){
    int posCount = 1;
    if(index == 1 || isEmpty(head)){
        head = insertBeginning(head,val);
        return head;
    }


    struct Node *temp = head;
    struct Node *nextTemp = head->next;
    while(nextTemp->next != NULL){
        posCount++;
        if(posCount == index){
            struct Node *newNode = createNode(val);
            newNode->next = temp->next;
            temp->next = newNode;
        }
        nextTemp = nextTemp->next;
        temp = temp->next;
    }

    if(nextTemp->next == NULL && posCount + 1 == index){
        struct Node *newNode = createNode(val);

        newNode->next = nextTemp;
        temp->next = newNode;

        return head;
    }

    return head;
}

struct Node *insertANodebeforeANodeWithGivenValue(struct Node *head, int nodeValue, int val){
    if(isEmpty(head)){
        printf("Empty Linked list.\n");
        return NULL;
    }

    struct Node *newNode = createNode(val);

    if(head->val == nodeValue){
        newNode->next = head;
        return newNode;
    }

    struct Node *temp = head;
    while(temp != NULL && temp->next != NULL && temp->next->val != nodeValue){
        temp = temp->next;
    }

    if(temp->next == NULL){
        printf("Node With Given Value not found");
        free(newNode);
        return head;
    }
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

struct Node *deleteSpecificPosition(struct Node *head, int index){
    int posCount = 1;
    if(isEmpty(head)){
        printf("Empty Linked list.\n");
        return NULL;
    }

    if(index == 1){
        head = deleteBeginning(head);
        return head;
    }

    struct Node *temp = head;
    struct Node *nextTemp = head->next;
    while(nextTemp->next != NULL){
        posCount++;
        if(posCount == index){
            temp->next = nextTemp->next;
            free(nextTemp);
            return head;
        }

        nextTemp = nextTemp->next;
        temp = temp->next;
    }

    if(nextTemp->next == NULL && posCount+1 == index){
        temp->next = nextTemp->next;
        free(nextTemp);
        return head;
    }

    return head;

}


void printList(struct Node *head){
    if(isEmpty(head)){
        printf("Empty Linkedlist.\n");
        return;
    }

    

    struct Node *temp = head;
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
    struct Node *head = NULL;
    int opt;
    while(true){
        printf("\n ... MENU ... \n");
        printf("1. Create List: \n");
        printf("2. Display List: \n");
        printf("3. Insert At Beginning: \n");
        printf("4. Insert At End: \n");
        printf("5. Delete At Beginning: \n");
        printf("6. Delete At End: \n");
        printf("7. Insert At Specific Position: \n");
        printf("8. Delete At Specific Position: \n");
        printf("0. Exit: \n");
        
        printf("Enter Your Choice: ");
        scanf("%d",&opt);

        if(opt == 1){
            head = createLL(head);
        }else if(opt == 2){
            printList(head);
        }else if(opt == 3){
            int val;
            printf("Enter Value: ");
            scanf("%d",&val);
            head = insertBeginning(head,val);
        }else if(opt == 4){
            int val;
            printf("Enter Value: ");
            scanf("%d",&val);
            head = insertEnd(head,val);
        }
        else if(opt == 5){
            head = deleteBeginning(head);
        }else if(opt == 6){
            head = deleteEnd(head);
        }else if(opt == 7){
            int index,nodeValue;
            printf("Enter Index: ");
            scanf("%d",&index);
            printf("Enter Node Value: ");
            scanf("%d",&nodeValue);
            head = insertAtSpecificPosition(head,nodeValue,index);
        }else if(opt == 8){
            int index;
            printf("Enter Index: ");
            scanf("%d",&index);
            head = deleteSpecificPosition(head,index);
        }else if(opt == 0){
            printf("Exit.\n");
            return -1;
        }else{
            printf("Invalid Choice.\n");
            return -1;
        }

    }
    return 0;
}