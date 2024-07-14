#include <stdio.h>

#define MAX 25

struct queue {
    int data[MAX];
    int top;
    int cnt;
};

struct queue stk1, stk2, temp;
struct queue *tem = &temp;

void enque(int x);
int deque();
void push(struct queue *sp, int d);
int pop(struct queue *sp);
void display();

int main() {
    enque(10);
    enque(20);
    enque(30);

    int da = deque();
    printf("%d\n", da);

    int dc = deque();
    printf("%d\n", dc);

    int dd = deque();
    printf("%d\n", dd);

    int th = deque();
    printf("%d\n", th);

    display();

    return 0;
}

void enque(int x) {
    push(&stk1, x);
    ++(tem->cnt);
}

int deque() {
    int i;
    for (i = 0; i < tem->cnt; ++i) {
        int a = pop(&stk1);
        push(&stk2, a);
    }
    int b = pop(&stk2);
    --(tem->cnt);
    for (i = 0; i < tem->cnt; ++i) {
        int c = pop(&stk2);
        push(&stk1, c);
    }
    return (b);
}

void push(struct queue *sp, int d) {
    if (sp->top == MAX - 1) {
        printf("Full\n");
    } else {
        sp->top++;
        sp->data[sp->top] = d;
        sp->cnt++;  // Increment the count when pushing
    }
}

int pop(struct queue *sp) {
    int x = -1;  // Default value if the stack is empty
    if (sp->top == -1) {
        printf("Empty\n");
    } else {
        x = sp->data[sp->top];
        sp->top--;
        sp->cnt--;  // Decrement the count when popping
    }
    return x;
}

void display() {
    for (int i = 0; i < stk1.cnt; ++i)
        printf("%d\t", stk1.data[i]);
    printf("\n");
}
