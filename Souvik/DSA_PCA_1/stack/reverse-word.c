#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    char arr[MAX_SIZE];
};

bool isEmpty(struct Stack *s){
    return s->top == -1;
}

bool isFull(struct Stack *s){
    return s->top == MAX_SIZE-1;
}

void init(struct Stack *s){
    s->top = -1;
}

void push(struct Stack *s, char val){
    if(isFull(s)){
        printf("Stack Overflow.\n");
        return;
    }
    s->top++;
    s->arr[s->top] = val;
}

char pop(struct Stack *s){
    if(isEmpty(s)){
        printf("Stack Underflow.\n");
        return -1;
    }

    char poppedElement = s->arr[s->top];
    s->top--;
    return poppedElement;
}

void reverseWord(struct Stack *s, char string[]) {
    for (int i = 0; string[i] != '\0'; i++)
        push(s, string[i]);

    char result[MAX_SIZE];
    int j = 0;
    while (!isEmpty(s))
        result[j++] = pop(s);
    result[j] = '\0';

    printf("%s\n", result);
}


int main() {
    char str[MAX_SIZE];
    printf("Enter a word: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  

    struct Stack *s = malloc(sizeof(struct Stack));
    init(s);
    printf("Reversed Word: \n");
    reverseWord(s, str);
    free(s);
    return 0;
}