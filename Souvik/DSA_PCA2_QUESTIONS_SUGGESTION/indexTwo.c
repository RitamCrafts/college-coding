#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isEmpty(struct TreeNode *root){
    return root == NULL;
}

struct TreeNode *createNode(int val){
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right =NULL;
    return newNode;
}

struct TreeNode *createBST(struct TreeNode *root, int val){
    if(isEmpty(root)){
        struct TreeNode *newNode = createNode(val);
        return newNode;
    }

    if(val<root->data){
        root->left =  createBST(root->left,val);
    }else if(val>root->data){
        root->right =  createBST(root->right,val);
    }

    return root;
}

void inOrder(struct TreeNode *root){
    if(isEmpty(root)) return;
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}

void preOrder(struct TreeNode *root){
    if(isEmpty(root)) return;
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(struct TreeNode *root){
    if(isEmpty(root)) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->data);
}

bool searchBST(struct TreeNode *root,int val){
    if(isEmpty(root)){
        return false;
    }

    if(val<root->data){
        return searchBST(root->left,val);
    }else if(val>root->data){
        return searchBST(root->right,val);
    }

    return true;
}

struct TreeNode *inOrderSuccessor(struct TreeNode *root){
    if(isEmpty(root)) return NULL;

    if(root->right != NULL){
        root = root->right;
    }

    while(root->left != NULL){
        root = root->left;
    }

    return root;
}

struct TreeNode *deleteNode(struct TreeNode *root,int val){
    if(isEmpty(root)){
        return NULL;
    }

    if(val<root->data){
        root->left =  deleteNode(root->left,val);
    }else if(val>root->data){
        root->right =  deleteNode(root->right,val);
    }else{
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }else if(root->left == NULL && root->right != NULL){
            struct TreeNode *temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL && root->left != NULL){
            struct TreeNode *temp = root->left;
            free(root);
            return temp;
        }else{
            struct TreeNode *temp = inOrderSuccessor(root);
            root->data = temp->data;
            root->right = deleteNode(root->right,temp->data);
        }
    }

    return root;
}

void swapPointer(struct TreeNode **ptr1, struct TreeNode **ptr2){
    struct TreeNode *temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

struct TreeNode *mirrorTree(struct TreeNode *root){
    if(isEmpty(root)) return NULL;
    swapPointer(&root->left,&root->right);

    root->left = mirrorTree(root->left);
    root->right = mirrorTree(root->right);
    return root;
}

int totalNodes(struct TreeNode *root){
    if(isEmpty(root)) return 0;

    return 1+ totalNodes(root->left) + totalNodes(root->right);
}

int totalLeafNodes(struct TreeNode *root){
    if(isEmpty(root)) return 0;

    if(root->left == NULL && root->right == NULL){
        return 1;
    }

    return totalLeafNodes(root->left)+totalLeafNodes(root->right);
}

int totalInternalNodes(struct TreeNode *root){
    if(isEmpty(root)) return 0;

    int totalNodesCount = totalNodes(root);
    int totalLeadNodesCount = totalLeafNodes(root);

    return totalNodesCount - totalLeadNodesCount;
}

int height(struct TreeNode *root){
    if(isEmpty(root)) return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1+ (leftHeight>rightHeight?leftHeight:rightHeight);
}

int minElement(struct TreeNode *root){
    if(isEmpty(root)) return -1;

    while(root->left != NULL){
        root = root->left;
    }

    return root->data;
}

int maxElement(struct TreeNode *root){
    if(isEmpty(root)) return -1;

    while(root->right != NULL){
        root = root->right;
    }

    return root->data;
}

int main(){
    struct TreeNode *root = NULL;
    int opt, val;
    while(true){
        printf(" \n .... MENU .... \n ");
        printf("1. Create BST: \n");
        printf("2. Inorder: \n");
        printf("3. Preorder: \n");
        printf("4. Postorder: \n");
        printf("5. Search in BST: \n");
        printf("6. Delete Node in BST: \n");
        printf("7. Derive Mirror Image: \n");
        printf("8. Total Nodes: \n");
        printf("9. Total Leaf Nodes: \n");
        printf("10. Total Internal Nodes: \n");
        printf("11. Calculate Height: \n");
        printf("12. Find Max Element: \n");
        printf("13. Find Min Element: \n");
        printf("14. Exit: \n");
        printf("Enter Your Choice: ");
        scanf("%d",&opt);

        switch(opt){
            case 1:
                printf("Enter Value: ");
                scanf("%d",&val);
                root = createBST(root,val);
                break;

            case 2:
                printf("Inorder Display: \n");
                inOrder(root);
                printf("\n");
                break;
            
            case 3:
                printf("Preorder Display: \n");
                preOrder(root);
                printf("\n");
                break;
            
            case 4:
                printf("Postorder Display: \n");
                postOrder(root);
                printf("\n");
                break;

            case 5:
                printf("Enter Value: ");
                scanf("%d",&val);
                if(searchBST(root,val) == true){
                    printf("Value Found.\n");
                }else{
                    printf("Value not Found.\n");
                }
                break;

            case 6:
                printf("Enter Value to search: ");
                scanf("%d",&val);
                if(searchBST(root,val) == false){
                    printf("Value not found.\n");
                }else{
                    root = deleteNode(root,val);
                }
                break;

            case 7:
                printf("Original Tree Before Swapping: \n");
                preOrder(root);
                printf("\n");

                root = mirrorTree(root);

                printf("After Mirror Image: \n");
                preOrder(root);
                printf("\n");
                break;
            
            case 8:
                printf("Total Nodes: %d \n",totalNodes(root));
                break;
            
            case 9:
                printf("Total Leaf Nodes: %d \n",totalLeafNodes(root));
                break;
            
            case 10:
                printf("Total Internal Nodes: %d \n",totalInternalNodes(root));
                break;

            case 11:
                printf("Height: %d \n",height(root));
                break;

            case 12:
                printf("Max Element: %d \n",maxElement(root));
                break;

            case 13:
                printf("Min Element: %d \n", minElement(root));
                break;

            case 14:
                printf("Exit Successfull...\n");
                free(root);
                return -1;
            
            default:
                printf("Invalid Choice...\n");
                break;
            
        }

    }

    free(root);
    return 0;
}