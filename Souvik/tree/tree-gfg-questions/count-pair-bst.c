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

struct TreeNode *createNode(struct TreeNode *root, int val){
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void inOrderArray(struct TreeNode *root, int arr[MAX_SIZE],int *index){
    if(isEmpty(root)){
        return;
    }
    inOrderArray(root->left,arr,index);
    arr[*index] = root->val;
    (*index)++;
    inOrderArray(root->right,arr,index);
}

int countPairs(struct TreeNode *root1, struct TreeNode *root2, int val){
    if(isEmpty(root1) && isEmpty(root2)){
        return 0;
    }
    int arr[MAX_SIZE];
    int j = 0;
    inOrderArray(root1,arr,&j);
    inOrderArray(root2,arr,&j);

    for(int i = 0; i<j-1; i++){
        for(int k = 0; k<j-i-1; k++){
            if(arr[k]>arr[k+1]){
                int temp = arr[k];
                arr[k] = arr[k+1];
                arr[k+1] = temp;
            }
        }
    }

    int count = 0;
    for(int i = 0; i<j; i++){
        for(int k = i+1; k<j; k++){
            if(arr[i]+arr[k]==val){
                count++;
            }
        }
    }

    return count;
}
int main(){
    struct TreeNode *root1 = createNode(root1,7);
    root1->left = createNode(root1,5);
    root1->left->left = createNode(root1,1);
    root1->right = createNode(root1,10);
    struct TreeNode *root2= createNode(root2,2);
    root2->right = createNode(root2,6);

    int count = countPairs(root1,root2,9);
    printf("Count: %d\n",count);
    return 0;
}