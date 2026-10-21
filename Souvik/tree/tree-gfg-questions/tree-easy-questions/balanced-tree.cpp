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

int height(Node *root){
    if(isEmpty(root)){
        return -1;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1+max(leftHeight,rightHeight);
}

bool isBalanced(Node *root){
    if(isEmpty(root)){
        return true;
    }

    int leftHeightResult = height(root->left);
    int rightHeightResult = height(root->right);
    
    int diff = abs(leftHeightResult-rightHeightResult);

    if(diff>1){
        return false;
    }

    bool leftResult = isBalanced(root->left);
    bool rightResult = isBalanced(root->right);

    return leftResult && rightResult;
}

int main(){
    Node *root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->left->left->left = createNode(120);
    root->left->right = createNode(60);

    if(isBalanced(root) == true){
        cout<<"The tree is balanced"<<endl;
    }else{
        cout<<"The tree is not balanced"<<endl;
    }
    return 0;
}