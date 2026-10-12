#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10000
int j = 0;

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

void inOrder(struct TreeNode *root, int arr[MAX_SIZE],int *j){
    if(isEmpty(root)){
        return;
    }

    inOrder(root->left,arr,j);
    arr[*j] = root->val;
    (*j)++;
    inOrder(root->right,arr,j);
}

bool isValidBST(struct TreeNode* root) {
    if(isEmpty(root)){
        return false;
    }

    int arr[MAX_SIZE];
    int j = 0;
    inOrder(root,arr,&j);
    for(int i = 0; i<j; i++){
        if(arr[i]>arr[i+1]){
            return false;
        }
    }

    return true;

}

int main(){
    struct TreeNode *root = createNode(2);
    root->left = createNode(2);
    root->right = createNode(2);

    if(isValidBST(root) == true){
        printf("true\n");
    }else{
        printf("false\n");
    }
    return 0;
}