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
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int height(Node *root){
    if(isEmpty(root)){
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1+max(leftHeight,rightHeight);
}

int maxDiameter = 0;

int diameterRecursion(Node *root){
    if(isEmpty(root)){
        return 0;
    }

    int leftHeight = diameterRecursion(root->left);
    int rightHeight = diameterRecursion(root->right);

    if(leftHeight+rightHeight > maxDiameter){
        maxDiameter = leftHeight+rightHeight;
    }

    return 1+max(leftHeight,rightHeight);
}

int diameter(Node *root){
    maxDiameter = 0;
    diameterRecursion(root);
    return maxDiameter;
}

int main(){
    Node *root = createNode(5);
    root->left = createNode(8);
    root->right = createNode(6);

    root->left->left = createNode(3);
    root->left->right = createNode(7);

    root->right->left = createNode(9);

    cout<<"Diameter is: "<<diameter(root)<<endl;
    return 0;
}