// reverse a word
#include<stdio.h>
#include<string.h>
#define size 50

char stack[size];
int top = -1;

char pop() {
    if (top == -1) {
        printf("underflow\n");
        return '\0'; // Return null character to indicate underflow
    } else {
        return stack[top--];
    }
}

void push(char x) {
    if (top >= size - 1) {
        printf("overflow\n");
    } else {
        stack[++top] = x;
    }
}

void reverse(char str[]) {
    int wordStart = 0;
    for (int i = 0; i <= strlen(str); i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            for (int j = wordStart; j < i; j++) {
                push(str[j]);
            }
            while (top != -1) {
                char ch = pop();
                printf("%c", ch);
            }
            if (str[i] == ' ') {
                printf(" "); // Print space between words
            }
            wordStart = i + 1; // Update the start index for the next word
        }
    }
}

int main() {
    char str[50];
    printf("Enter the string\n");
    gets(str);
    reverse(str);
    return 0;
}