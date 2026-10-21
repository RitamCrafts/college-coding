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

int minValue(struct TreeNode *root){
    if(isEmpty(root)){
        return -1;
    }

    int min_value = INT_MAX;
    while(root != NULL){
        if(root->val < min_value){
            min_value = root->val;
        }

        root = root->left;
    }

    return min_value;
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
        printf("1. Create BST: \n");
        printf("2. Print tree: \n");
        printf("3. find min value: \n");
        printf("0. Exit: \n");
        printf("Enter Choice: ");
        scanf("%d",&opt);

        if(opt == 1){
            int val;
            printf("Enter Val: ");
            scanf("%d",&val);
            root = createBST(root,val);
        }else if(opt == 2){
            inOrder(root);
        }else if(opt == 3){
            int min_val = minValue(root);
            printf("Min value: %d\n",min_val);
        }else if(opt == 0){
            printf("Exit...\n");
            free(root);
            return -1;
        }else{
            printf("Invalid Choice: \n");
        }
    }
    return 0;
}