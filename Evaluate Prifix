#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>
#define SIZE 100
struct Stack {
    int top;
    int data[SIZE];
};
// Push an element onto the stack
void push(struct Stack *stack, int value) {
    if (stack->top >= SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack->data[++stack->top] = value;
}
// Pop an element from the stack
int pop(struct Stack* stack) {
    if (stack->top==-1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->data[stack->top--];
}
// Function to evaluate a prefix expression
int evaluatePrefix(char* expression) {
    struct Stack stack;
    stack.top=-1;
    int length = strlen(expression);
    for (int i = length - 1; i >= 0; i--) {
        if (isdigit(expression[i]) ) {
            push(&stack, expression[i] - '0');
        } else if (expression[i] == ' ' || expression[i] == '\t') {
            // Ignore whitespace
            continue;
        } else {
            int operand1 = pop(&stack);
            int operand2 = pop(&stack);
            switch (expression[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator: %c\n", expression[i]);
                    exit(1);
            }
        }
    }
    return pop(&stack);
}

int main() {
    char expression[SIZE];

    printf("Enter a prefix expression: ");
    scanf("%s",expression);
    int result = evaluatePrefix(expression);

    printf("Result: %d\n", result);

    return 0;
}
