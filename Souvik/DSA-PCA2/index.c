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

struct TreeNode *createBST(struct TreeNode *root, int val){
    if(isEmpty(root)){
        struct TreeNode *newNode = createNode(val);
        return newNode;
    }
    if(val<root->val){
        root->left = createBST(root->left,val);
    }else if(val>root->val){
        root->right = createBST(root->right,val);
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

void preOrder(struct TreeNode *root){
    if(isEmpty(root)){
        return;
    }

    printf("%d ",root->val);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(struct TreeNode *root){
    if(isEmpty(root)){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->val);
}

bool isDatapresent(struct TreeNode *root, int val){
    if(isEmpty(root)){
        return false;
    }

    if(val<root->val){
        return isDatapresent(root->left,val);
    }

    if(val>root->val){
        return isDatapresent(root->right,val);
    }

    return true;
}

struct TreeNode* inOrderSuccessor(struct TreeNode *root) {
    if(isEmpty(root) || isEmpty(root->right))
        return NULL;

    root = root->right;

    while(root->left != NULL)
        root = root->left;

    return root;
}

struct TreeNode *deleteBST(struct TreeNode *root, int val){
    if(isEmpty(root)){
        printf("Tree is Empty.\n");
        return NULL;
    }


    struct TreeNode *temp = NULL;
    if(val<root->val){
        root->left = deleteBST(root->left,val);
    }else if(val>root->val){
        root->right = deleteBST(root->right,val);
    }
    else{
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }else if(root->left == NULL && root->right != NULL){
            temp = root->right;
            free(root);
            return temp;
        }else if(root->left != NULL && root->right == NULL){
            temp = root->left;
            free(root);
            return temp;
        }else{
            temp = inOrderSuccessor(root);
            root->val = temp->val;
            root->right = deleteBST(root->right,temp->val);
        }
    }

    return root;
}



int main(){
    struct TreeNode *root = NULL;
    int ch,val;
    while(true){
        printf("\n .... MENU .... \n");
        printf("1. Create BST \n");
        printf("2. Display Tree preOrder \n");
        printf("3. Display Tree inOrder \n");
        printf("4. Display Tree postOrder \n");
        printf("5. Search Value \n");
        printf("6. Delete Value \n");
        printf("7. Exit \n");
        printf("Enter Your Choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                printf("Enter Value: ");
                scanf("%d",&val);
                root = createBST(root,val);
                break;
            case 2:
                preOrder(root);
                break;
            case 3:
                inOrder(root);
                break;
            case 4:
                postOrder(root);
                break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d",&val);
                if(isDatapresent(root,val) == true){
                    printf("Value is Present.\n");
                }else{
                    printf("Value is absent.\n");
                }

                break;
            case 6:
                printf("Enter Value: ");
                scanf("%d",&val);
                root = deleteBST(root,val);
                break;
            case 7:
                printf("Exit...\n");
                return -1;
            default:
                printf("Invalid Choice.\n");
                break;
            
        }
    }
    return 0;
}