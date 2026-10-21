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

void preOrderArray(Node *root,vector<string>&nodes){
    if(isEmpty(root)){
        nodes.push_back("NULL");
        return;
    }

    nodes.push_back(to_string(root->data));
    preOrderArray(root->left,nodes);
    preOrderArray(root->right,nodes);
}

bool isSubTree(Node *root1, Node *root2){
    if (isEmpty(root2)) return true;
    if (isEmpty(root1)) return false;

    vector<string>nodes1;
    vector<string>nodes2;
    preOrderArray(root1,nodes1);
    preOrderArray(root2,nodes2);

    vector<vector<string>>subArrays;
    for(int i = 0; i<nodes1.size(); i++){
        vector<string>subArray;
        for(int j = i; j<nodes1.size(); j++){
            subArray.push_back(nodes1[j]);
            subArrays.push_back(subArray);
        }
    }

    for(int i = 0; i<subArrays.size(); i++){
        if(subArrays[i] == nodes2){
            return true;
        }
    }

    return false;
}

bool isIdentical(Node *root1, Node *root2){
    if(isEmpty(root1) && isEmpty(root2)){
        return true;
    }

    if(isEmpty(root1) || isEmpty(root2)){
        return false;
    }

    if(root1->data != root2->data){
        return false;
    }

    bool leftResult = isIdentical(root1->left,root2->left);
    bool rightResult = isIdentical(root1->right,root2->right);

    return leftResult && rightResult;
}

// better approach
bool isSubTreeBetter(Node *root1,Node *root2){
    if(isEmpty(root2)) return true;
    if(isEmpty(root1)) return false;

    if(isIdentical(root1,root2)){
        return true;
    }

    return isIdentical(root1->left,root2) || isIdentical(root1->right,root2);
}

int main(){
    Node* root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);

    root1->left->left = nullptr;
    root1->left->right = nullptr;

    root1->right->left = createNode(4);
    root1->right->right = nullptr;

    Node* root2 = createNode(3);
    root2->left = createNode(4);
    root2->right = nullptr;

    if(isSubTreeBetter(root1,root2) == true){
        cout<<"Tree 2 is a subtree of Tree 1"<<endl;
    }else{
        cout<<"Tree 2 is not a subtree of Tree 1"<<endl;
    }
    return 0;
}