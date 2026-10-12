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

struct node *insertNode(struct node *root, int val){
    struct node *newNode = createNode(val);
    if(isEmpty(root)){
        return newNode;
    }
    struct node *ptr = root;
    struct node *parentPtr = NULL;
    while (ptr != NULL)
    {
       parentPtr = ptr;

       if(val < ptr->val){
            ptr = ptr->left;
       }else if(val > ptr->val){
            ptr  = ptr->right;
       }else if(val == ptr->val){
            return root;
       }
    }

    if(val<parentPtr->val){
        parentPtr->left = newNode;
    }else if(val > parentPtr->val){
        parentPtr->right = newNode;
    }

    return root;
    
}

bool searchNode(struct node *root, int val){

    if(isEmpty(root)){
        return false;
    }

    if(val == root->val){
        return true;
    }

    if(val < root->val){
        return searchNode(root->left, val);
    }
    else{
        return searchNode(root->right, val);
    }
}

bool searchNodeIterative(struct node *root,int val){
    if(isEmpty(root)){
        printf("Tree is empty.\n");
        return false;
    }

    struct node *ptr = root;
    while(ptr != NULL){
        if(val == ptr->val){
            return true;
        }else if(val<ptr->val){
            ptr = ptr->left;
        }else{
            ptr = ptr->right;
        }
    }

    return false;
}

void preOrder(struct node *root){
    if(!isEmpty(root)){
        printf("%d ",root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(struct node *root){
    if(!isEmpty(root)){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->val);
    }
}
void inOrder(struct node *root){
    if(!isEmpty(root)){
        inOrder(root->left);
        printf("%d ",root->val);
        inOrder(root->right);
    }
}

int main(){
    struct node *root = NULL;
    int opt;
    while(true){
        printf("\n .... MENU .... \n");
        printf("1. For Inserting Node: \n");
        printf("2. For PreOrder: \n");
        printf("3. For Inorder: \n");
        printf("4. For PostOrder: \n");
        printf("5. For searching a node: \n");
        printf("0. For Exit: \n");

        printf("Enter Your Choice: ");
        scanf("%d",&opt);
        if(opt == 1){
            int val;
            printf("Enter Value: ");
            scanf("%d",&val);
            root = insertNode(root,val);
        }else if(opt == 2){
            preOrder(root);
            printf("\n");
        }else if(opt == 3){
            inOrder(root);
            printf("\n");
        }
        else if(opt == 4){
            postOrder(root);
            printf("\n");
        }else if(opt == 0){
            printf("Exit...\n");
            free(root);
            return -1;
        }

        else if(opt == 5){
            int val;
            printf("Enter Node value: ");
            scanf("%d",&val);
            if(searchNodeIterative(root,val) == true){
                printf("Found.\n");
            }else{
                printf("Not Found.\n");
            }
        }

        else{
            printf("Invalid Choice.\n");
        }
    }
    return 0;
}