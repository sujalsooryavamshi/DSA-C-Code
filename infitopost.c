#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 100

char stack[max];
char post[max];
int top = -1;
char in[max];

void intopost(char in[]);
int isspaces(char c);
int isempty();
void push(char symbol);
char pop();
int precedence(char symbol);
void print();

int main() {
    printf("Enter the infix expression: ");
    scanf("%s", in);
    intopost(in);
    print();
    return 0;
}

void intopost(char in[]) {
    char symbol, new;
    int i, l = strlen(in), j = 0;
    for (i =0; i <=l-1; ++i) {
        symbol = in[i];
        if (!isspaces(symbol)) {
            switch (symbol) {
                case '(':
                    push(symbol);
                    break;
                case ')':
                    while ((new = pop()) != '(')
                        post[j] = new;
                    ++j;
                    break;
                case '+':
                case '-':
                case '^':
                case '/':
                case '*':
                    while (!isempty() && precedence(stack[top]) >= precedence(symbol)) {
                        post[j] = pop();
                        ++j;
                    }
                    push(symbol);
                    break;
                default:
                    post[j] = symbol;
                    ++j;
                    break;
            }
        }
    }
    while (!isempty()) {
        post[j] = pop();
        ++j;
    }
    post[j] = '\0';
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
            return 4;
        case '*':
        case '/':
            return 3;
        case '+':
        case '-':
            return 2;
    
        default:
            return 0;
    }
}

void print()
{ int i,l;
    l=strlen(post);
    printf("The postfix expression is as follows :\n");
    for(i=0;i<=l-1;++i)
    {
      printf("%c",post[i]);
    }
}