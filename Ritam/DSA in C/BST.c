#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int val;
    struct node *left;
    struct node *right;
};

int isEmpty(struct node *root){
    return root==NULL;
}

struct node *insert(struct node *root, int val){
    if(root==NULL){
        struct node *newNode = (struct node*)malloc(sizeof(struct node));
        newNode->left=newNode->right=NULL;
        newNode->val=val;
        return newNode;
    }
    if(val<root->val){
        root->left=insert(root->left,val);
    }
    else if(val>root->val){
        root->right=insert(root->right,val);
    }
    return root;
}

int smallest(struct node *root){//empty check req
    if(root->left==NULL) return root->val;
    return smallest(root->left);
}
int largest(struct node *root){//empty check req
    if(root->right==NULL) return root->val;
    return largest(root->right);
}

struct node *find(struct node *root, int val){
    if(root==NULL){
        printf("Value \"%d\" not found.",val);
        return NULL;
    }

    if(val<root->val)
        return find(root->left,val);
    else if(val>root->val)
        return find(root->right,val);
    else if(val==root->val)
        return root;
}

struct node *delete(struct node *root, int val){
    if(root==NULL){
        printf("Value %d not found.",val);
        return NULL;
    }
    //FINDING
    if(root->val<val)
        root->right = delete(root->right,val);
    else if(root->val>val)
        root->left = delete(root->left,val);
    else{
        //FOUND
        //0 child
        if(root->left==NULL && root->right==NULL){
            free(root);
            return NULL;
        }
        //2 child(ioOrder successor method i choose)
        else if(root->left!=NULL && root->right!=NULL){
            root->val=smallest(root->right);
            root->right = delete(root->right,root->val);
            return root;
        }
        //1 child
        else if(root->left!=NULL){//both  == and both != alr checked
            struct node *temp=root->left;
            free(root);
            return temp;
        }
        else if(root->right!=NULL){//both  == and both != alr checked
            struct node *temp=root->right;
            free(root);
            return temp;
        }
    }
    return root;
}

void inOrder(struct node *root){
    if(root==NULL) return;
    inOrder(root->left);
    printf("%d ",root->val);
    inOrder(root->right);
}
void preOrder(struct node *root){
    if(root==NULL) return;
    printf("%d ",root->val);
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(struct node *root){
    if(root==NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->val);
}

int main(){//generated with AI
    struct node *bst = NULL;
    int choice, val;

    while(1){
        printf("\n=== BST MENU ===\n");
        printf("[1] Insert    [2] Delete     [3] Find\n");
        printf("[4] Smallest  [5] Largest    [6] In-Order\n");
        printf("[7] Pre-Order [8] Post-Order [9] Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Value to insert: ");
                scanf("%d", &val);
                bst = insert(bst, val);
                break;

            case 2:
                if(isEmpty(bst))
                    printf("Tree is empty.\n");
                else{
                    printf("Value to delete: ");
                    scanf("%d", &val);
                    bst = delete(bst, val);
                }
                break;

            case 3:
                if(isEmpty(bst))
                    printf("Tree is empty.\n");
                else{
                    printf("Value to find: ");
                    scanf("%d", &val);
                    struct node *res = find(bst, val);
                    if(res != NULL){
                        if(res == bst)
                            printf("Value \"%d\" found at ROOT.\n", val);
                        else
                            printf("Value \"%d\" found.\n", val);
                    }
                }
                break;

            case 4:
                if(isEmpty(bst))
                    printf("Tree is empty.\n");
                else
                    printf("Smallest: %d\n", smallest(bst));
                break;

            case 5:
                if(isEmpty(bst))
                    printf("Tree is empty.\n");
                else
                    printf("Largest: %d\n", largest(bst));
                break;

            case 6:
                if(isEmpty(bst))
                    printf("Tree is empty.\n");
                else{
                    printf("In-Order: ");
                    inOrder(bst);
                    printf("\n");
                }
                break;

            case 7:
                if(isEmpty(bst))
                    printf("Tree is empty.\n");
                else{
                    printf("Pre-Order: ");
                    preOrder(bst);
                    printf("\n");
                }
                break;

            case 8:
                if(isEmpty(bst))
                    printf("Tree is empty.\n");
                else{
                    printf("Post-Order: ");
                    postOrder(bst);
                    printf("\n");
                }
                break;

            case 9:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}