
#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

int priority(char ch) {
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    return 0;
}

int main() {
    char infix[MAX_SIZE], ch;
    int i;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    printf("Postfix expression: ");

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (isalnum(ch))
            printf("%c", ch);

        else if (ch == '(')
            push(ch);

        else if (ch == ')') {
            while (top != -1 && stack[top] != '(')
                printf("%c", pop());
            pop();
        }

        else {
            while (top != -1 && stack[top] != '(' &&
                  (priority(stack[top]) > priority(ch) ||
                  (priority(stack[top]) == priority(ch) && ch != '^')))
                printf("%c", pop());

            push(ch);
        }
    }

    while (top != -1)
        printf("%c", pop());

    return 0;
}

/*
Enter infix expression: (A+B)*C-D/E
Postfix expression: AB+C*DE/-
*/