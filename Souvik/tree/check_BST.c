#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int val;
    struct node *left;
    struct node *right;
};


struct node *createNode(int val){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void inorder(struct node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
}

bool isBST(struct node *root) {

    static struct node *prev = NULL;

    if (root != NULL) {

        // Check left subtree
        if (!isBST(root->left)) {
            return false;
        }

        // Check current node
        if (prev != NULL && root->val <= prev->val) {
            return false;
        }

        // Current becomes previous
        prev = root;

        // Check right subtree
        if (!isBST(root->right)) {
            return false;
        }
    }

    return true;
}
int main(){
    struct node *root = createNode(4);
    root->left = createNode(1);
    root->left->left = createNode(0) ;
    root->left->right = createNode(2);
    root->right = createNode(6);

    if(isBST(root) == true){
        printf("Yes, Binary search tree.\n");
    }else{
        printf("No, Not Binary search tree.\n");
    }
    return 0;
}