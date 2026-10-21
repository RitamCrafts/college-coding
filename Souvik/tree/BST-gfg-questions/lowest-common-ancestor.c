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

struct TreeNode *createBST(struct TreeNode *root,int val){
    struct TreeNode *newNode = createNode(val);
    if(isEmpty(root)){
        return newNode;
    }
    else if(val<root->val){
        root->left =  createBST(root->left,val);
    }else if(val>root->val){
        root->right =  createBST(root->right,val);
    }

    return root;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(isEmpty(root)){
        return NULL;
    }

    if(p->val < root->val && q->val < root->val){
        return lowestCommonAncestor(root->left,p,q);
    }else if(p->val > root->val && q->val > root->val){
        return lowestCommonAncestor(root->right,p,q);
    }

    return root;

}

struct TreeNode *lowestCommonAncestorOptimal(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q){
    if(isEmpty(root)){
        return NULL;
    }

    while(root != NULL){
        if(p->val < root->val && q->val < root->val){
            root = root->left;
        }else if(p->val > root->val && q->val > root->val){
            root = root->right;
        }else{
            break;
        }
    }

    return root;
}

void inOrder(struct TreeNode *root){
    if(isEmpty(root)){
        return;
    }

    inOrder(root->left);
    printf("%d ",root->val);
    inOrder(root->right);

}

int main(){
    struct TreeNode *root = NULL;
    struct TreeNode *newRoot = NULL;
    int opt;
    while(true){
        printf("\n ... MENU ... \n");
        printf("1. create BST: \n");
        printf("2. print tree: \n");
        printf("3. get LCA: \n");
        printf("4. get LCA optimal: \n");
        printf("0. Exit: \n");
        printf("Enter Your Choice: ");
        scanf("%d",&opt);

        if(opt == 1){
            int val;
            printf("Enter Val: ");
            scanf("%d",&val);
            root = createBST(root,val);
        }else if(opt == 2){
            inOrder(root);
            printf("\n");
        }else if(opt == 3){
            root = lowestCommonAncestor(root,root->left->left,root->left->right->right);
            printf("LCA value: %d \n",root->val);
        }
        else if(opt == 4){
            newRoot = lowestCommonAncestorOptimal(root,root->left->left,root->left->right->right);
            printf("LCA value: %d \n",newRoot->val);
        }
        else if(opt == 0){
            printf("Exit... \n");
            free(root);
            free(newRoot);
            return -1;
        }
        else{
            printf("Invalid Choice: ");
        }
    }

    return 0;
}