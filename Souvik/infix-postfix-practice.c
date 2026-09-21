#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct stack {
    int top;
    char arr[MAX_SIZE];
};

void init(struct stack *s) {
    s->top = -1;
}

bool isFull(struct stack *s) {
    return s->top == MAX_SIZE - 1;
}

bool isEmpty(struct stack *s) {
    return s->top == -1;
}

void push(struct stack *s, char val) {

    if (isFull(s)) {
        printf("Stack Overflow.\n");
        return;
    }

    s->top++;
    s->arr[s->top] = val;
}

char pop(struct stack *s) {

    if (isEmpty(s)) {
        printf("Stack Underflow.\n");
        return '\0';
    }

    char poppedElement = s->arr[s->top];

    s->top--;

    return poppedElement;
}

char peek(struct stack *s) {

    if (isEmpty(s)) {
        return '\0';
    }

    return s->arr[s->top];
}

int checkPrecedence(char c) {

    if (c == '^') {
        return 3;
    }
    else if (c == '/' || c == '*') {
        return 2;
    }
    else if (c == '+' || c == '-') {
        return 1;
    }
    else {
        return -1;
    }
}

bool checkRightAssociative(char c) {
    return c == '^';
}

void infixToPostFix(char *arr) {

    struct stack *s = malloc(sizeof(struct stack));

    init(s);

    int j = 0;
    char result[MAX_SIZE];

    for (int i = 0; arr[i] != '\0'; i++) {

        if (isalnum(arr[i])) {

            result[j++] = arr[i];

        }

        else if (arr[i] == '(') {

            push(s, arr[i]);

        }

        else if (arr[i] == ')') {

            while (!isEmpty(s) && peek(s) != '(') {

                char poppedElement = pop(s);

                result[j++] = poppedElement;
            }

            if (!isEmpty(s) && peek(s) == '(') {
                pop(s);
            }
        }


        else {

            while (
                !isEmpty(s) &&
                peek(s) != '(' &&
                (
                    checkPrecedence(peek(s)) > checkPrecedence(arr[i])
                    ||
                    (
                        checkPrecedence(peek(s)) ==
                        checkPrecedence(arr[i])
                        &&
                        !checkRightAssociative(arr[i])
                    )
                )
            ) {

                char poppedElement = pop(s);

                result[j++] = poppedElement;
            }

            push(s, arr[i]);
        }
    }

    // Pop remaining operators
    while (!isEmpty(s)) {

        char poppedElement = pop(s);

        result[j++] = poppedElement;
    }

    result[j] = '\0';

    printf("Postfix Expression: %s\n", result);

    free(s);
}

int main() {

    char exp[] = "A+B+C-D*4";

    infixToPostFix(exp);

    return 0;
}