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

int height(struct TreeNode *root){
    if(isEmpty(root)){
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if(leftHeight>rightHeight){
        return 1+ leftHeight;
    }

    return 1+ rightHeight;
}

int max(int a, int b){
    if(a > b){
        return a;
    }

    return b;
}

int diameterOfBinaryTree(struct TreeNode* root){
    if(isEmpty(root)){
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int curr = leftHeight+rightHeight;

    int leftDiameter = diameterOfBinaryTree(root->left);
    int rightDiameter = diameterOfBinaryTree(root->right);
    if(leftDiameter > rightDiameter && leftDiameter > curr){
        return leftDiameter;
    }else if(rightDiameter > leftDiameter && rightDiameter > curr){
        return rightDiameter;
    }
    return curr;
}

int maxDiameter = 0;

int diameterOfBinaryTreeOptimal(struct TreeNode *root){
    if(isEmpty(root)){
        return 0;
    }

    
    int lHeight = diameterOfBinaryTreeOptimal(root->left);
    int rheight = diameterOfBinaryTreeOptimal(root->right);
    int curr = lHeight+rheight;
    maxDiameter = max(curr,maxDiameter);

    return 1+max(lHeight,rheight);
}

int diameter(struct TreeNode *root){
    maxDiameter = 0;
    diameterOfBinaryTreeOptimal(root);
    return maxDiameter;
}

int main(){
    struct TreeNode *root = createNode(1);
    root->right = createNode(2);

    int maxDiameter = diameter(root);
    printf("Max Diameter: %d \n",maxDiameter);
    return 0;
}