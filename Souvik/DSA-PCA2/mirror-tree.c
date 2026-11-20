#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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

void swapPointer(struct TreeNode **ptr1, struct TreeNode **ptr2){
    struct TreeNode *temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

void mirrorTree(struct TreeNode *root){
    if(isEmpty(root)){
        return;
    }

    swapPointer(&root->left,&root->right);
    mirrorTree(root->left);
    mirrorTree(root->right);
}

void inOrder(struct TreeNode *root){
    if(isEmpty(root)){
        return;
    }

    inOrder(root->left);
    printf("%d ",root->val);
    inOrder(root->right);
}

int totalNodes(struct TreeNode *root){
    if(isEmpty(root)) return 0;
    return 1+totalNodes(root->left)+totalNodes(root->right);
}

int totalLeafNodes(struct TreeNode *root){
    if(isEmpty(root)) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    return totalLeafNodes(root->left)+totalLeafNodes(root->right);
}

int totalInternalNodes(struct TreeNode *root){
    if(isEmpty(root)) return 0;
    if((root->left == NULL && root->right != NULL) || 
    (root->right == NULL && root->left != NULL) || 
    (root->left != NULL && root->right != NULL) ){
        return 1+totalInternalNodes(root->left)+totalInternalNodes(root->right);
    }

    return 0;
    
}

int heightTree(struct TreeNode *root){
    if(isEmpty(root)) return 0;

    int leftheight = heightTree(root->left);
    int rightHeight = heightTree(root->right);
    return 1+ (leftheight>rightHeight?leftheight:rightHeight);
}

int minElement(struct TreeNode *root){
    if(isEmpty(root)) return -1;
    while(root->left != NULL){
        root = root->left;
    }

    return root->val;
}
int maxElement(struct TreeNode *root){
    if(isEmpty(root)) return -1;
    while(root->right != NULL){
        root = root->right;
    }

    return root->val;
}

int main(){
    struct TreeNode *root = createNode(40);
    root->left = createNode(20);
    root->right = createNode(60);
    root->right->right = createNode(100);
    printf("Before inversion: ");
    inOrder(root);
    printf("\n");
    mirrorTree(root);
    printf("After Inversion: ");
    inOrder(root);
    printf("\n");
    printf("TotalNodes: %d \n",totalNodes(root));

    printf("Total Leaf Nodes: %d \n",totalLeafNodes(root));
    printf("Total Number of internal nodes: %d \n",totalInternalNodes(root));

    printf("Height: %d \n",heightTree(root));
    printf("Min Element: %d \n",minElement(root));
    printf("Max Element: %d \n",maxElement(root));
    return 0;
}