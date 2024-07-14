#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 100

char stack[max];
char pri[max];
int top = -1;
char in[max];

void intopri(char in[]);
int isspaces(char c);
int isempty();
void push(char symbol);
char pop();
int precedence(char symbol);
void print();

int main() {
    printf("Enter the infix expression: ");
    scanf("%s", in);
    intopri(in);
    print();
    return 0;
}

void intopri(char in[]) {
    char symbol, new;
    int i, l = strlen(in), j = 0;
    for (i = l - 1; i >= 0; --i) {
        symbol = in[i];
        if (!isspaces(symbol)) {
            switch (symbol) {
                case '(':
                    push(symbol);
                    break;
                case ')':
                    while ((new = pop()) != '(')
                        pri[j] = new;
                    ++j;
                    break;
                case '+':
                case '-':
                case '^':
                case '/':
                case '*':
                    while (!isempty() && precedence(stack[top]) >= precedence(symbol)) {
                        pri[j] = pop();
                        ++j;
                    }
                    push(symbol);
                    break;
                default:
                    pri[j] = symbol;
                    ++j;
                    break;
            }
        }
    }
    while (!isempty()) {
        pri[j] = pop();
        ++j;
    }
    pri[j] = '\0';
}

int isspaces(char c) {
    if (c == ' ' || c == '\t')
        return 1;
    else
        return 0;
}

int isempty() {
    if (top == -1)
        return 1;
    else
        return 0;
}

void push(char symbol) {
    if (top == max - 1)
        printf("Overflow condition\n");
    else {
        ++top;
        stack[top] = symbol;
    }
}

char pop() {
    char c;
    if (top == -1) {
        printf("Underflow condition\n");
        exit(1);
    } else {
        c = stack[top];
        top--;
        return c;
    }
}

int precedence(char symbol) {
    switch (symbol) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

void print()
{ int i,l;
    l=strlen(pri);
    for(i=l-1;i>=0;--i)
    {
      printf("%c",pri[i]);
    }
}