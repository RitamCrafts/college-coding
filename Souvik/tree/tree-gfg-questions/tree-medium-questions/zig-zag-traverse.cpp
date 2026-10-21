#include <iostream>
#include <queue>
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

TreeNode *createTreeNode(int val){
    TreeNode *newTreeNode = new TreeNode(val);
    newTreeNode->data = val;
    newTreeNode->left = NULL;
    newTreeNode->right = NULL;

    return newTreeNode;
}

vector<vector<int>>levelOrder(TreeNode *root){
    if(isEmpty(root)){
        return {};
    }
    vector<vector<int>>result;
    queue<TreeNode *>q;
    q.push(root);

    while(!q.empty()){
        vector<int>resultSubArray;
        int size = q.size();;
        for(int i = 0; i<size; i++){
            TreeNode *frontTreeNode = q.front();
            resultSubArray.push_back(frontTreeNode->data);

            if(frontTreeNode->left != NULL){
                q.push(frontTreeNode->left);
            }

            if(frontTreeNode->right != NULL){
                q.push(frontTreeNode->right);
            }

            q.pop();
        }
        result.push_back(resultSubArray);
    }

    return result;
}

vector<int>zigZagTraversal(TreeNode *root){
    if(isEmpty(root)){
        return {};
    }

    vector<vector<int>>levelOrderResult = levelOrder(root);
    for(int i = 0; i<levelOrderResult.size(); i++){
        if(i%2 != 0){
            reverse(levelOrderResult[i].begin(),levelOrderResult[i].end());
        }
    }

    vector<int>finalResult;
    for(vector<int>i:levelOrderResult){
        for(int j:i){
            finalResult.push_back(j);
        }
    }

    return finalResult;
}

int main(){
    TreeNode *root = createTreeNode(5);
    root->left = createTreeNode(12);
    root->right = createTreeNode(13);
    root->left->left = createTreeNode(7);
    root->left->left->left = createTreeNode(17);
    root->left->left->right = createTreeNode(23);
    root->right->left = createTreeNode(14);
    root->right->right = createTreeNode(2);

    root->right->left->left = createTreeNode(27);
    root->right->left->right = createTreeNode(3);
    root->right->right = createTreeNode(2);
    root->right->right->left = createTreeNode(8);
    root->right->right->right = createTreeNode(11);


    vector<vector<int>>result = levelOrder(root);
    for(vector<int>i: result){
        for(int j:i){
            cout<<"[ "<<j<<" ]"<<" ";
        }
        cout<<endl;
    }

    vector<int>zigZagResult = zigZagTraversal(root);
    cout<<"Zig Zag Traversal: ";
    for(int i:zigZagResult){
        cout<<i<<" ";
    }

    return 0;
}