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

struct TreeNode *searchNode(struct TreeNode *root, int key){
    if(isEmpty(root)){
        return NULL;
    }

    if(key<root->val){
        return searchNode(root->left,key);
    }else if(key>root->val){
        return searchNode(root->right,key);
    }

    return root;
}

int inOrderSuccessor(struct TreeNode *root, int key){
    if(isEmpty(root)){
        return -1;
    }

    struct TreeNode *successor = NULL;
    struct TreeNode *keyNode = searchNode(root,key);

    if(isEmpty(keyNode)){
        while(!isEmpty(root)){
            if(key<root->val){
                successor = root;
                root = root->left;
            }else{
                root = root->right;
            }
        }

        return successor == NULL ? -1 : successor->val;
    }

    else if(keyNode->right != NULL){
        successor = keyNode->right;

        while(successor->left != NULL){
            successor = successor->left;
        }
    }else{
        while(root != NULL){
            if(keyNode->val < root->val){
                successor = root;
                root = root->left;
            }else if(keyNode->val > root->val){
                root = root->right;
            }else{
                break;
            }
        }
    }

    if(isEmpty(successor)){
        return -1;
    }

    return successor->val;
}

int inOrderPre(struct TreeNode *root, int key){
    if(isEmpty(root)){
        return -1;
    }

    struct TreeNode *pre = NULL;
    struct TreeNode *keyNode = searchNode(root,key);

    if(isEmpty(keyNode)){
        while(!isEmpty(root)){
            if(key>root->val){
                pre = root;
                root = root->right;
            }else{
                root = root->left;
            }
        }

        return pre == NULL ? -1 : pre->val;
    }

    else if(keyNode->left != NULL){
        pre = keyNode->left;
        while(pre->right != NULL){
            pre = pre->right;
        }
    }else{
        while(root != NULL){
            if(keyNode->val < root->val){
                root = root->left;
            }else if(keyNode->val > root->val){
                pre = root;
                root = root->right;
            }else{
                break;
            }
        }
    }

    if(isEmpty(pre)){
        return -1;
    }

    return pre->val;
}

void finPreSuc(struct TreeNode *root, int key){
    if(isEmpty(root)){
        return;
    }

    int arr[2];
    int j = 0;
    int pre = inOrderPre(root,key);
    int succ = inOrderSuccessor(root,key);
    for(int i = 0; i<2; i++){
        if(i == 0){
            arr[i] = pre;
        }else{
            arr[i] = succ;
        }
    }

    for(int i = 0; i<2; i++){
        printf("%d ",arr[i]);
    }

    printf("\n");
}

int main(){
    struct TreeNode *root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(70);

    root->left->left = createNode(20);
    root->left->right = createNode(40);

    root->right->left = createNode(60);
    root->right->right = createNode(80);

    finPreSuc(root,65);
    return 0;
}