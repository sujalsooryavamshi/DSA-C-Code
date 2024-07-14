#include <stdio.h>
#include <stdlib.h>

#define max 50

int top = -1;
int stack[max];

void immediatenextsmall(int arr[], int n);
void push(int symbol);
int pop();

int main() {
    int arr[max];
    int n, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    
    immediatenextsmall(arr, n);
    return 0;
}

void immediatenextsmall(int arr[], int n) {
    int i,s=arr[0];
    push(s);
    for (i = 1; i < n; ++i) {
        int next = arr[i];
        int current;

        while (top != -1) {
            current = pop();
            if (current > next) {
                printf("%d\t", next);
                push(next);
                break;
            }
        }

        if (top == -1) {
            printf("-1\t");
            push(next);
        }
    }
    printf("-1");
    
}

void push(int symbol) {
    if (top == max - 1) {
        printf("Stack overflow condition\n");
        exit(1);
    } else {
        ++top;
        stack[top] = symbol;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack underflow condition\n");
        exit(1);
    } else {
        int c = stack[top];
        --top;
        return c;
    }
}
