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

int minDiff(struct TreeNode *root, int key){
    if(isEmpty(root)){
        return INT_MAX;
    }

    int minValue = INT_MAX;
    while(root != NULL){
        if(root->val == key){
            return 0;
        }

        if(key<root->val){
            int diff = abs(key-(root->val));
            if(diff<minValue){
                minValue = diff;
            }

            root = root->left;
        }else if(key>root->val){
            int diff = abs(key-(root->val));
            if(diff<minValue){
                minValue = diff;
            }

            root = root->right;
        }
    }

    return minValue;
}

int main(){
    struct TreeNode *root = createNode(10);

    root->left = createNode(2);
    root->right = createNode(11);

    root->left->left = createNode(1);
    root->left->right = createNode(5);

    root->left->right->left = createNode(3);
    root->left->right->right = createNode(6);

    root->left->right->left->right = createNode(4);

    int result = minDiff(root,13);
    printf("%d \n",result);
    return 0;
}