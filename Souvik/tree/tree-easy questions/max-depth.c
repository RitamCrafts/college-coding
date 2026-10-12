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

int maxDepth(struct TreeNode *root){
    if(isEmpty(root)){
        return 0;
    }

    int maxVal = INT_MIN;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    if(leftDepth > maxVal){
        maxVal = leftDepth;
    }

    if(rightDepth > maxVal){
        maxVal = rightDepth;
    }

    return 1+maxVal;
}

int minDepth(struct TreeNode *root){
    if(isEmpty(root)){
        return 0;
    }

    if(root->left != NULL && root->right == NULL){
        return 1+minDepth(root->left);
    }
    if(root->left == NULL && root->right != NULL){
        return 1+minDepth(root->right);
    }

    int minVal = INT_MAX;

    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);

    if(leftDepth<minVal){
        minVal = leftDepth;
    }

    if(rightDepth<minVal){
        minVal = rightDepth;
    }

    return 1+minVal;
}

int main(){
    struct TreeNode *root = createNode(3);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);

    printf("Max Depth: %d \n",maxDepth(root));
    printf("Min Depth: %d \n",minDepth(root));
    return 0;
}