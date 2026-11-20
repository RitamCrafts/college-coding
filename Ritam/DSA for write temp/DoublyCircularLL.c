
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

void insertStart(struct node **head, int data) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;

    if (*head == NULL) {
        newNode->next = newNode->prev = newNode;
        *head = newNode;
        return;
    }

    struct node *last = (*head)->prev;
    newNode->next = *head;
    newNode->prev = last;
    last->next = newNode;
    (*head)->prev = newNode;
    *head = newNode;
}

void insertEnd(struct node **head, int data) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;

    if (*head == NULL) {
        newNode->next = newNode->prev = newNode;
        *head = newNode;
        return;
    }

    struct node *last = (*head)->prev;
    newNode->next = *head;
    newNode->prev = last;
    last->next = newNode;
    (*head)->prev = newNode;
}

void insertAt(struct node **head, int data, int pos) {
    struct node *ptr = *head;
    int i = 0;

    if (pos < 0) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 0) {
        insertStart(head, data);
        return;
    }

    if (ptr == NULL) {
        printf("Position doesn't exist\n");
        return;
    }

    while (i < pos && ptr != *head) {
        ptr = ptr->next;
        i++;
    }

    if (i != pos) {
        printf("Position doesn't exist\n");
        return;
    }

    if (ptr == *head) {
        insertEnd(head, data);
        return;
    }

    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = ptr;
    newNode->prev = ptr->prev;
    ptr->prev->next = newNode;
    ptr->prev = newNode;
}

void deleteAt(struct node **head, int pos) {
    struct node *ptr = *head;
    int i = 0;

    if (ptr == NULL || pos < 0) {
        printf("Invalid position\n");
        return;
    }

    while (i < pos && ptr->next != *head) {
        ptr = ptr->next;
        i++;
    }

    if (i != pos) {
        printf("Position doesn't exist\n");
        return;
    }

    if (ptr->next == ptr)
        *head = NULL;
    else {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;

        if (ptr == *head)
            *head = ptr->next;
    }

    free(ptr);
}

void display(struct node *head) {
    struct node *ptr = head;
    int i = 1;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("DOUBLY CIRCULAR LINKED LIST\n");
    do {
        printf("%d. %d\n", i++, ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

int main() {
    struct node *head = NULL;
    int choice, value, pos;

    printf("--- DOUBLY CIRCULAR LINKED LIST ---\n");
    printf("1.Insert Start  2.Insert End  3.Insert At\n");
    printf("4.Delete At  5.Display  6.Menu  7.Exit\n");

    while (1) {
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertStart(&head, value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(&head, value);
                break;

            case 3:
                printf("Enter value and position: ");
                scanf("%d%d", &value, &pos);
                insertAt(&head, value, pos);
                break;

            case 4:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAt(&head, pos);
                break;

            case 5:
                display(head);
                break;

            case 6:
                printf("--- DOUBLY CIRCULAR LINKED LIST ---\n");
                printf("1.Insert Start  2.Insert End  3.Insert At\n");
                printf("4.Delete At  5.Display  6.Menu  7.Exit\n");
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}


/*
--- DOUBLY CIRCULAR LINKED LIST ---
1.Insert Start  2.Insert End  3.Insert At
4.Delete At  5.Display  6.Menu  7.Exit

Enter choice: 1
Enter value: 10

Enter choice: 2
Enter value: 30

Enter choice: 3
Enter value and position: 20 1

Enter choice: 5
DOUBLY CIRCULAR LINKED LIST
1. 10
2. 20
3. 30

Enter choice: 4
Enter position: 1

Enter choice: 5
DOUBLY CIRCULAR LINKED LIST
1. 10
2. 30

Enter choice: 7
*/