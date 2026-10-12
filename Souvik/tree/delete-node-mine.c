#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isEmpty(struct TreeNode *root) {
    return root == NULL;
}

struct TreeNode *createNode(int val) {
    struct TreeNode *newNode =
        (struct TreeNode *)malloc(sizeof(struct TreeNode));

    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct TreeNode *insertNode(struct TreeNode *root, int val) {

    if (isEmpty(root)) {
        return createNode(val);
    }

    if (val < root->val) {
        root->left = insertNode(root->left, val);
    }
    else if (val > root->val) {
        root->right = insertNode(root->right, val);
    }

    return root;
}

struct TreeNode *searchNode(struct TreeNode *root, int val) {

    if (isEmpty(root)) {
        return NULL;
    }

    if (val < root->val) {
        return searchNode(root->left, val);
    }
    else if (val > root->val) {
        return searchNode(root->right, val);
    }

    return root;
}

bool isLeafNode(struct TreeNode *root) {

    if (isEmpty(root)) {
        return false;
    }

    if (root->left == NULL && root->right == NULL) {
        return true;
    }

    return false;
}

struct TreeNode *inOrderPredecessor(struct TreeNode *root) {

    if (isEmpty(root) || root->left == NULL) {
        return NULL;
    }

    root = root->left;

    while (root->right != NULL) {
        root = root->right;
    }

    return root;
}

struct TreeNode *findParent(struct TreeNode *root, int val) {

    if (isEmpty(root)) {
        return NULL;
    }

    if (root->left != NULL && root->left->val == val) {
        return root;
    }

    if (root->right != NULL && root->right->val == val) {
        return root;
    }

    if (val < root->val) {
        return findParent(root->left, val);
    }
    else if (val > root->val) {
        return findParent(root->right, val);
    }

    return NULL;
}

struct TreeNode *deleteNode(struct TreeNode *root, int val) {

    if (isEmpty(root)) {
        return NULL;
    }

    // Search the node
    if (val < root->val) {

        root->left = deleteNode(root->left, val);
    }
    else if (val > root->val) {

        root->right = deleteNode(root->right, val);
    }

    // Node found
    else {

        // CASE 1: Leaf node
        if (root->left == NULL && root->right == NULL) {

            free(root);
            return NULL;
        }

        // CASE 2: Only left child
        else if (root->left != NULL && root->right == NULL) {

            struct TreeNode *temp = root->left;

            free(root);

            return temp;
        }

        // CASE 3: Only right child
        else if (root->left == NULL && root->right != NULL) {

            struct TreeNode *temp = root->right;

            free(root);

            return temp;
        }

        // CASE 4: Two children
        else {

            struct TreeNode *iPre =
                inOrderPredecessor(root);

            root->val = iPre->val;

            root->left =
                deleteNode(root->left, iPre->val);
        }
    }

    return root;
}

void inOrder(struct TreeNode *root) {

    if (isEmpty(root)) {
        return;
    }

    inOrder(root->left);

    printf("%d ", root->val);

    inOrder(root->right);
}

int main() {

    struct TreeNode *root = NULL;

    root = insertNode(root, 1);
    root = insertNode(root, 0);
    root = insertNode(root, 2);
    root = insertNode(root, 3);

    inOrder(root);

    printf("\n");

    root = deleteNode(root, 2);

    inOrder(root);

    printf("\n");

    return 0;
}