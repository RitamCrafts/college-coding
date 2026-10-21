#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000
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
    newNode->val  = val;
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

void findCommon(struct TreeNode *root1, struct TreeNode *root2){
    if(isEmpty(root1) || isEmpty(root2)){
        return;
    }

    int arr1[MAX_SIZE];
    int arr2[MAX_SIZE];
    int index1 = 0;
    int index2 = 0;
    int result[MAX_SIZE];
    int resultIndex = 0;

    inOrderArray(root1,arr1,&index1);
    inOrderArray(root2,arr2,&index2);


    for(int i = 0; i<index1; i++){
        for(int j = 0; j<index2; j++){
            if(arr1[i] == arr2[j]){
                result[resultIndex++] = arr1[i];
            }
        }
    }

    for(int i = 0; i<resultIndex; i++){
        printf("%d ",result[i]);
    }

    printf("\n");
}

int main(){
    struct TreeNode *r1 = createNode(5);
    r1->left = createNode(1);
    r1->right = createNode(10);

    r1->left->left = createNode(0);
    r1->left->right = createNode(4);

    r1->right->left = createNode(7);
    r1->right->left->right = createNode(9);

    struct TreeNode *r2 = createNode(10);
    r2->left = createNode(2);
    r2->right = createNode(11);
    r2->left->left = createNode(1);
    r2->left->right = createNode(3);

    findCommon(r1,r2);
    return 0;
}