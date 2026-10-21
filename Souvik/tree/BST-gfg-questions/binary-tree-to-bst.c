#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100000

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

struct TreeNode *createBST(struct TreeNode *root, int val){
    struct TreeNode *newNode = createNode(val);
    if(isEmpty(root)){
        return newNode;
    }

    if(val<root->val){
        root->left = createBST(root->left,val);
    }else if(val>root->val){
        root->right = createBST(root->right,val);
    }

    return root;
}

void inOrderArray(struct TreeNode *root, int arr[MAX_SIZE],int *j){
    if(isEmpty(root)){
        return;
    }
    inOrderArray(root->left,arr,j);
    arr[*j] = root->val;
    (*j)++;
    inOrderArray(root->right,arr,j);
}

struct TreeNode *binaryTreeToBST(struct TreeNode *root){
    if(isEmpty(root)){
        return NULL;
    }
    int arr[MAX_SIZE];
    int j = 0;
    inOrderArray(root,arr,&j);
    struct TreeNode *newRoot = NULL;
    for(int i = 0; i<j-1; i++){
        for(int k = 0; k<j-i-1; k++){
            if(arr[k]>arr[k+1]){
                int temp = arr[k];
                arr[k] = arr[k+1];
                arr[k+1] = temp;
            }
        }
    }

    for(int i = 0; i<j; i++){
        newRoot = createBST(newRoot,arr[i]);
    }

    return newRoot;
}

void constructBST(struct TreeNode *root,int arr[MAX_SIZE], int *index){
    if(isEmpty(root)){
        return;
    }

    constructBST(root->left,arr,index);
    root->val = arr[(*index)++];
    constructBST(root->right,arr,index);
}

struct TreeNode *binaryTreeToBSTOptimal(struct TreeNode *root){
    if(isEmpty(root)){
        return NULL;
    }
    int arr[MAX_SIZE];
    int j = 0;
    inOrderArray(root,arr,&j);
    for(int i = 0; i<j-1; i++){
        for(int k = 0; k<j-i-1; k++){
            if(arr[k]>arr[k+1]){
                int temp = arr[k];
                arr[k] = arr[k+1];
                arr[k+1] = temp;
            }
        }
    }
    int index = 0;
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
    struct TreeNode *bstRoot = NULL;
    struct TreeNode *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    printf("Binary Tree: \n");
    inOrder(root);

    printf("\n");
    bstRoot = binaryTreeToBSTOptimal(root);
    printf("BST: \n");
    inOrder(bstRoot);
    printf("\n");
    return 0;
}