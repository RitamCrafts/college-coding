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

int totalLeafNodesCount(struct TreeNode *root){
    if(isEmpty(root)) return 0;

    if(root->left == NULL && root->right == NULL){
        return 1;
    }

    return totalLeafNodesCount(root->left)+totalLeafNodesCount(root->right);
}

int main(){
    struct TreeNode *root = createNode(10);
    root->left = createNode(5);
    root->left->left = createNode(2);
    root->left->right = createNode(7);
    root->right = createNode(20);
    root->right->left = createNode(11);
    root->right->right = createNode(50);

    printf("Before Mirror: \n");
    inOrder(root);
    printf("\n");

    mirrorTree(root);
    printf("After Mirror: \n");
    inOrder(root);
    printf("\n");

    printf("Total Leaf Node Count: %d \n",totalLeafNodesCount(root));
    return 0;
}