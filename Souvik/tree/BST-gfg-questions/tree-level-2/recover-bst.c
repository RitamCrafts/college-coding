#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10000

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

void inOrderArray(struct TreeNode *root, int arr[MAX_SIZE], int *index){
    if(isEmpty(root)){
        return;
    }

    inOrderArray(root->left,arr,index);
    arr[*index] = root->val;
    (*index)++;
    inOrderArray(root->right,arr,index);
}


void constructBST(struct TreeNode *root, int arr[MAX_SIZE], int *index){
    if(isEmpty(root)){
        return;
    }

    constructBST(root->left,arr,index);
    root->val = arr[*index];
    (*index)++;
    constructBST(root->right,arr,index);
}

struct TreeNode *coorectBST(struct TreeNode *root){
    if(isEmpty(root)){
        return NULL;
    }

    int arr[MAX_SIZE];
    int index = 0;
    inOrderArray(root,arr,&index);
    for(int i = 0; i<index-1; i++){
        for(int j = 0; j<index-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    constructBST(root,arr,&index);
    return root;
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
    struct TreeNode* root = createNode(10);

    root->left = createNode(5);
    root->right = createNode(8);

    root->left->left = createNode(2);
    root->left->right = createNode(20);

    inOrder(root);
    printf("\n");
    coorectBST(root);
    inOrder(root);
    printf("\n");
    return 0;
}