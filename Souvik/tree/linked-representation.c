#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int val){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preorder(struct node *root){
    if(root != NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postOrder(struct node *root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}

int main(){
    int rootNodeVal;
    printf("Enter Root Node Value: ");
    scanf("%d",&rootNodeVal);

    struct node *p = createNode(rootNodeVal);

    int nodeValOne,nodeValTwo;
    printf("Enter Value of Node One: ");
    scanf("%d",&nodeValOne);
    printf("Enter Value of Node Two: ");
    scanf("%d",&nodeValTwo);
    struct node *p1 = createNode(nodeValOne);
    struct node *p2 = createNode(nodeValTwo);
    p->left = p1;
    p->right = p2;

    printf("Preorder Traversal: \n");
    preorder(p);
    printf("\n");
    printf("Postorder Traversal: \n");
    postOrder(p);
    printf("\n");
    return 0;
}