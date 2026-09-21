#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    char *arr[MAX_SIZE];
};

void init(struct Stack *s){
    s->top = -1;
}

bool isFull(struct Stack *s){
    return s->top == MAX_SIZE-1;
}

bool isEmpty(struct Stack *s){
    return s->top == -1;
}

void push(struct Stack *s,char *val){
    if(isFull(s)){
        printf("Stack Overflow.\n");
        return;
    }

    s->top++;
    s->arr[s->top] = val;
}

char *pop(struct Stack *s){
    if(isEmpty(s)){
        printf("Stack Underflow.\n");
        return NULL;
    }
    char *poppedElement = s->arr[s->top];
    s->top--;
    return poppedElement;
}

char **getWords(char *str){
    char **words = malloc(MAX_SIZE*sizeof(char *));
    int j = 0;
    for(int i = 0; str[i] != '\0'; i++){
        if(i == 0 || str[i-1] == ' '){
            words[j++] = &str[i];
        }
    }

    return words;
}

int getCount(char *str){
    int count = 0;
    for(int i = 0; str[i] != '\0'; i++){
        if(i == 0 || str[i-1] == ' '){
            count++;
        }
    }

    return count;
}
char *reverseWords(char *str){
    struct Stack *s = malloc(sizeof(struct Stack));
    init(s);
    char **words = getWords(str);
    int size = getCount(str);

    for(int i = 0; i<size; i++){
        push(s,words[i]);
    }
    char *reverseText = malloc(MAX_SIZE*sizeof(char));
    int j = 0;
    for(int i = s->top; i>=0; i--){
        reverseText[j++] = *s->arr[i];
    }
    reverseText[j] = '\0';

    return reverseText;
    
}



int main(){
    
    return 0;
}