#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

struct stack {
    int top;
    char *arr[MAX_SIZE];
};

void initialise(struct stack *s){
    s->top = -1;
}

bool isEmpty(struct stack *s){
    return s->top == -1;
}

bool isFull(struct stack *s){
    return s->top == MAX_SIZE-1;
}

void push(struct stack *s,char *val){
    if(isFull(s)) {
        printf("Stack Overflow.\n");
        return;
    }

    s->top++;
    s->arr[s->top] = val;
}

char *pop(struct stack *s){
    if(isEmpty(s)){
        printf("Stack Underflow.\n");
        return NULL;
    }

    char *poppedElement = s->arr[s->top];
    s->top--;
    return poppedElement;
}

void reverseString(char* s) {
    struct stack *st = malloc(sizeof(struct stack));
    initialise(st);

    char result[MAX_SIZE] = {};
    int j = 0;
    char *words = strtok(s," ");
    while(words != NULL){
        push(st,words);
        words = strtok(NULL," ");
    }

    while(!isEmpty(st)){
        char *word = pop(st);

        for(int i = 0; word[i] != '\0'; i++){
            result[j++] = word[i];
        }

        if(!isEmpty(st)){
            result[j++] = ' ';
        }
    }
    result[j] = '\0';
    free(st);
    for(int i = 0;result[i] != '\0'; i++){
        printf("%c",result[i]);
    }
}


int main(){
    char string[MAX_SIZE] = "Welcome to the jungle";
    reverseString(string);
    return 0;
}