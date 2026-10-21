#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ct = 0;
class TreeNode{
    public:
        int val;
        TreeNode *left;
        TreeNode *right;
    TreeNode(int val){
        val = val;
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

void find(TreeNode *root, int mx){
    if(isEmpty(root)) return;

    if(root->val>=mx){
        ct++;
    }

    find(root->left,max(mx,root->val));
    find(root->right,max(mx,root->val));
}

int goodNodes(TreeNode *root){
    if(isEmpty(root)) return -1;

    find(root,INT_MIN);
    return ct;
}



int main(){
    cout<< "Hello Souvik"<< endl;
    return 0;
}