#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool isMirror(struct TreeNode *left, struct TreeNode *right){
    if(isEmpty(left)&&isEmpty(right)){
        return true;
    }

    if(isEmpty(left)||isEmpty(right)){
        return false;
    }

    if(left->val != right->val){
        return false;
    }

    bool resultOne = isMirror(left->left,right->right);
    bool resultTwo = isMirror(left->right,right->left);

    if(resultOne == true && resultTwo == true){
        return true;
    }

    return false;


}

bool isSymmetric(struct TreeNode *root){
    if(isEmpty(root)){
        return false;
    }
    if(isMirror(root->left,root->right) == true){
        return true;
    }

    return false;
}

int main(){
    struct TreeNode *root = createNode(1);
    root->left = createNode(2);
    root->left->left = createNode(3);
    root->left->right = createNode(4);
    root->right = createNode(2);
    root->right->left = createNode(4);
    root->right->right = createNode(3);

    if(isSymmetric(root) == true){
        printf("Symmetric.\n");
    }else{
        printf("Not Symmetric.\n");
    }

    return 0;
}