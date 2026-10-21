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

void swapPointer(Node **ptr1, Node **ptr2){
    Node *temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

void mirror(Node *root){
    if(isEmpty(root)){
        return;
    }

    swapPointer(&root->left,&root->right);
    mirror(root->left);
    mirror(root->right);
    
}

void inOrder(Node *root){
    if(isEmpty(root)){
        return;
    }

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int main(){
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    cout<<"Before Inverting: "<<endl;
    inOrder(root);
    cout<<endl;

    mirror(root);
    cout<<"After Inverting: "<<endl;
    inOrder(root);
    cout<<endl;

    return 0;
}