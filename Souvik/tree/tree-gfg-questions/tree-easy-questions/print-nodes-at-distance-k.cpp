#include <iostream>
#include <vector>
#include <algorithm>
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

void inOrderArray(Node *root, vector<int>&nodes){
    if(isEmpty(root)){
        return;
    }
    inOrderArray(root->left,nodes);
    nodes.push_back(root->data);
    inOrderArray(root->right,nodes);
}

vector<int>kDistanceNodes(Node *root, int target, int k){
    if(isEmpty(root)){
        return {};
    }

    vector<int>nodes;
    inOrderArray(root,nodes);
    vector<int>result;
}

int main(){
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->right->left = createNode(6);
    root->right->right = createNode(7);

    vector<int>result = kDistanceNodes(root,3,1);
    for(int i:result){
        cout<<i<<" ";
    }

    cout<<endl;
}