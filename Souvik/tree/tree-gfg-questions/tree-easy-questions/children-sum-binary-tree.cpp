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

int getSum(Node *left, Node *right){
    if(isEmpty(left) && isEmpty(right)){
        return 0;
    }else if(isEmpty(left)){
        return right->data;
    }else if(isEmpty(right)){
        return left->data;
    }

    return left->data+right->data;
}

bool isSumProperty(Node *root){
    if(isEmpty(root)){
        return true;
    }
    if(isEmpty(root->left) && isEmpty(root->right)){
        return true;
    }
    int sum = getSum(root->left,root->right);
    if(sum != root->data){
        return false;
    }

    bool leftResult = isSumProperty(root->left);
    bool rightResult = isSumProperty(root->right);

    return leftResult && rightResult;
}

int main(){
    Node *root = createNode(15);
    root->left = createNode(20);
    root->right = createNode(15);
    root->left->left = createNode(15);
    root->left->right = createNode(5);


    root->right->left = createNode(10);
    root->right->right = createNode(5);

    if(isSumProperty(root) == true){
        cout<<"Yes, the given tree satisfies the children sum property"<<endl;
    }else{
        cout<<"No, the given tree does not satisfy the children sum property"<<endl;
    }

    return 0;
}