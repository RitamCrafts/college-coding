//23. Merge k Sorted Lists
struct ListNode {
     int val;
     struct ListNode *next;
 };
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode *ptr1 = list1;
    struct ListNode *ptr2 = list2;
    struct ListNode *mergedListHead = NULL;
    struct ListNode *ptrMerge = mergedListHead;
    if(ptr1==NULL){
        while(ptr2!=NULL){
            int val2=ptr2->val;
             
            //insert node end
            struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
            newNode->next=NULL;
            newNode->val=val2;
            if(ptrMerge==NULL){
                ptrMerge=newNode;
                mergedListHead=ptrMerge;
            }
            else{
                ptrMerge->next=newNode;
                ptrMerge=ptrMerge->next;
            }
            ptr2=ptr2->next;
        }
    }
    while(ptr1!=NULL){
        int val1=ptr1->val;
        while(ptr2!=NULL){
            int val2=ptr2->val;
            if(val2>val1) break;
             
            //insert node end
            struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
            newNode->next=NULL;
            newNode->val=val2;
            if(ptrMerge==NULL){
                ptrMerge=newNode;
                mergedListHead=ptrMerge;
            }
            else{
                ptrMerge->next=newNode;
                ptrMerge=ptrMerge->next;
            }
            ptr2=ptr2->next;
        }
        //insert node end(should have made a function)
        struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->next=NULL;
        newNode->val=val1;
        if(ptrMerge==NULL){
            ptrMerge=newNode;
            mergedListHead=ptrMerge;
        }
        else{
            ptrMerge->next=newNode;
            ptrMerge=ptrMerge->next;
        }
        ptr1=ptr1->next;
    }
    while(ptr2!=NULL){
        int val2=ptr2->val;
            
        //insert node
        struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->next=NULL;
        newNode->val=val2;
        if(ptrMerge==NULL){
            ptrMerge=newNode;
            mergedListHead=ptrMerge;
        }
        else{
            ptrMerge->next=newNode;
            ptrMerge=ptrMerge->next;
        }
        ptr2=ptr2->next;
    }
    return mergedListHead;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if(listsSize==0) return NULL;
    while(listsSize>1){
        int newSize=0;//idt this will ever overlap with i as at start after meerge i += 2 but it just ++ so it is overwrite pos 1 and i is using pos 2 and 3 after 01 and then i is usin 4 and 5 and it is 2 and then it cant catch up
        int i = 0;
        for(i=0;i<listsSize;i+=2){
            if(i+1 < listsSize){
                lists[newSize] = mergeTwoLists(lists[i], lists[i + 1]);
            }
            else{
                lists[newSize] = lists[i];
            }
            newSize++;
        }
        listsSize = newSize;
    }

    return lists[0];
}