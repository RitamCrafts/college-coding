#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isEmpty(struct TreeNode *root){
    return root == NULL;
}

struct TreeNode *createNode(int val){
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct TreeNode *generateBST(struct TreeNode *root,int val){
    if(isEmpty(root)){
        struct TreeNode *newNode = createNode(val);
        return newNode;
    }

    if(val<root->data){
        root->left = generateBST(root->left,val);
    }else if(val>root->data){
        root->right = generateBST(root->right,val);
    }

    return root;
}

int minValue(struct TreeNode *root){
    if(isEmpty(root)) return -1;
    while(root->left != NULL){
        root = root->left;
    }

    return root->data;
}
int maxValue(struct TreeNode *root){
    if(isEmpty(root)) return -1;
    while(root->right != NULL){
        root = root->right;
    }

    return root->data;
}

int main() {
    struct TreeNode *root = NULL;
    int choice, val;

    do {
        printf("\n===== BST MENU =====\n");
        printf("1. Generate BST (Insert Node)\n");
        printf("2. Find Minimum Value\n");
        printf("3. Find Maximum Value\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);

                root = generateBST(root, val);
                printf("Node inserted successfully!\n");
                break;

            case 2:
                if (isEmpty(root)) {
                    printf("BST is empty!\n");
                } else {
                    printf("Minimum value = %d\n",
                           minValue(root));
                }
                break;

            case 3:
                if (isEmpty(root)) {
                    printf("BST is empty!\n");
                } else {
                    printf("Maximum value = %d\n",
                           maxValue(root));
                }
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}