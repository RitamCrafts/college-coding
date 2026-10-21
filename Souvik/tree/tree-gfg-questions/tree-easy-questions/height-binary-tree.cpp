#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

bool isEmpty(Node *root){
    return root == NULL;
}

Node *createNode(int val){
    Node *newNode = new Node(val);
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

int main(){
    Node *root = createNode(12);
    root->left = createNode(8);
    root->right = createNode(18);
    root->left->left = createNode(5);
    root->left->right = createNode(11);

    cout<<"Height of tree: "<<height(root)<<endl;
    return 0;
}