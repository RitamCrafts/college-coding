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

bool isSameTree(struct TreeNode *p, struct TreeNode *q){
    if(isEmpty(p) && isEmpty(q)){
        return true;
    }

    if(isEmpty(p) || isEmpty(q)){
        return false;
    }

    if(p->val != q->val){
        return false;
    }

    if((p->left == NULL && q->left != NULL)||
    (p->left != NULL && q->left == NULL)||
    (p->right == NULL && q->right != NULL)||
    (p->right != NULL && q->right == NULL)){
        return false;
    }

    bool resultOne = isSameTree(p->left,q->left);
    bool resultTwo = isSameTree(p->right,q->right);

    return resultOne && resultTwo;
}

int main(){
    struct TreeNode *rootOne = createNode(10);
    rootOne->left = createNode(11);
    rootOne->left->left = createNode(120);
    rootOne->left->right = createNode(34);
    rootOne->right = createNode(13);


    struct TreeNode *rootTwo = createNode(10);
    rootTwo->left = createNode(11);
    rootTwo->left->left = createNode(120);
    rootTwo->left->right = createNode(34);
    rootTwo->right = createNode(13);

    if(isSameTree(rootOne,rootTwo) == true){
        printf("Both trees are same\n");
    }else{
        printf("Both trees are not same\n");
    }
    return 0;
}