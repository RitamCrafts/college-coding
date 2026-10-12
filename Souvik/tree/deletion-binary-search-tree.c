#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int val;
    struct node *left;
    struct node *right;
};

bool isEmpty(struct node *root){
    return root == NULL;
}

struct node *createNode(int val){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct node *inOrderPredecessor(struct node *root){
    // left subtree ka right most child

    root = root->left;
    while(root->right != NULL){
        root = root->right;
    }

    return root;
}

struct node *deleteNode(struct node *root, int val){
    // search for the node to be deleted.
    struct node *iPre;
    if(isEmpty(root)){
        return NULL;
    }

    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }

    if(val<root->val){
        root->left = deleteNode(root->left,val);
    }else if(val>root->val){
        root->right = deleteNode(root->right,val);
    }

    // deletion strategy
    else {
        iPre = inOrderPredecessor(root);
        root->val = iPre->val;
        root->left = deleteNode(root->left,iPre->val);
    }

    return root;
}

void inOrder(struct node *root){
    if(isEmpty(root)){
        return;
    }

    inOrder(root->left);
    printf("%d ",root->val);
    inOrder(root->right);
}

int main(){
    struct node *root = createNode(1);
    root->left = createNode(0);
    root->right = createNode(2);

    inOrder(root);
    printf("\n");
    deleteNode(root,2);
    inOrder(root);
    printf("\n");
}