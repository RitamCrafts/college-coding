#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct stack {

    int top;

    int arr[MAX_SIZE];

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

void push(struct stack *s, int val) {

    if (isFull(s)) {

        printf("Stack Overflow.\n");

        return;

    }

    s->top++;

    s->arr[s->top] = val;

}

int pop(struct stack *s) {

    if (isEmpty(s)) {

        printf("Stack Underflow.\n");

        return -1;

    }

    int poppedElement = s->arr[s->top];

    s->top--;

    return poppedElement;

}

int evaluatePostfix(char *exp) {

    struct stack *s = malloc(sizeof(struct stack));

    init(s);

    for (int i = 0; exp[i] != '\0'; i++) {

        // Ignore spaces

        if (exp[i] == ' ') {

            continue;

        }

        // If operand

        if (isdigit(exp[i])) {

            push(s, exp[i] - '0');

        }

        // If operator

        else {

            int operand2 = pop(s);

            int operand1 = pop(s);

            int result;

            switch (exp[i]) {

                case '+':

                    result = operand1 + operand2;

                    break;

                case '-':

                    result = operand1 - operand2;

                    break;

                case '*':

                    result = operand1 * operand2;

                    break;

                case '/':

                    result = operand1 / operand2;

                    break;

                case '^':

                    result = 1;

                    for (int j = 0; j < operand2; j++) {

                        result *= operand1;

                    }

                    break;

                default:

                    printf("Invalid Operator.\n");

                    free(s);

                    return -1;

            }

            push(s, result);

        }

    }

    int finalResult = pop(s);

    free(s);

    return finalResult;

}

int main() {

    char exp[] = "5 6 2 + * 12 4 / -";

    int result = evaluatePostfix(exp);

    printf("Result: %d\n", result);

    return 0;

}