
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *insert(struct node *root, int val) {
    if (root == NULL) {
        struct node *newNode = malloc(sizeof(struct node));
        newNode->data = val;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}

struct node *smallest(struct node *root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct node *deleteNode(struct node *root, int val) {
    if (root == NULL)
        return NULL;

    if (val < root->data)
        root->left = deleteNode(root->left, val);
    else if (val > root->data)
        root->right = deleteNode(root->right, val);
    else {
        struct node *temp;

        if (root->left == NULL) {
            temp = root->right;
            free(root);
            return temp;
        }

        if (root->right == NULL) {
            temp = root->left;
            free(root);
            return temp;
        }

        temp = smallest(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int countNodes(struct node *root) {
    if (root == NULL)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int largest(struct node *root) {
    while (root->right != NULL)
        root = root->right;
    return root->data;
}

int height(struct node *root) {
    int l, r;

    if (root == NULL)
        return -1;

    l = height(root->left);
    r = height(root->right);

    return 1 + (l > r ? l : r);
}

int internalNodes(struct node *root) {
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 0;

    return 1 + internalNodes(root->left) + internalNodes(root->right);
}

int externalNodes(struct node *root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return externalNodes(root->left) + externalNodes(root->right);
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void mirror(struct node *root) {
    if (root == NULL)
        return;

    struct node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

void menu() {
    printf("\n--- BINARY SEARCH TREE ---\n");
    printf("1.Insert  2.Delete  3.Total Nodes\n");
    printf("4.Largest  5.Smallest  6.Height\n");
    printf("7.Internal Nodes  8.External Nodes\n");
    printf("9.Mirror Image  10.Display  11.Menu  12.Exit\n");
}

int main() {
    struct node *root = NULL;
    int choice, val;

    menu();

    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                root = deleteNode(root, val);
                break;

            case 3:
                printf("Total nodes: %d\n", countNodes(root));
                break;

            case 4:
                if (root == NULL)
                    printf("Tree is empty\n");
                else
                    printf("Largest element: %d\n", largest(root));
                break;

            case 5:
                if (root == NULL)
                    printf("Tree is empty\n");
                else
                    printf("Smallest element: %d\n", smallest(root)->data);
                break;

            case 6:
                printf("Height: %d\n", height(root));
                break;

            case 7:
                printf("Internal nodes: %d\n", internalNodes(root));
                break;

            case 8:
                printf("External nodes: %d\n", externalNodes(root));
                break;

            case 9:
                // Mirroring changes the BST property.
                mirror(root);
                printf("Mirror image created\n");
                inorder(root);
                printf("\n");
                break;

            case 10:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 11:
                menu();
                break;

            case 12:
                exit(0);

            default:
                printf("Wrong choice\n");
        }
    }
}

/*
--- BINARY SEARCH TREE ---
1.Insert  2.Delete  3.Total Nodes
4.Largest  5.Smallest  6.Height
7.Internal Nodes  8.External Nodes
9.Mirror Image  10.Display  11.Menu  12.Exit

Enter choice: 1
Enter value: 50

Enter choice: 1
Enter value: 30

Enter choice: 1
Enter value: 70

Enter choice: 1
Enter value: 20

Enter choice: 1
Enter value: 40

Enter choice: 1
Enter value: 60

Enter choice: 1
Enter value: 80

Enter choice: 10
Inorder: 20 30 40 50 60 70 80

Enter choice: 9
Mirror image created
80 70 60 50 40 30 20

Enter choice: 12
*/