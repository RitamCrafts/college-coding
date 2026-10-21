#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode *left;
        TreeNode *right;
    TreeNode(int data){
        val = data;
        left = right = nullptr;
    }
};

bool isEmpty(TreeNode *root){
    return root == NULL;
}

TreeNode *createNode(int val){
    TreeNode *newNode = new TreeNode(val);
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode *buildTree(vector<int>&preorder,vector<int>&inorder){
    if(preorder.size() == 0 || inorder.size() == 0) return NULL;

    TreeNode *root = createNode(preorder[0]);
    vector<int>leftTree;
    vector<int>rightTree;
    for(int i = 0; i<inorder.size(); i++){
        if(inorder[i] == preorder[0]){
            for(int j = 0; j<i; j++){
                leftTree.push_back(inorder[j]);
            }

            for(int j = i+1; j<inorder.size(); j++){
                rightTree.push_back(inorder[j]);
            }
        }
    }

    vector<int>preOrderLeftTree(preorder.begin()+1,preorder.begin()+leftTree.size()+1);
    vector<int> preOrderRightTree(preorder.begin() + 1 + leftTree.size(),preorder.end());

    root->left = buildTree(preOrderLeftTree,leftTree);
    root->right = buildTree(preOrderRightTree,rightTree);

    return root;
}

void inorder(TreeNode *root){
    if(isEmpty(root)) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}


int main(){
    vector<int>preOrder = {3,9,20,15,7};
    vector<int>inOrder = {9,3,15,20,7};
    TreeNode *root = buildTree(preOrder,inOrder);
    cout<<"Inorder Printing: "<<endl;
    inorder(root);
    return 0;
}