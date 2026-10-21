#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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

vector<vector<int>>levelOrder(TreeNode *root){
    if(isEmpty(root)){
        return {};
    }

    queue<TreeNode *>q;
    vector<vector<int>>result;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int>levelOrderSubArray;
        for(int i = 0; i<size; i++){
            TreeNode *frontNode = q.front();
            levelOrderSubArray.push_back(frontNode->val);

            if(frontNode->left != NULL){
                q.push(frontNode->left);
            }

            if(frontNode->right != NULL){
                q.push(frontNode->right);
            }

            q.pop();
        }

        result.push_back(levelOrderSubArray);
    }

    return result;
}

vector<int>rightSideView(TreeNode *root){
    if(isEmpty(root)){
        return {};
    }

    vector<vector<int>>levelOrderResult = levelOrder(root);
    vector<int>result;
    for(int i = 0;i<levelOrderResult.size(); i++){
        result.push_back(levelOrderResult[i][levelOrderResult[i].size()-1]);
    }

    return result;
}


int main(){
    TreeNode *root = createNode(1);
    root->left = createNode(2);
    root->left->right = createNode(4);

    root->right = createNode(3);
    root->right->right = createNode(5);

    vector<int>rightSideResult = rightSideView(root);
    cout<<"Right Side: "<<endl;
    for(int i:rightSideResult){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}