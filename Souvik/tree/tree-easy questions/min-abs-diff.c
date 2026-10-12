#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_SIZE 10000


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

void inOrder(struct TreeNode *root, int arr[MAX_SIZE], int *index){
    if(isEmpty(root)){
        return;
    }

    inOrder(root->left,arr,index);
    arr[*index] = root->val;
    (*index)++;
    inOrder(root->right,arr,index);
}

int getMinDiff(struct TreeNode *root){
    if(isEmpty(root)){
        return -1;
    }

    int minDiff = INT_MAX;
    int arr[MAX_SIZE];
    int index = 0;
    inOrder(root,arr,&index);
    for(int i = 0; i<index; i++){
        for(int j = i+1; j<index; j++){
            int diff = abs(arr[i]-arr[j]);
            if(diff<minDiff){
                minDiff = diff;
            }
        }
    }

    return minDiff;
}

int main(){
    struct TreeNode *root = createNode(1);
    root->left = createNode(0);
    root->right = createNode(48);
    root->right->left = createNode(12);
    root->right->right = createNode(49);

    int minDiff = getMinDiff(root);
    printf("%d \n",minDiff);
}