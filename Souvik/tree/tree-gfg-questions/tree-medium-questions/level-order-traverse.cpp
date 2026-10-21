#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;
    Node(int val){
        data = val;
        left = right = nullptr;
    }
};

bool isEmpty(Node *root){
    return root == NULL;
}

Node *createNode(int val){
    Node *newNode = new Node(val);
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

vector<int>levelOrder(Node *root){
    if(isEmpty(root)){
        return {};
    }

    queue<Node *>q;
    q.push(root);
    vector<int>result;

    while(!q.empty()){
        Node *frontNode = q.front();
        result.push_back(frontNode->data);

        if(frontNode->left != NULL){
            q.push(frontNode->left);
        }

        if(frontNode->right != NULL){
            q.push(frontNode->right);
        }

        q.pop();
    }


    return result;
}

int main(){
    Node *root = createNode(5);
    root->left = createNode(12);
    root->right = createNode(13);
    root->left->left = createNode(7);
    root->left->left->left = createNode(17);
    root->left->left->right = createNode(23);
    root->right->left = createNode(14);
    root->right->right = createNode(2);

    root->right->left->left = createNode(27);
    root->right->left->right = createNode(3);
    root->right->right = createNode(2);
    root->right->right->left = createNode(8);
    root->right->right->right = createNode(11);

    vector<int>result = levelOrder(root);
    for(int i:result){
        cout<<i<<" ";
    }

    cout<<endl;
    return 0;
}