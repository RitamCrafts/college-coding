#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isEmpty(struct TreeNode *root){
    return root == NULL;
}

struct TreeNode *createNode(int val){
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct TreeNode *createBST(struct TreeNode *root, int val){
    struct TreeNode *newNode = createNode(val);
    if(isEmpty(root)){
        return newNode;
    }

    if(val<root->val){
        root->left = createBST(root->left,val);
    }else if(val>root->val){
        root->right = createBST(root->right,val);
    }

    return root;
}

int inOrderSuccessor(struct TreeNode *root,struct TreeNode *k){
    if(isEmpty(root)){
        return -1;
    }
    struct TreeNode *successor = NULL;
    if(k->right != NULL){
        successor = k->right;
        while(successor->left != NULL){
            successor = successor->left;
        }
    }else{
        while(root!= NULL){
            if(k->val < root->val){
                successor = root;
                root = root->left;
            }else if(k->val > root->val){
                root = root->right;
            }else{
                break;
            }
        }
    }

    if(isEmpty(successor)){
        return -1;
    }

    return successor->val;
}

void inOrder(struct TreeNode *root){
    if(isEmpty(root)){
        return;
    }

    inOrder(root->left);
    printf("%d ",root->val);
    inOrder(root->right);
}

int main(){
    struct TreeNode *root = NULL;
    int opt;
    while(true){
        printf("\n ... MENU ... \n");
        printf("1. create BST: \n");
        printf("2. print tree: \n");
        printf("3. get inorder successor: \n");
        printf("0. Exit: \n");
        printf("Enter Your Choice: ");
        scanf("%d",&opt);

        if(opt == 1){
            int val;
            printf("Enter Val: ");
            scanf("%d",&val);
            root = createBST(root,val);
        }else if(opt == 2){
            inOrder(root);
            printf("\n");
        }else if(opt == 3){
            int val;
            printf("Enter Val: ");
            scanf("%d",&val);
            struct TreeNode *k = createNode(val);
            int successorVal = inOrderSuccessor(root,k);
            if(successorVal != -1){
                printf("Inorder Successor Value: %d\n",successorVal);
            }else{
                printf("No Inorder Successor Found.\n");
            }
            free(k); // Free the allocated memory for k
        }
        else if(opt == 0){
            printf("Exit... \n");
            free(root);
            return -1;
        }
        else{
            printf("Invalid Choice: ");
        }
    }

    return 0;
}