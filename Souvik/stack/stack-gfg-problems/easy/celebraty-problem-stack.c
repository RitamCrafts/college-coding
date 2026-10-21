#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 3

struct stack {
    int val;
    struct stack *next;
};

bool isEmpty(struct stack *s){
    return s == NULL;
}

struct stack *createNode(int val){
    struct stack *newNode = (struct stack *)malloc(sizeof(struct stack));
    newNode->val = val;
    newNode->next = NULL;

    return newNode;
}

struct stack *push(struct stack *top, int val){
    struct stack *newNode = createNode(val);
    newNode->next = top;
    top = newNode;

    return top;
}

int pop(struct stack *top){
    if(isEmpty(top)){
        printf("Stack Underflow.\n");
        return -1;
    }

    struct stack *temp = top;
    int popped = top->val;
    top = top->next;
    free(temp);

    return popped;
}

int peek(struct stack *top){
    if(isEmpty(top)){
        printf("Stack Underflow.\n");
        return -1;
    }

    int topValue = top->val;
    return topValue;
}

bool checkKnowing(int arr[MAX_SIZE][MAX_SIZE], int c){

    for(int i = 0; i < MAX_SIZE; i++){

        if(i == c)
            continue;

        if(arr[c][i] != 0 || arr[i][c] != 1){
            return false;
        }
    }

    return true;
}

int elementCount(struct stack *s){

    if(isEmpty(s)){
        return 0;
    }

    int count = 0;

    struct stack *temp = s;

    while(temp != NULL){
        count++;
        temp = temp->next;
    }

    return count;
}




int main(){
    struct stack *s = NULL;
    

    printf("Element Count: %d \n",elementCount(s));
    return 0;

}