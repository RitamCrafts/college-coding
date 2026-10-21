#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10000

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

void inOrder(struct TreeNode *root){
    if(isEmpty(root)){
        return;
    }

    inOrder(root->left);
    printf("%d ",root->val);
    inOrder(root->right);

}

void inOrderArray(struct TreeNode *root, int arr[MAX_SIZE], int *j){
    if(isEmpty(root)){
        return;
    }

    inOrderArray(root->left,arr,j);
    arr[*j]= root->val;
    (*j)++;
    inOrderArray(root->right,arr,j);
}


int countNodes(struct TreeNode *root, int l, int h){
    if(isEmpty(root)){
        return -1;
    }

    int arr[MAX_SIZE];
    int j = 0;

    inOrderArray(root,arr,&j);
    int count = 0;
    for(int i = 0; i<j; i++){
        if(arr[i]>=l && arr[i]<=h){
            count++;
        }
    }

    return count;
}

int countNodesOptinal(struct TreeNode *root, int l, int h){
    if(isEmpty(root)){
        return 0;
    }

    int leftCount = 0;
    int rightCount = 0;
    int nodeCount = 0;
    if(root->val < l){
        leftCount = countNodesOptinal(root->right,l,h);
    }else if(root->val > h){
        rightCount = countNodesOptinal(root->left,l,h);
    }else{
        nodeCount++;
        leftCount = countNodesOptinal(root->left,l,h);
        rightCount = countNodesOptinal(root->right,l,h);
        
    }

    return nodeCount+leftCount+rightCount;
}

int main(){
    struct TreeNode *root = NULL;
    int opt;
    while(true){
        printf("\n ... MENU ... \n");
        printf("1. create BST: \n");
        printf("2. print tree: \n");
        printf("3. count nodes in range: \n");
        printf("4. count nodes in optimal approach: \n");
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
            int l,h;
            printf("Enter Range: ");
            scanf("%d %d",&l,&h);
            int count = countNodes(root,l,h);
            printf("Count: %d\n",count);
        }
        else if(opt == 4){
            int l,h;
            printf("Enter Range: ");
            scanf("%d %d",&l,&h);
            int count = countNodesOptinal(root,l,h);
            printf("Count: %d\n",count);
        }
        else if(opt == 0){
            printf("Exit...");
            free(root);
            return -1;
        }
        else if(opt == 0){
            printf("Exit...\n ");
            free(root);
            return -1;
        }else{
            printf("Invalid Choice: ");
        }
    }

    return 0;
}