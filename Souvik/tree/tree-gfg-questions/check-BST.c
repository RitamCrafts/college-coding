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

void inOrderArray(struct TreeNode *root,int arr[MAX_SIZE],int *j){
    if(isEmpty(root)){
        return;
    }

    inOrderArray(root->left,arr,j);
    arr[*j] = root->val;
    (*j)++;
    inOrderArray(root->right,arr,j);

}

bool isValidBST(struct TreeNode *root){
    if(isEmpty(root)){
        return false;

    }

    int arr[MAX_SIZE];
    int j = 0;
    inOrderArray(root,arr,&j);
    for(int i = 0; i<j-1; i++){
        if(arr[i+1]<arr[i]){
            return false;
        }
    }

    return true;
}

int main(){
    struct TreeNode *root = createNode(10);
    root->left = createNode(5);
    root->right= createNode(20);
    root->right->left = createNode(9);
    root->right->right = createNode(25);


    if(isValidBST(root) == true){
        printf("true\n");
    }else{
        printf("false\n");
    }
    return 0;
}