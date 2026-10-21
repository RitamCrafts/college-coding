#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ListNode{
    public:
        int val;
        ListNode *next;
    ListNode(int data){
        val = data;
        next = NULL;
    }
};

bool isEmpty(ListNode *head){
    return head == NULL;
}

ListNode *insertEnd(ListNode *head, int val){
    ListNode *newNode = new ListNode(val);
    if(isEmpty(head)) return newNode;

    ListNode *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

void reOrderList(ListNode * &head){
        if(isEmpty(head) || isEmpty(head->next)) return;
        vector<int>nodes;
        ListNode *temp = head;

        while(temp != NULL){
            nodes.push_back(temp->val);
            temp = temp->next;
        }

        int low = 0;
        int high = nodes.size()-1;
        vector<int>result;
        while(low<=high){
            result.push_back(nodes[low]);
            if(low != high){
                result.push_back(nodes[high]);
            }
            low++;
            high--;
        }
        ListNode *newHead = NULL;
        for(int i:result){
            newHead = insertEnd(newHead,i);
        }

        head = newHead;

       
}

int main(){
    ListNode *head = new ListNode(2);
    head = insertEnd(head,4);
    head = insertEnd(head,6);
    head = insertEnd(head,8);

    ListNode *temp = head;
    while(temp != NULL){
        cout<< temp->val<< " ";
        if(temp->next != NULL){
            cout<< "-> ";
        }
        temp = temp->next;
    }

    cout<<endl;
    reOrderList(head);
    cout<<endl;
    return 0;
}