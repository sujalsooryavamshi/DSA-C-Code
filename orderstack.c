#include <stdio.h>
// check order of the stack
#define MAX 10

struct stack {
    int data[MAX];
    int top;
};

void push(struct stack *st, int x);
int pop(struct stack *st);
int checkorder(struct stack stk);
int isempty(struct stack *s);
void display(struct stack stk);
int peek(struct stack st);

int main(void) {
    struct stack stk;
    stk.top = -1;

    push(&stk, 6);
    push(&stk, 7);
    push(&stk, 8);
    push(&stk, 9);
    push(&stk, 10);

    int value = checkorder(stk);

    if (value == 2) {
        printf("It is in ascending order\n");
    } else if (value == 3) {
        printf("It is in descending order\n");
    } else {
        printf("It is not in ascending or descending order\n");
    }

    return 0;
}

void push(struct stack *st, int x) {
    if (st->top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        st->data[++st->top] = x;
    }
}

int pop(struct stack *st) {
    if (st->top == -1) {
        printf("Stack underflow\n");
        return -1; // Return a special value indicating underflow
    } else {
        return st->data[st->top--];
    }
}

int checkorder(struct stack stk) {
    int ascending = 1, descending = 1;

    if (stk.top == -1) {
        printf("Stack is empty\n");
        return 0; // Return 0 to indicate the stack is empty
    } else {
        while(!isempty(&stk)) {
            int x = pop(&stk);
            
            if (!isempty(&stk) && x > peek(stk)) {
                ascending = 0;
            }
            
            if (!isempty(&stk) && x < peek(stk)) {
                descending = 0;
            }
        }

        if (ascending) {
            return 2; 
        } else if (descending) {
            return 3;
        } else {
            return 4; 
        }
    }
}

int isempty(struct stack *s) {
    return s->top == -1;
}

void display(struct stack stk) {
    if (stk.top == -1) {
        printf("The stack is empty\n");
    } else {
        printf("The elements of the stack are:\n");
        for (int i = 0; i <= stk.top; ++i) {
            printf("%d\n", stk.data[i]);
        }
    }
}

int peek(struct stack st) {
    if (st.top == -1) {
        printf("No elements to peek\n");
        return -1; 
    } else {
        return st.data[st.top];
    }
}
