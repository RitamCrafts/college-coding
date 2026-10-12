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

struct TreeNode *insertIntoBST(struct TreeNode* root, int val) {
    struct TreeNode *newNode = createNode(val);
    if(isEmpty(root)){
        return newNode;
    }

    if(val<root->val){
        root->left = insertIntoBST(root->left,val);
    }else if(val>root->val){
        root->right = insertIntoBST(root->right,val);
    }


    return root;
}

int main(){
    
    return 0;
}