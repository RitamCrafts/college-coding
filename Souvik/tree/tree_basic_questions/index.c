#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_SIZE 10000

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

int countNodes(struct node *root){
    if(isEmpty(root)){
        return 0;
    }

    return 1 + countNodes(root->left)+countNodes(root->right);
}

int leafNodeCount(struct node *root){
    if(isEmpty(root)){
        return 0;
    }

    if(root->left == NULL && root->right == NULL){
        return 1;
    }

    return leafNodeCount(root->left)+leafNodeCount(root->right);
}

int sumllNodes(struct node *root){
    if(isEmpty(root)){
        return 0;
    }

    

    return root->val+sumllNodes(root->left)+sumllNodes(root->right);
}

int findMaxNodeValue(struct node *root){
    if(isEmpty(root)){
        return -1;
    }

    int maxValue = root->val;
    int leftMaxValue = findMaxNodeValue(root->left);
    int rightMaxValue = findMaxNodeValue(root->right);

    if(leftMaxValue>maxValue){
        maxValue = leftMaxValue;
    }

    if(rightMaxValue > maxValue){
        maxValue = rightMaxValue;
    }

    return maxValue;
}

int findMinValue(struct node *root){
    if(isEmpty(root)){
        return INT_MAX;
    }

    int minValue = root->val;
    int leftMin = findMinValue(root->left);
    int rightMin = findMinValue(root->right);

    if(leftMin<minValue){
        minValue = leftMin;
    }

    if(rightMin<minValue){
        minValue = rightMin;
    }

    return minValue;
}

int findHeight(struct node *root){
    if(isEmpty(root)){
        return 0;
    }

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    int maxHeight = INT_MIN;

    if(leftHeight>maxHeight){
        maxHeight = leftHeight;
    }

    if(rightHeight > maxHeight){
        maxHeight = rightHeight;
    }

    return 1+maxHeight;
}

struct node *insertNode(struct node *root, int val){
    if(isEmpty(root)){
        return createNode(val);
    }

    if(val<root->val){
        root->left = insertNode(root->left,val);
    }else if(val>root->val){
        root->right = insertNode(root->right,val);
    }

    return root;
}

void preOrder(struct node *root, int arr[], int *index) {
    if (isEmpty(root)) {
        return;
    }

    arr[*index] = root->val;
    (*index)++;

    preOrder(root->left, arr, index);
    preOrder(root->right, arr, index);
}

bool searchElement(struct node *root, int val) {
    if (isEmpty(root)) {
        return false;
    }

    int arr[MAX_SIZE];
    int index = 0;

    preOrder(root, arr, &index);

    for (int i = 0; i < index; i++) {
        if (arr[i] == val) {
            return true;
        }
    }

    return false;
}

int main(){
    struct node *root = createNode(10);
    root->left = createNode(11);
    root->left->left = createNode(12);
    root->left->right = createNode(34);
    root->right = createNode(13);


    printf("Total Node Count: %d \n",countNodes(root));
    printf("Total LeafNode Count: %d \n",leafNodeCount(root));
    printf("Sum of All Nodes: %d \n ",sumllNodes(root));
    printf("Max Value: %d \n",findMaxNodeValue(root));
    printf("Min Value: %d \n",findMinValue(root));
    printf("Height: %d \n",findHeight(root));

    int val;
    printf("Enter Value to find: ");
    scanf("%d",&val);

    if(searchElement(root,val) == true){
        printf("Found.\n");
    }else{
        printf("Not Found.\n");
    }

    printf("\n");
    return 0;
}