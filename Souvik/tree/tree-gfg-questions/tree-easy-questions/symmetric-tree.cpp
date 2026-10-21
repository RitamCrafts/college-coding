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

bool isSymmetricUtil(Node *left, Node *right){
    if((left == NULL && right == NULL)){
        return true;
    }

    if((left == NULL && right != NULL) || (left != NULL && right == NULL)){
        return false;
    }

    if((left != NULL && right != NULL) && (left->data != right->data)){
        return false;
    }

    bool leftResult = isSymmetricUtil(left->left,right->right);
    bool rightResult = isSymmetricUtil(left->right,right->left);
    return leftResult && rightResult;
}

bool isSymmetric(Node *root){
    if(isEmpty(root)){
        return true;
    }

    return isSymmetricUtil(root->left,root->right);
}

int main(){
    Node *root = createNode(10);
    root->left = createNode(5);
    root->left->left = createNode(2);
    root->right = createNode(5);
    root->right->right = createNode(2);

    if(isSymmetric(root) == true){
        cout<<"The tree is symmetric"<<endl;
    }else{
        cout<<"The tree is not symmetric"<<endl;
    }
    return 0;
}