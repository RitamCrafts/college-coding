#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode *left;
        TreeNode *right;
    TreeNode(int data){
        val = data;
        left = right = NULL;
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

int maxValue = INT_MIN;
void postOrder(TreeNode *root){
    if(isEmpty(root)) return;

    int sum = 0;
    postOrder(root->left);
    postOrder(root->right);
    if(root->left != NULL){
        sum+=root->val+root->left->val;
    }

    if(root->right != NULL){
        sum+=root->right->val;
    }
}

int maxPathSum(TreeNode *root){
    if(isEmpty(root)) return 0;

    int left = maxPathSum(root->left);
    int right = maxPathSum(root->right);


    return root->val+max(left,right);
}

int main(){
    TreeNode *root = createNode(-15);
    root->left = createNode(10);
    root->right = createNode(20);


    root->right->left = createNode(15);
    root->right->left->left = createNode(-5);


    root->right->right = createNode(5);

    int result = maxPathSum(root);
    cout << "Max path sum: " << result << endl;
    return 0;
}