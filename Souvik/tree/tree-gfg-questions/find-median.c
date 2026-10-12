#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100000

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

    if(val<root->val){
        root->left = createBST(root->left,val);
    }else if(val>root->val){
        root->right = createBST(root->right,val);
    }

    return root;
}

void inOrderArray(struct TreeNode *root, int arr[MAX_SIZE],int *j){
    if(isEmpty(root)){
        return;
    }
    inOrderArray(root->left,arr,j);
    arr[*j] = root->val;
    (*j)++;
    inOrderArray(root->right,arr,j);
}

int findMedian(struct TreeNode *root){
    if(isEmpty(root)){
        return -1;
    }
    int j = 0;
    int arr[MAX_SIZE];
    inOrderArray(root,arr,&j);

    if(j%2 == 0){
        return arr[(j)/2-1];
    }

    return arr[j/2];
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
    int opt;
    struct TreeNode *root = NULL;
    while(true){
        printf("\n ... MENU ... \n");
        printf("1. create BST: \n");
        printf("2. print tree: \n");
        printf("3. find median: \n");
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
            int median = findMedian(root);
            printf("Median: %d\n",median);
        }else if(opt == 0){
            break;
        }
    }
    return 0;
}