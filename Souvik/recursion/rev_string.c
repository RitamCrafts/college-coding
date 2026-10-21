#include <stdio.h>

void reverse_string(char c[], int left, int right) {
    if(left >= right) {
        return;
    }

    char temp = c[left];
    c[left] = c[right];
    c[right] = temp;

    reverse_string(c, left + 1, right - 1);
}

int main() {
    char c[] = {'S','E','U','V','I','K','\0'};

    reverse_string(c, 0, 5);

    printf("%s", c);

    return 0;
}