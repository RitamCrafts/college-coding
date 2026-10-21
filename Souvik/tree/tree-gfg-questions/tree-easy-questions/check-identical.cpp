#include <iostream>
#include <vector>
#include <algorithm>
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

bool isIdentical(Node *r1, Node *r2){

    if(isEmpty(r1) && isEmpty(r2)){
        return true;
    }

    if(isEmpty(r1) || isEmpty(r2)){
        return false;
    }

    if(r1->data != r2->data){
        return false;
    }

    bool leftResult = isIdentical(r1->left,r2->left);
    bool rightResult = isIdentical(r1->right,r2->right);
    return leftResult && rightResult;
}

int main(){
    Node *r1 = createNode(1);
    r1->left = createNode(2);
    r1->right = createNode(3);
    r1->left->left = createNode(4);

    Node *r2 = createNode(1);
    r2->left = createNode(2);
    r2->right = createNode(3);
    r2->left->left = createNode(4);


    if(isIdentical(r1,r2) == true){
        cout<<"Both trees are identical"<<endl;
    }else{
        cout<<"Both trees are not identical"<<endl;
    }
    
    return 0;
}