
#include <stdio.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char ch) {
    if (top == MAX_SIZE-1)
        return;
    stack[++top] = ch;
}

char pop() {
    if (top == -1)
        return '\0';
    return stack[top--];
}

int main() {
    char str[MAX_SIZE];
    int i;

    printf("Enter a string: ");
    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++)
        push(str[i]);

    printf("Reversed string: ");
    while (top != -1)
        printf("%c", pop());

    return 0;
}

/*
Enter a string: HELLO
Reversed string: OLLEH
*/
