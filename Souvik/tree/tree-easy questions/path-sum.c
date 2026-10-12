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


bool hasPathSum(struct TreeNode *root, int targetSum){
    if(isEmpty(root)){
        return false;
    }

    int sum = 0;
    sum+=root->val;

    targetSum = targetSum-sum;
    if(root->left == NULL && root->right == NULL){
        if(targetSum == 0){
            return true;
        }
    }


    bool leftResult = hasPathSum(root->left,targetSum);
    bool rightResult = hasPathSum(root->right,targetSum);

    if(leftResult == true || rightResult == true){
        return true;
    }

    return false;
}


int main(){
    struct TreeNode *root = createNode(5);
    root->left = createNode(4);
    root->right = createNode(8);
    root->right->left = createNode(13);
    root->right->right = createNode(4);
    root->right->right->right = createNode(1);
    root->left->left = createNode(11);
    root->left->left->left = createNode(7);
    root->left->left->right = createNode(2);

    int targetSum = 22;
    if(hasPathSum(root,22) == true){
        printf("Found");
    }else{
        printf("Not Found");
    }
    return 0;
}