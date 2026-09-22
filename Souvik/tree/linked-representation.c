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

void preOrder(struct node *root){
    if(isEmpty(root)){
        return;
    }

    printf("%d ",root->val);
    preOrder(root->left);
    preOrder(root->right);

}

void inOrder(struct node *root){
    if(isEmpty(root)){
        return;
    }

    inOrder(root->left);
    printf("%d ",root->val);
    inOrder(root->right);
}

void postOrder(struct node *root){
    if(isEmpty(root)){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->val);
}

int main(){
    struct node *root = createNode(4);
    root->left = createNode(1);
    root->left->left = createNode(5);
    root->left->right = createNode(2);
    root->right = createNode(6);

    int opt;
    while(true){
        printf("\n .... MENU .... \n");
        printf("1. Preorder: \n");
        printf("2. Postorder: \n");
        printf("3. Inorder: \n");
        printf("0. Exit: \n");
        printf("Choose Your Option: ");
        scanf("%d",&opt);

        if(opt == 1){
            preOrder(root);
        }else if(opt == 2){
            postOrder(root);
        }else if(opt == 3){
            inOrder(root);
        }else if(opt == 0){
            printf("Exit...\n");
            return -1;
        }else{
            printf("Invalid Choice.\n");
        }
    }
    return 0;
}