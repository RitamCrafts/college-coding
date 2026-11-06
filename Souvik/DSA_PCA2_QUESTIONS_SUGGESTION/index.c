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

struct TreeNode *createBST(struct TreeNode *root, int val){
    if(isEmpty(root)){
        return createNode(val);
    }

    if(val<root->data){
        root->left =  createBST(root->left,val);
    }else if(val>root->data){
        root->right =  createBST(root->right,val);
    }

    return root;
}

bool searchBST(struct TreeNode *root,int val){
    if(isEmpty(root)) return false;
    
    if(val == root->data) return true;

    if(val<root->data){
        return searchBST(root->left,val);
    }else if(val>root->data){
        return searchBST(root->right,val);
    }

    return false;
}

void inOrder(struct TreeNode *root){
    if(isEmpty(root)) return;
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}

void preOrder(struct TreeNode *root){
    if(isEmpty(root)) return;

    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(struct TreeNode *root){
    if(isEmpty(root)) return;

    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->data);
}


struct TreeNode *inOrderSuccessor(struct TreeNode *root){
    if(isEmpty(root)) return NULL;

    if(root->right != NULL){
        root = root->right;
    }

    while(root->left != NULL){
        root = root->left;
    }

    return root;
}

struct TreeNode *deleteNode(struct TreeNode *root,int val){
    if(isEmpty(root)){
        return NULL;
    }

    if(val<root->data){
        root->left = deleteNode(root->left,val);
    }else if(val>root->data){
        root->right = deleteNode(root->right,val);
    }else{
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }else if(root->left == NULL && root->right != NULL){
            struct TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->left != NULL && root->right == NULL){
            struct TreeNode *temp = root->left;
            free(root);
            return temp;
        }else{
            struct TreeNode *temp = inOrderSuccessor(root);
            root->data = temp->data;
            root->right = deleteNode(root->right,temp->data);
        }
    }

    return root;
}

void swapPointer(struct TreeNode **ptr1, struct TreeNode **ptr2){
    struct TreeNode *temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

struct TreeNode *mirrorTree(struct TreeNode *root){
    if(isEmpty(root)) return NULL;
    swapPointer(&root->left,&root->right);

    root->left = mirrorTree(root->left);
    root->right = mirrorTree(root->right);

    return root;
}

int totalNodesCount(struct TreeNode *root){
    if(isEmpty(root)) return 0;
    return 1+totalNodesCount(root->left)+totalNodesCount(root->right);
}

int totalLeafNodesCount(struct TreeNode *root){
    if(isEmpty(root)) return 0;

    if(root->left == NULL && root->right == NULL){
        return 1;
    }

    return  totalLeafNodesCount(root->left)+totalLeafNodesCount(root->right);
}

int heightTree(struct TreeNode *root){
    if(isEmpty(root)){
        return 0;
    }

    int leftHeight = heightTree(root->left);
    int rightHeight = heightTree(root->right);

    return 1+ (leftHeight>rightHeight?leftHeight:rightHeight);
}

int minElement(struct TreeNode *root){
    if(isEmpty(root)) return -1;
    while(root->left != NULL){
        root = root->left;
    }

    return root->data;
}

int maxElement(struct TreeNode *root){
    if(isEmpty(root)) return -1;
    while(root->right != NULL){
        root = root->right;
    }

    return root->data;
}

int totalInternalNodesCount(struct TreeNode *root){
    if(isEmpty(root)) return 0;

    return totalNodesCount(root)-totalLeafNodesCount(root);
}

int main (){
    struct TreeNode *root = NULL;
    int opt, val;

    while (true) {
        printf("\n.... BST MENU ....\n");
        printf("1. Insert into BST\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search in BST\n");
        printf("6. Delete Node\n");
        printf("7. Mirror Tree (BST ordering will be lost)\n");
        printf("8. Total Nodes\n");
        printf("9. Total Leaf Nodes\n");
        printf("10. Total Internal Nodes\n");
        printf("11. Height of Tree (in levels)\n");
        printf("12. Minimum Element (valid only for a BST)\n");
        printf("13. Maximum Element (valid only for a BST)\n");
        printf("14. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &opt) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (opt) {
            case 1:
                printf("Enter value: ");
                if (scanf("%d", &val) != 1) {
                    printf("Invalid input.\n");
                    free(root);
                    return 1;
                }
                root = createBST(root, val);
                break;
            case 2:
                printf("Inorder: ");
                inOrder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder: ");
                preOrder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder: ");
                postOrder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter value to search: ");
                if (scanf("%d", &val) != 1) {
                    free(root);
                    return 1;
                }
                printf(searchBST(root, val) ? "Value found.\n" : "Value not found.\n");
                break;
            case 6:
                printf("Enter value to delete: ");
                if (scanf("%d", &val) != 1) {
                    free(root);
                    return 1;
                }
                root = deleteNode(root, val);
                break;
            case 7:
                root = mirrorTree(root);
                printf("Tree mirrored. BST ordering is no longer valid for search/insert/delete/min/max.\n");
                break;
            case 8:
                printf("Total nodes: %d\n", totalNodesCount(root));
                break;
            case 9:
                printf("Total leaf nodes: %d\n", totalLeafNodesCount(root));
                break;
            case 10:
                printf("Total internal nodes: %d\n", totalInternalNodesCount(root));
                break;
            case 11:
                printf("Height (levels): %d\n", heightTree(root));
                break;
            case 12:
                printf("Minimum element: ");
                if (root == NULL) printf("Tree is empty.\n");
                else printf("%d\n", minElement(root));
                break;
            case 13:
                printf("Maximum element: ");
                if (root == NULL) printf("Tree is empty.\n");
                else printf("%d\n", maxElement(root));
                break;
            case 14:
                free(root);
                printf("Exit...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    free(root);
    return 0;
}