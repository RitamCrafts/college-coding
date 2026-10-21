#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode *left;
        TreeNode *right;
    TreeNode(int val){
        data = val;
        left = right = nullptr;
    }
};

bool isEmpty(TreeNode *root){
    return root == NULL;
}

TreeNode *createNode(int val){
    TreeNode *newNode = new TreeNode(val);
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}



TreeNode *lowestCommonAncestor(TreeNode *root,TreeNode *p, TreeNode *q){
    if(isEmpty(root)){
        return NULL;
    }

    while(root != NULL){
        if(root->data>p->data && root->data > q->data){
            root = root->left;
        }else if(root->data<p->data && root->data<q->data){
            root = root->right;
        }else{
            break;
        }
    }

    return root;
}

int main(){
    TreeNode *root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(8);
    root->left->left = createNode(1);
    root->left->right = createNode(4);
    root->left->left->right = createNode(2);
    root->right->left = createNode(7);
    root->right->right = createNode(9);

    TreeNode *result = lowestCommonAncestor(root,root->left,root->right);
    cout<<"Value of LCA: "<<result->data<<endl;

    return 0;
}