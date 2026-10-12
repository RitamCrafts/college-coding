#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
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

void swapPointer(struct TreeNode **ptr1, struct TreeNode **ptr2){
    struct TreeNode *temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

struct TreeNode *invertTree(struct TreeNode *root){
    if(isEmpty(root)){
        return root;
    }

    swapPointer(&root->left,&root->right);
    invertTree(root->left);
    invertTree(root->right);

    return root;
}

void preOrder(struct TreeNode *root){
    if(isEmpty(root)){
        return;
    }

    printf("%d ", root->val);
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    struct TreeNode *root = createNode(10);
    root->left = createNode(11);
    root->left->left = createNode(12);
    root->left->right = createNode(34);
    root->right = createNode(13);

    printf("Before Inverting: \n");
    preOrder(root);

    printf("\n");
    root = invertTree(root);
    printf("After Inverting: \n");
    preOrder(root);

    printf("\n");

    return 0;
}