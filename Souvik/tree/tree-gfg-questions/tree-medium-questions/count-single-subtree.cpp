#include <iostream>
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

bool checkSingle(Node *root){
    if(isEmpty(root)){
        return true;
    }

    bool isSingle = true;
    if(root->left != NULL && root->left->data != root->data){
        isSingle = false;
    }
    if(root->right != NULL && root->right->data != root->data){
        isSingle = false;
    }

    bool leftResult = checkSingle(root->left);
    bool rightResult = checkSingle(root->right);

    return isSingle && leftResult && rightResult;
}

int countSingle(Node *root){
    if(isEmpty(root)){
        return 0;
    }

    int count = 0;
    bool isSingle = checkSingle(root);
    if(isSingle == true){
        count++;
    }

    count+=countSingle(root->left);
    count+=countSingle(root->right);

    return count;
}



int main(){
    Node *root = createNode(5);
    root->left = createNode(1);
    root->right = createNode(5);

    root->left->left = createNode(5);
    root->left->right = createNode(5);


    root->right->right = createNode(5);

    cout<<"Count: "<<countSingle(root)<<endl;
    return 0;
}